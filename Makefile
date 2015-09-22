# top-level Makefile
#
KMOD_HEADERS = `pwd`/kmod
INCLUDES = . $(KMOD_HEADERS)/include
LDPATH =  $(KMOD_HEADERS)/lib

.PHONY: all apps pluto

apps: 
	$(MAKE) -C apps all

pluto: 
	$(MAKE) -C pluto all

tags:
	ctags -R . ../linux-zex

clean:
	$(MAKE) -C pluto clean
	$(MAKE) -C apps clean
