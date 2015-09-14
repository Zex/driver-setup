# top-level Makefile
#
KMOD_HEADERS = `pwd`/kmod
INCLUDES = . $(KMOD_HEADERS)

.PHONY: all apps

apps: 
	make -C apps all


