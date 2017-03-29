# Linked List
Created:  March 21, 2017

Author:   Matt Mumau

Licensed: MIT License (see included LICENSE file)

## What Is It?
An implementation of linked lists, written in c. It stores object data in 
generic pointers.

A variety of utility functions are included for typical list operations.

The list object itself is a c struct, which is defined in the list.h header 
file. You may browse that file for information about list operation functions.

## How Do I Use It?
You may build the linked list source into a static library and include it in
your project to give you linked list functionality. 

The List type may be used to refer to the list. Typically it will be used as a
pointer.

`#include "list.h"`

`List my_list_obj;`
`List *my_list;`

`...`
`list_sizeof(my_list);`

or

`...`
`List *my_list;`
`...`

## Available Functions

### list_push
`void list_push(List **head, void *data);`
Takes a void pointer of data as well as the address of a head pointer and adds
it to the end of the list

### list_pop
 Remove the final element of the list and return its data.
 */
void *list_pop(List **head);

/*
 Insert the data object to the beginning of the list.
 */
void list_insert(List **head, void *data);

/*
 Get the size of the list.
 */
unsigned int list_sizeof(List *head);

/*
 Get the data of the node at the given ordinal number in the list.
 */
List *list_get(List *head, unsigned int index);

/*
 Delete the item in the list at the given ordinal location (1 is the first).
 */
void list_remove(List **head, unsigned int index);


## Example Program, Tests
You may build this project with the included makefile by running simply "make"
from the command line, at the root directory of this project. This will build
an executable, list_test, in the bin directory ("bin/list_test").

The example program runs through a handful of scenarios using the list in order
to prove its functionality.



