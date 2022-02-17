# Directories
SRCDIR=src
DEPDIR=deps
OBJDIR=objs

# Find all sources
SRC = $(shell find $(SRCDIR) -name "*.cpp")
OTMP = $(patsubst %.cpp,%.o,$(SRC:$(SRCDIR)/%=%))
OBJS = $(patsubst %,$(OBJDIR)/%,$(OTMP))
DEPS = $(patsubst %.o,$(DEPDIR)/%.d,$(OTMP))

# Variables
CC = g++ -fopenmp
ifdef DEBUG
CC += -g
CPPFLAGS = -g -fbounds-check -fopenmp -O3 -Iheaders -std=c++11
else
CPPFLAGS = -fopenmp -O3 -Iheaders -std=c++11
endif

LIBS = 

all: init $(OBJS)
	@echo Building the executable...
	$(CC) -o main $(OBJS) $(LIBS)

init:
	@echo Initilizing...
	mkdir -p $(DEPDIR)
	mkdir -p $(OBJDIR)

clean:
	@echo Clearing...
	rm -fr $(OBJDIR)/ $(DEPDIR)/ main result.ppm

.PHONY: all clean test

-include $(DEPS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(dir $@)
	mkdir -p $(DEPDIR)/$(dir $(@:$(OBJDIR)/%=%))
	$(eval CPP = $(shell find $(SRCDIR)/$(dir $*) -name "$(notdir $*).cpp"))
	$(CC) -c $(CPPFLAGS) $(CPP) -o $@ $(LIBS)
	$(CC) -MM $(CPPFLAGS) $(CPP) $(LIBS) > $(DEPDIR)/$*.d
