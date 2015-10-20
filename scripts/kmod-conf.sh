#!/bin/bash
# Build kmod devel
# Author: Zex Li <top_zlynch AT yahoo.com>
#
# make ctags

[ -f "Makefile" ] && make distclean

./configure                             \
    --prefix=`pwd`/../driver-setup/kmod \
    --disable-manpages                  \
    --disable-test-modules              \
    --enable-debug                      \
    --enable-experimental               \
    --enable-shared                     
[ 0 -ne $? ] && echo "configure failed" && exit

make
[ 0 -ne $? ] && echo "make failed" && exit

#make install-exec
make install-binPROGRAMS
[ 0 -ne $? ] && echo "install applications failed" && exit

make install-includeHEADERS
[ 0 -ne $? ] && echo "install headers failed" && exit

