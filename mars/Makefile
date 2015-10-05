# Makefile for mars module
# Author: Zex Li <top_zlynch AT yahoo.com>
# Copyright 2015 Zex Li <top_zlynch AT yahoo.com>. All Rights Reserved
MODNAME		:= mars
obj-m		:= $(MODNAME).o mars-dev1.o
KERNVER		:= $(shell uname -r)
MODULES_LIB		:= /lib/modules/$(KERNVER)/build
SIGNFILE_PATH	:= $(MODULES_LIB)/scripts/sign-file
PRIVKEY_PATH	:= signing_key.priv
X509KEY_PATH	:= signing_key.x509

.PHONY: all clean

all:
	$(MAKE) -C $(MODULES_LIB) M=$(shell pwd) modules

clean:
	$(MAKE) -C $(MODULES_LIB) M=$(shell pwd) clean
	
# rm -f *.o *.ko *.mod.*

signmod:
	perl $(SIGNFILE_PATH) sha512 $(PRIVKEY_PATH) $(X509KEY_PATH) $(MODNAME).ko

kernkey:
	openssl req -new -nodes -utf8 -sha256 -days 36500 -batch -x509 \
	-config ../misc/x509.genkey -outform DER -out $(X509KEY_PATH) -keyout $(PRIVKEY_PATH)
