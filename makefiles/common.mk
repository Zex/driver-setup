# common.mk - Common definition for makefiles
# Author: Zex Li <top_zlynch AT yahoo.com>
# Copyright 2015 Zex Li <top_zlynch AT yahoo.com>. All Rights Reserved

export BUILD	:= $(PWD)/build
export MKDIR	:= mkdir -p
export RMDIR	:= rmdir

all:
	$(MKDIR) $(BUILD)
