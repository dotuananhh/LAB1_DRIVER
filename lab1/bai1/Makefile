obj-m := bai1.o
MODULE_FILE := bai1.ko

choice ?= 2
arr ?= 2,6,0,5,2,0,0,0
a ?= 2605
b ?= 2000

KDIR := /lib/modules/`uname -r`/build

all:
	make -C ${KDIR} M=`pwd` 

clean:
	make -C ${KDIR} M=`pwd` clean

install:
	sudo dmesg -C
	sudo insmod ${MODULE_FILE} choice=${choice} arr=${arr} a=${a} b=${b}
	sudo rmmod ${MODULE_FILE}

echo:
	echo ${choice}
	echo ${arr}
