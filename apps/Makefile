# apps Makefile
#
.PHONY: all

SOURCES := $(shell find . -iregex ".*\.c\(\|c\|pp\|++\|xx\)")
#TARGETS := $(SOURCES:.cpp=)
TARGETS := $(SOURCES:.c=)
OUTDIR	:= $(BUILD)/$(notdir $(CURDIR))

all: outdir $(TARGETS)

%: %.cpp
	$(CXX) -o $(OUTDIR)/$@ $^

%: %.c
	$(CC) -o $(OUTDIR)/$@ $^

outdir:
	$(MKDIR) $(OUTDIR)

clean:
	@echo "cleaning apps ..."
	$(RM) $(TARGETS:%=$(OUTDIR)/%)
	$(RMDIR) $(OUTDIR)
