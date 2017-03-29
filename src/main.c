#ifndef MAIN_DEF
#define MAIN_DEF 1

/*
 File:          main.c
 Description:   A variety of tests and examples of linked list usages.
 Created:       March 21, 2017
 Author:        Matt Mumau
 */

// System Dependencies
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Local includes
#include "list.h"

unsigned int getRandomNumber()
{
    return (rand() % 10) + ((rand() % 10) * 10) + \
        ((rand() % 10) * 100) + ((rand() % 10) * 1000) + \
        ((rand() % 10) * 10000) + ((rand() % 10) * 100000) + \
        ((rand() % 10) * 1000000) + ((rand() % 10) * 10000000);
}

void loadList(char *data[], List **list, unsigned int count) 
{
    srand(time(NULL));

    char *buffer;
    size_t formatted_size;
    char *format = "{id: %d, val: %d}";
    unsigned int rand_num;

    for (unsigned int i = 0; i < count; i++)
    {
        rand_num = getRandomNumber();

        formatted_size = snprintf(NULL, 0, format, i + 1, rand_num);
        buffer = malloc(formatted_size + 1);
        if (buffer == NULL)
        {
            return;
        }
        snprintf(buffer, formatted_size + 1, format, i + 1, rand_num);
        data[i] = buffer;
    }

    for (unsigned int j = 0; j < count; j++)
    {
        printf("Data item [%d]: %s\n", j + 1, (char *) data[j]);
    }

    for (unsigned int k = 0; k < count; k++)
    {
        list_push(list, (void *) data[k]);
    }

    printf("=================================================\n");
}

void unloadList(List **list, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
    {
        free((char *) list_pop(list));    
    }
}

void iterateByPointer(List *list)
{
    char *buffer = NULL;
    while (list != NULL)
    {
        buffer = (char *) list->data;
        printf("[[%d]] [next: %d, data: %s]\n", list, list->next, buffer);
        list = list->next;
    }
}

void iterateByIndex(List *list)
{
    unsigned int total = list_sizeof(list);
    char *buffer = NULL;
    List *cursor = NULL;
    for (unsigned int i = 1; i <= total; i++)
    {
        cursor = list_get(list, i);
        buffer = (char *) cursor->data;
        printf("[#%d] [[%d]] [next: %d, data: %s]\n", i, cursor, cursor->next, buffer);
    }
}

void main (int argc, char *argv[])
{
    const unsigned int n = 5; // must be greater than 3
    const unsigned int remove_at = 2;
    char *data[n];

    List *list = NULL;

    printf("=================================================\n");
    printf("         Linked List Tests and Examples\n");
    printf("=================================================\n");

    printf("Total nodes specified: %d\n", n);
    printf("=================================================\n");
    
    printf("Size of list before loading [should be 0]: %d\n", list_sizeof(list));
    printf("=================================================\n");
    
    loadList(data, &list, n);
    printf("Size of list after loading [should be %d]: %d\n", n, list_sizeof(list));
    printf("=================================================\n");

    printf("Iterating through list by pointer: \n");
    printf("-------------------------------------------------\n");
    iterateByPointer(list);
    printf("=================================================\n");

    printf("Iterating through list by index number: \n");
    printf("-------------------------------------------------\n");
    iterateByIndex(list);
    printf("=================================================\n");

    printf("Removing item number %d...\n", remove_at);
    printf("=================================================\n");
    list_remove(&list, remove_at);

    printf("Iterating through list after removing item %d: \n", remove_at);
    printf("-------------------------------------------------\n");
    iterateByIndex(list);
    printf("=================================================\n");

    printf("Size of list after removing item %d [should be %d]: %d\n", remove_at, n - 1, list_sizeof(list));
    printf("=================================================\n");

    //unloadList(&list, n);
    //printf("Size after unloading [should be 0]: %d\n", list_sizeof(list));
    //printf("=================================================\n");

    printf("Bye! :)\n");
    exit(1);
}

#endif