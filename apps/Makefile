# apps Makefile
#
.PHONY: all


SOURCES := $(shell find . -iregex ".*\.c\(\|c\|pp\|++\|xx\)")
TARGETS := $(SOURCES:.cpp=)

all: $(TARGETS)

%: %.cpp
	$(CXX) -o $@ $

clean:
	@echo "cleaning apps ..."
