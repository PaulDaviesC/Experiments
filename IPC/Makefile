obj-m:=dev.o
Kver=$(shell uname -r)
CC=cc
all:
	make -C /lib/modules/$(Kver)/build M=$(PWD) modules
clean:
	rm *.mod.* dev.o dev.ko modules.order Module.symvers read write;
exe:
	$(CC) read.c -o read
	$(CC) write.c -o write
dev:
	mknod /dev/ipcdev c 250 0
