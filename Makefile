# rule name: dependencies
# <TAB> rule commands
# - make runs the first rule, and then its dependencies
#   or can be called with a rule name
# - when a makefile is run, it will only make if the file with the same name as the rule doesn't exist or any dependencies have
#   been updated since last make
# - clean is just a convention -- there is no make clean by default, it must be included in a rule
# - make variables are name := value, and accessed using $(name)
# - all rule as convention to run multiple targets
# - $@ contains the target name
# - wildcards (*) should always be ran 

# lmao chatgpt can just do it

# Set the final executable name
exe_name = game.exe

# Compiler and flags
CC = gcc
CFLAGS = -std=c17 -Wall 

# Add all subdirectories of lib/ to the include path
INCLUDE_PATHS := $(shell find include -type d)
INCLUDE_PATHS += $(shell find src -type d)
CFLAGS += -DPLATFORM_DESKTOP
CFLAGS += $(addprefix -I, $(INCLUDE_PATHS))

# Library paths and libraries
LDFLAGS := -Llib 
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm 


# Find all .c files in src/ and lib/ directories recursively
SRCS := $(shell find src lib -name "*.c")

# Generate corresponding object files in build/ directory
OBJS := $(patsubst %.c, build/%.o, $(SRCS))

# Default target
all: bin/$(exe_name)

# Link object files to create the final executable
bin/$(exe_name): $(OBJS)
	mkdir -p bin
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)

# Compile .c files to .o files in build/ directory
# build/%.o: %.c
build/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to remove the build/ directory
clean:
	rm -rf build/

# Production build with optimization flags
production: CFLAGS += -O3
production: all

debug: CFLAGS += -g
debug: all
