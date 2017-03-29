# C Linked List
##### Created:  March 21, 2017

##### Author:   Matt Mumau

##### Licensed: MIT License (see included LICENSE file)

##### Repository: https://github.com/mpmumau/c_linked_list

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

    #include "list.h"

    List list_obj;
    List *my_list = &list_obj;
    list_sizeof(my_list);

or

    #include "list.h"

    List *my_list;
    list_sizeof(my_list);

Note that most volatile utility functions take a double pointer (an address to 
a pointer) as a parameter.

Also note that the data stored within the linked lists's nodes is pointed to
by a void pointer. Therefor, you must keep be aware of your own data types, and
must cast all pointers to data objects as void pointers (void *).

## Available Functions

### void list_push(List **head, void *data);
Takes a void pointer of data as well as the address of a head pointer and adds
it to the end of the list

#### Example:

    List *list;
    char *data = "Some data";
    list_push(&list, (void *) data);

### void *list_pop(List **head);
Remove the final element of the list and return its data.

#### Example:

    List *list;
    char *orig_data = "Original data";
    list_push(&list, (void *) orig_data);
    char *data;
    data = (char *) list_pop(&list);

### void list_insert(List **head, void *data);
Insert the data object to the beginning of the list.

#### Example

    List *list;
    char *data = "Some data";
    list_insert(&list, (void *) data);

### unsigned int list_sizeof(List *head);
Get the size of the list.

#### Example

    List *list;
    'char *data = "Some data";'
    char *moar_data = "Moar data";
    list_push(&list, (void *) data);
    list_push(&list, (void *) moar_data);
    return list_sizeof(list);
    // returns 2

### List *list_get(List *head, unsigned int index);
Get the data of the node at the given ordinal number in the list.

#### Example

    List *list;
    char *data="Some data";
    list_push(&list, data);
    char *retrieved_data = list_get(list, 1);

### void list_remove(List **head, unsigned int index);
Delete the item in the list at the given ordinal location (1 is the first).

#### Example

    List *list;
    char *data = "Some data";
    list_push(&list, data);
    list_remove(&list, 1);

## Example Program, Tests
You may build this project with the included makefile by running simply "make"
from the command line, at the root directory of this project. This will build
an executable, list_test, in the bin directory ("bin/list_test").

The example program runs through a handful of scenarios using the list in order
to prove its functionality and prints output to the console.



