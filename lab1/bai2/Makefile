
obj-m := bai2.o

KDIR := /lib/modules/`uname -r`/build

arr ?= 2,6,0,5,2,0,0,0

all:
	make -C ${KDIR} M=`pwd`

clean:
	make -C ${KDIR} M=`pwd` clean

install:
	sudo dmesg -C
	sudo insmod bai2.ko arr=${arr}
	sudo rmmod bai2
