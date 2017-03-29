#==============================================================================
# Linked List: Makefile
#------------------------------------------------------------------------------
# Makefile for compiling an a c-based linked list implementation.
#------------------------------------------------------------------------------
# Created: 	March 21, 2017
#------------------------------------------------------------------------------
# Author: 	Matt Mumau
#==============================================================================

# The c compiler program
CC=gcc

# Project directories
INCLUDE_DIR=inc
SRC_DIR=src
OBJECT_DIR=obj
BIN_DIRECTORY=bin
LIBRARIES=

# Compiler flags
CFLAGS=-I$(INCLUDE_DIR)

# Project dependencies
_DEPENDENCIES = list.h
DEPENDENCIES = $(patsubst %,$(INCLUDE_DIR)/%,$(_DEPENDENCIES))

# Project objects
_OBJECT = main.o list.o
OBJECT = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJECT))

# Debug objects
_OBJECT_DEBUG = main.debug.o list.debug.o
OBJECT_DEBUG = $(patsubst %,$(OBJECT_DIR)/%,$(_OBJECT_DEBUG))

# A catch-all rule which compiles all files with the .c extension within the 
# source directory into objects in the object directory.
$(OBJECT_DIR)/%.o: $(SRC_DIR)/%.c $(DEPENDENCIES)
	$(CC) -c -o $@ $< $(CFLAGS)

$(OBJECT_DIR)/%.debug.o: $(SRC_DIR)/%.c $(DEPENDENCIES)
	$(CC) -ggdb -c -o $@ $< $(CFLAGS)	

list_test: $(OBJECT)
	gcc -o $(BIN_DIRECTORY)/$@ $^ $(CFLAGS) $(LIBRARIES)

debug: $(OBJECT_DEBUG)
	gcc -ggdb -o $(BIN_DIRECTORY)/list_test.debug $(OBJECT_DEBUG) $(CFLAGS) $(LIBRARIES)

clean:
	rm -f $(OBJECT_DIR)/*.o $(OBJECT_DIR)/*.debug.o bin/list_test bin/list_test.debug

.PHONY: clean
	

		