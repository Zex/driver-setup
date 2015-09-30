# top-level Makefile
# Author: <Zex Li AT yahoo.com>
KMOD_HEADERS:= `pwd`/kmod
INCLUDES	:= . $(KMOD_HEADERS)/include
LDPATH		:= $(KMOD_HEADERS)/lib
COMPONENTS	:= apps pluto mars

.PHONY: all apps pluto mars

include makefiles/common.mk

all:
	$(foreach comp, $(COMPONENTS),$(MAKE) -C $(comp) all;)

apps: 
	$(MAKE) -C apps all

pluto: 
	$(MAKE) -C pluto all

mars: 
	$(MAKE) -C mars all

tags:
	ctags -R . ../linux-zex
 
clean_apps:
	$(MAKE) -C apps clean

clean:
	$(foreach comp, $(COMPONENTS),$(MAKE) -C $(comp) clean;)
ifeq ($(BUILD),)
	@echo "BUILD not defined"
else
	@echo "cleaning "$(BUILD)"..."
	$(RMDIR) $(BUILD)
endif
	@echo "clean done ..."

