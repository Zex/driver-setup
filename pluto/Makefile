# Makefile for pluto
#
obj-m		:= pluto.c
#MODULES_LIB	:= /lib/modules/$(shell uname -r)/build
MODULES_LIB	:= /usr/src/$(shell uname -r)

all:
	make -C $(MODULES_LIB) M=$(shell pwd)

clean:
	make -C $(MODULES_LIB) M=$(shell pwd) clean
	
# rm -f *.o *.ko *.mod.*

# ifneq ($(KERNELRELEASE),)
# 	obj-m := pluto.o
# 	#obj-$(CONFIG_HELLO_MODULE) += hello_module.o
# else
# 	PWD := $(shell pwd)
# 	KERNELVER := $(shell uname -r)
# 	KERNELDIR := /lib/modules/$(KERNELVER)/build
# default:
# 	$(MAKE) -C $(KERNELDIR) M=$(PWD)
# endif

