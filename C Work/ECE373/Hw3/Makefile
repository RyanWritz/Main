KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += Hw3.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

load:
	sudo insmod Hw3.ko
	dmesg

CProg: SyscallRW.c
	gcc -o Sys SyscallRW.c
	sudo ./Sys

cleanc: SyscallRW.c
	rm Sys
