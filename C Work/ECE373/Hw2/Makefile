KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += Hw2_Parameter.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

load:
	sudo insmod Hw2_Parameter.ko
	dmesg

unload:
	sudo rmmod Hw2_Parameter 

CProg: SyscallRW.c
	gcc -g -o Sys SyscallRW.c
	sudo ./Sys

cleanc: SyscallRW.c
	rm Sys
