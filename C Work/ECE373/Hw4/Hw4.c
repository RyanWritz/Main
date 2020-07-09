//Ryan W. Writz (c) 2020
//ECE 373 Hw 4
//Base of Example 5 --> Hw 2 --> Hw 3 --> Hw 4
//E1000 code snippets based off code at 
//LXR /linux/latest/source/drivers/net/ethernet/intel/e1000e/netdev.c

//How to use this module:
//In terminal type the following:
//make (will show kernel building)
//Use lspci -nn to find e1000e ethernet controller we are working with 
//echo 0000:00:03.0 > /sys/module/e1000/drivers/pci:e1000/unbind (unbind device from e1000e driver) 
//sudo insmod Hw3.ko (loads kernel)
//sudo mknod location(/dev/ece) drivertype(c) major# minor#
//sudo rmmod Hw3 (removes the kernel)
//make clean (cleans up build of kernel)
//echo 0000:00:03.0 > /sys/module/e1000/drivers/pci:e1000/bind (bind device back to e1000e driver) 

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/init.h>
#include <linux/netdevice.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/err.h>

#define DEVCNT 1
#define DEVNAME "Hw3"
#define LEDOFFSET 0xE00

//#define PCI_DEVIDE(PCI_VENDOR_ID_INTEL,device_id)

char e1000e_driver_name[] = "e1000e";

static struct mydev_dev {
	struct cdev my_cdev;
	/* more stuff will go in here later... */
	int sys_int;
	int syscall_val;
	unsigned int  led_inital_value;
	int current_blink_rate;
	struct timer_list my_timer;
	
} mydev;

static struct PCI
{	struct pci_dev *pdev;
	void * hw_addr;
}PCIForUse;

static const struct pci_device_id pci_table[]= {
	{PCI_DEVICE(0x8086,0x100E)},	//Vendor and Device ID for device
	{},
};

static dev_t mydev_node;
struct class *dev_class;

/* this shows up under /sys/modules/example5/parameters */
static int exam = 15;
int sys_t_c = 40;
module_param(exam, int, S_IRUSR | S_IWUSR);
module_param(sys_t_c,int, S_IRUSR | S_IWUSR);


//Sets up blink_rate and blinks-per-second-rate parameters and initialization 
int blink_rate;
int temp_blink_rate;
int blinks_per_second_rate = 2;
module_param(blinks_per_second_rate,int, S_IRUSR | S_IWUSR);

/* this doesn't appear in /sys/modules */
static int exam_nosysfs = 25;
module_param(exam_nosysfs, int, 0);

static void timer_callback(struct timer_list *t)
{
	printk(KERN_INFO "Current blink_rate is %d per second\n", blink_rate);\
}

static int example5_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "successfully opened!\n");

	return 0;
}

static ssize_t example5_read(struct file *file, char __user *buf,
                             size_t len, loff_t *offset)
{	
	/* Get a local kernel buffer set aside */
	int ret;

	printk(KERN_INFO "And now we're reading with copy_to_user\n");

	if (*offset >=  sizeof(u32))	//Full 32 bytes
		return 0;
	printk(KERN_INFO "Read offset set\n");

	/* Make sure our user wasn't bad... */
	if (!buf) {
		ret = -EINVAL;	//Results in "Interrupted function call"
		goto out;
	}

	printk(KERN_INFO "User wasn't bad\n");

	mydev.syscall_val = readl(PCIForUse.hw_addr + LEDOFFSET);
		
	printk(KERN_INFO "Readl was good, at %p + LEDOFFSET\n",PCIForUse.hw_addr);
	printk(KERN_INFO "%x\n", mydev.syscall_val);

	if (copy_to_user(buf, &mydev.syscall_val, sizeof(u32))) {
		ret = -EFAULT;	//Results in "Bad address"
		goto out;
	}
	ret = sizeof(u32);
	*offset += sizeof(u32);

	/* Good to go, so printk the thingy */
	printk(KERN_INFO "User got %u from us\n", mydev.syscall_val);

out:
	return ret;
}

