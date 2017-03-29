#==============================================================================
# Linked List: Makefile
#------------------------------------------------------------------------------
# Makefile for compiling an a c-based linked list implementation.
#
# Created: 	March 21, 2017
# Author: 	Matt Mumau
#==============================================================================

# The c compiler
CC=gcc

# Project directories
INC_DIR=inc
SRC_DIR=src
OBJ_DIR=obj
LIB_DIR=lib
BIN_DIR=bin

# Compiler flags
CFLAGS=-I$(INC_DIR)

# Project DEPS
_DEPS = list.h
DEPS = $(patsubst %,$(INC_DIR)/%,$(_DEPS))

# Demo OBJs
_OBJ_DMO = main.o list.o
OBJ_DMO = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ))

# Debug OBJs
_OBJ_DBG = main.debug.o list.debug.o
OBJ_DBG = $(patsubst %,$(OBJ_DIR)/%,$(_OBJ_DBG))

$(LIB_DIR)/liblist.a: $(OBJ_DIR)/list.o
	ar rcs $@ $<

$(OBJ_DIR)/list.o: $(SRC_DIR)/list.c $(DEPS)
	$(CC) -c -o $(OBJ_DIR)/list.o $(SRC_DIR)/list.c $(CFLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c $(DEPS)
	$(CC) -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c $(CFLAGS)	

$(OBJ_DIR)/%.debug.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) -ggdb -c -o $@ $< $(CFLAGS)	

demo: $(SRC_DIR)/main.c $(LIB_DIR)/liblist.a
	gcc -o $(BIN_DIR)/list_demo $(SRC_DIR)/main.c $(CFLAGS) -Llib -llist

debug: $(OBJ_DBG)
	gcc -ggdb -o $(BIN_DIR)/list_demo.debug $(OBJ_DBG) $(CFLAGS)

clean:
	rm -f $(OBJ_DIR)/*.o $(OBJ_DIR)/*.debug.o $(LIB_DIR)/liblist.a $(BIN_DIR)/list_demo $(BIN_DIR)/list_demo.debug

.PHONY: clean
	

		