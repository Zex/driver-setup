# Makefile for venus
#
MODNAME		:= venus
obj-m		:= $(MODNAME).o
KERNVER		:= $(shell uname -r)
MODULES_LIB		:= /lib/modules/$(KERNVER)/build
SIGNFILE_PATH	:= $(MODULES_LIB)/scripts/sign-file
PRIVKEY_PATH	:= signing_key.priv
X509KEY_PATH	:= signing_key.x509

all:
	$(MAKE) -C $(MODULES_LIB) M=$(shell pwd) modules

clean:
	$(MAKE) -C $(MODULES_LIB) M=$(shell pwd) clean
	
# rm -f *.o *.ko *.mod.*

# ifneq ($(KERNELRELEASE),)
# 	obj-m := venus.o
# 	#obj-$(CONFIG_HELLO_MODULE) += hello_module.o
# else
# 	PWD := $(shell pwd)
# 	KERNELVER := $(shell uname -r)
# 	KERNELDIR := /lib/modules/$(KERNELVER)/build
# default:
# 	$(MAKE) -C $(KERNELDIR) M=$(PWD)
# endif
signmod:
	perl $(SIGNFILE_PATH) sha512 $(PRIVKEY_PATH) $(X509KEY_PATH) $(MODNAME).ko

kernkey:
	openssl req -new -nodes -utf8 -sha256 -days 36500 -batch -x509 \
	-config ../misc/x509.genkey -outform DER -out $(X509KEY_PATH) -keyout $(PRIVKEY_PATH)