static ssize_t example5_write(struct file *file, const char __user *buf,
                              size_t len, loff_t *offset)
{
	/* Have local kernel memory ready */
	uint32_t *kern_buf;
	int ret;


	printk("And now we're writing with copy_from_user");

	/* Make sure our user isn't bad... */
	if (!buf) {
		ret = -EINVAL;	//Results in "Interrupted function call"
		goto out;
	}

	/* Get some memory to copy into... */
	kern_buf = kmalloc(len, GFP_KERNEL);

	/* ...and make sure it's good to go */
	if (!kern_buf) {
		ret = -ENOMEM;	//Results in "Not enough space/cannot allocate memory
		goto out;
	}

	/* Copy from the user-provided buffer */
	if (copy_from_user(kern_buf, buf, len)) {
		/* uh-oh... */
		ret = -EFAULT;
		goto mem_out;
	}

	mydev.syscall_val = *kern_buf;
	ret = len;
	writel(mydev.syscall_val,PCIForUse.hw_addr + LEDOFFSET);

	/* print what userspace gave us */
	//printk(KERN_INFO "Userspace wrote \"%s\" to us\n", kern_buf);
	//printk(KERN_INFO "Userspace wrote %u to us\n", &mydev.syscall_val);
	printk(KERN_INFO "Userspace wrote %u to us\n", *kern_buf);

mem_out:
	kfree(kern_buf);
out:
	return ret;
}

static void pci_remove(struct pci_dev *pdev)
{
	//struct net_device *netdev = pci_get_drvdata(pdev);

	printk(KERN_INFO "Enacting pci_remove function\n");
	iounmap(PCIForUse.hw_addr);
	pci_release_selected_regions(pdev,pci_select_bars(pdev,IORESOURCE_MEM));

}

/* File operations for our device */
static struct file_operations mydev_fops = {
	.owner = THIS_MODULE,
	.open = example5_open,
	.read = example5_read,
	.write = example5_write,
};


static int pci_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{	//struct net_device *netdev;
	int bars,err;
	resource_size_t mmio_start, mmio_len;

	printk(KERN_INFO "Enacting pci_probe function\n");
	
	mydev.syscall_val = 40;

	printk(KERN_INFO "Hw3 module loading... exam=%d, exam_nosysfs: %d\n", exam, exam_nosysfs);

	if(blink_rate > 0)
	{	blink_rate = temp_blink_rate;
	}else		//blink_rate <= 0
	{	return -1;
	}
	timer_setup(&mydev.my_timer,timer_callback,0);
	mod_timer(&mydev.my_timer, jiffies + msecs_to_jiffies((1000/(2*blink_rate))));	

	if (alloc_chrdev_region(&mydev_node, 0, DEVCNT, DEVNAME)) {
		printk(KERN_ERR "alloc_chrdev_region() failed!\n");
		return -1;
	}

	printk(KERN_INFO "Allocated %d devices at major: %d\n", DEVCNT,
	       MAJOR(mydev_node));

	/* Initialize the character device and add it to the kernel */
	cdev_init(&mydev.my_cdev,&mydev_fops);
	mydev.my_cdev.owner = THIS_MODULE;

	if (cdev_add(&mydev.my_cdev, mydev_node, DEVCNT)) {
		printk(KERN_ERR "cdev_add() failed!\n");
	/* clean up chrdev allocation */
	unregister_chrdev_region(mydev_node, DEVCNT);

		return -1;
	}



	//Allows access to the BAR
	err = pci_enable_device_mem(pdev);
	if(err)
		return err;
	
	//Look at the BAR	
	bars = pci_select_bars(pdev,IORESOURCE_MEM);	

	//Prevents BARS from memory mapping BARs
	err = pci_request_selected_regions_exclusive(pdev,bars,e1000e_driver_name);	    
	//pci_set_drvdata(pdev,netdev);

	pci_set_master(pdev);
	
	//Gives starting Address and length to continue it 
	mmio_start = pci_resource_start(pdev,0);
	mmio_len  = pci_resource_len(pdev,0);

	if(!(PCIForUse.hw_addr = ioremap(mmio_start, mmio_len)))
		printk(KERN_INFO "Ioremap failed\n");

	mydev.led_inital_value = readl(PCIForUse.hw_addr + LEDOFFSET);
	printk(KERN_INFO "Initial value of LED is %x\n",mydev.led_inital_value);

	return 0;
}

static struct pci_driver e1000_driver ={
	.name = e1000e_driver_name,
	.id_table  = pci_table,
	.probe = pci_probe,
	.remove = pci_remove,
};

static int __init Hw3_init(void)
{
	pr_info("ECE 373 Custom E1000e Driver\n");
	pr_info("Copyright(c) 2020 Ryan Writz\n");
	
	if ((pci_register_driver(&e1000_driver)))
	{
		printk(KERN_INFO "Pci device not registered\n");
	}
	
	return 0;	
}

static void __exit Hw3_exit(void)
{
	pci_unregister_driver(&e1000_driver);
	
	/* destroy the cdev */
	cdev_del(&mydev.my_cdev);

	/* clean up the devices */
	unregister_chrdev_region(mydev_node, DEVCNT);

	printk(KERN_INFO "Hw3 module unloaded!\n");
}

MODULE_AUTHOR("Ryan W. Writz");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.4");
module_init(Hw3_init);
module_exit(Hw3_exit);
