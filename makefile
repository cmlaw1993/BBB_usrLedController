# makefile for usrLedController

# project name
TARGET 		= usrLedController
SUBTARGET	= on off flash status

# compiler
CC			= g++ -c
CFLAGS		= -std=c++11 -Wall $(foreach d,$(INCDIR),-I $d)

# linker
LINKER		= g++ -o
LFLAGS		=

# directories
SRCDIR 		= src
INCDIR 		= include
OBJDIR 		= obj
BINDIR		= bin

VPATH 		= $(foreach d,$(SRCDIR),$d) \
			  $(foreach d,$(INCDIR),$d) \
			  $(foreach d,$(OBJDIR),$d)


.PHONY: all
all: build_msg $(BINDIR)/$(TARGET) subtarget
	rm -f $(foreach d,$(INCDIR),$d/*.gch)
	@printf "# Precompiled headers removed!\n"
	@printf "# Done!\n"

.PHONY: build_msg
build_msg:
	@printf "#\n# Building $(TARGET)\n"
	@printf "# VPATH: $(VPATH)\n#\n"

.PHONY: subtarget
subtarget: $(BINDIR)/$(TARGET)
	$(foreach d,$(SUBTARGET),ln -fs $(TARGET) $(BINDIR)/$d;)
	@printf "# Symbolic links created!\n"

$(BINDIR)/$(TARGET): usrLed.o main.o
	$(LINKER) $@ $^
	@printf "# Linking successful!\n"

$(OBJDIR)/main.o: main.cpp usrLed.h
	$(CC) $(CFLAGS) $< -o $@
	@printf "# Compiled $< successfully!\n"

$(OBJDIR)/usrLed.o: usrLed.cpp usrLed.h
	$(CC) $(CFLAGS) $< -o $@
	@printf "# Compiled $< successfully!\n"

.PHONY: clean
clean:
	rm -f $(foreach d,$(INCDIR),$d/*.gch)
	rm -f $(OBJDIR)/*.o
	rm -f $(foreach d,$(SUBTARGET),$(BINDIR)/$d)
	rm -f $(BINDIR)/$(TARGET)

