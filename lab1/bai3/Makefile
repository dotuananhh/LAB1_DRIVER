

MODULE_NAME := bai3

obj-m := ${MODULE_NAME}.o

KDIR := /lib/modules/`uname -r`/build

width ?= 5
heigh ?= 5
matrix ?= -1,-2,3,-4,5,-6,7,8,9,2,6,0,5,2,0,0,0,-2,-6,0,-5,-2,0,0,0,-4

all:
	make -C ${KDIR} M=`pwd`

clean:
	make -C ${KDIR} M=`pwd` clean

install:
	sudo dmesg -C
	sudo insmod ${MODULE_NAME}.ko width=${width} heigh=${heigh} matrix=${matrix}
	sudo rmmod ${MODULE_NAME}
