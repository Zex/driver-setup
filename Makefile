# top-level Makefile
#
KMOD_HEADERS = `pwd`/kmod
INCLUDES = . $(KMOD_HEADERS)/include
LDPATH =  $(KMOD_HEADERS)/lib

.PHONY: all apps

apps: 
	make -C apps all


