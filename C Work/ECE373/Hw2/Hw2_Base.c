//Ryan W. Writz (c) 2020
//ECE 373 Hw 2
//Base of Example 5 (Giving/getting stuff from the driver)
//Modified to meet hw needs 

//How to use this module:
//In terminal type the following:
//make (will show kernel building)
//sudo insmod Hw2.ko (loads kernel)
//sudo mknod location(/dev/ece) drivertype(c) major# minor#
//sudo rmmod Hw2 (removes the kernel)
//make clean (cleans up build of kernel)

#include <linux/module.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/slab.h>
#include <linux/uaccess.h>

#define DEVCNT 1
#define DEVNAME "Hw2"

int CharToInt;

static struct mydev_dev {
	struct cdev my_cdev;
	/* more stuff will go in here later... */
	int sys_int;
	int syscall_val;
} mydev;

static dev_t mydev_node;

/* this shows up under /sys/modules/example5/parameters */
static int exam = 15;
module_param(exam, int, S_IRUSR | S_IWUSR);


/* this doesn't appear in /sys/modules */
static int exam_nosysfs = 25;
module_param(exam_nosysfs, int, 0);

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

	printk("And now we're reading with copy_to_user");

	if (*offset >=  sizeof(u32))	//Full 32 bytes
		return 0;

	/* Make sure our user wasn't bad... */
	if (!buf) {
		ret = -EINVAL;	//Results in "Interrupted function call"
		goto out;
	}

	if (copy_to_user(buf, &mydev.syscall_val, sizeof(u32))) {
		ret = -EFAULT;	//Results in "Bad address"
		goto out;
	}
	ret = sizeof(u32);
	*offset += sizeof(u32);

	/* Good to go, so printk the thingy */
	printk(KERN_INFO "User got from us %d\n", mydev.syscall_val);

out:
	return ret;
}

static ssize_t example5_write(struct file *file, const char __user *buf,
                              size_t len, loff_t *offset)
{
	/* Have local kernel memory ready */
	int *kern_buf;
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

	//CharToInt = kstrtoint(buf,0,&mydev.syscall_val);
	mydev.syscall_val = *kern_buf;
	ret = len;

	/* print what userspace gave us */
	//printk(KERN_INFO "Userspace wrote \"%s\" to us\n", kern_buf);
	printk(KERN_INFO "Userspace wrote \"%d\" to us\n", &mydev.syscall_val);


mem_out:
	kfree(kern_buf);
out:
	return ret;
}

/* File operations for our device */
static struct file_operations mydev_fops = {
	.owner = THIS_MODULE,
	.open = example5_open,
	.read = example5_read,
	.write = example5_write,
};

static int __init Hw2_init(void)
{
	mydev.syscall_val = 40;

	printk(KERN_INFO "Hw2 module loading... exam=%d, exam_nosysfs: %d\n", exam, exam_nosysfs);

	if (alloc_chrdev_region(&mydev_node, 0, DEVCNT, DEVNAME)) {
		printk(KERN_ERR "alloc_chrdev_region() failed!\n");
		return -1;
	}

	printk(KERN_INFO "Allocated %d devices at major: %d\n", DEVCNT,
	       MAJOR(mydev_node));

	/* Initialize the character device and add it to the kernel */
	cdev_init(&mydev.my_cdev, &mydev_fops);
	mydev.my_cdev.owner = THIS_MODULE;

	if (cdev_add(&mydev.my_cdev, mydev_node, DEVCNT)) {
		printk(KERN_ERR "cdev_add() failed!\n");
		/* clean up chrdev allocation */
		unregister_chrdev_region(mydev_node, DEVCNT);

		return -1;
	}

	return 0;
}

static void __exit Hw2_exit(void)
{
	/* destroy the cdev */
	cdev_del(&mydev.my_cdev);

	/* clean up the devices */
	unregister_chrdev_region(mydev_node, DEVCNT);

	printk(KERN_INFO "Hw2 module unloaded!\n");
}

MODULE_AUTHOR("Ryan W. Writz");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.2");
module_init(Hw2_init);
module_exit(Hw2_exit);
