KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m += Hw4.o

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean

Hw2BAR: Hw4.c 
	gcc -g -o Hw4 Hw4.c
	sudo ./Hw4

HW2Clean:
	rm Hw4

CProg: SyscallRW.c
	gcc -o Sys SyscallRW.c
	sudo ./Sys

cleanc: SyscallRW.c
	rm Sys
