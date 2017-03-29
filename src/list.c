#ifndef LIST_DEF
#define LIST_DEF 1

/*
 File:          list.c
 Description:   Implementation of linked list object functionality.
 Created:       March 21, 2017
 Author:        Matt Mumau
 */

// System dependencies
 #include <stdlib.h>

// Header
#include "list.h"

void list_push(List **head, void *data)
{
    List *node = malloc(sizeof(List));
    if (node == NULL) {
        return;
    }

    node->data = data;
    node->next = NULL; 

    if (*head == NULL) {    
        *head = node;
        return;
    }

    while ((*head)->next != NULL)
    {
        head = &(*head)->next;
    }

    (*head)->next = node;
}

void *list_pop(List **head)
{
    void *data = NULL;

    if (*head == NULL)
    {
        return data;
    }

    List **last = head;
    while ((*head)->next != NULL)
    {
        last = head;
        head = &(*head)->next;
    }

    data = (void *) (*head)->data;

    (*last)->next = NULL;
      
    free(*head); 
    *head = NULL;

    return data;
}

void list_insert(List **head, void *data)
{
    List *node = malloc(sizeof(List));
    node->data = data;
    node->next = *head;

    *head = node;
}

unsigned int list_sizeof(List *head)
{
    if (head == NULL)
    {
        return 0;
    }    

    unsigned int size = 1;

    while (head->next != NULL)
    {
        size++;
        head = head->next;
    }

    return size;
}

List *list_get(List *head, unsigned int index)
{
    for (unsigned int i = 1; i < index; i++) {
        head = head->next;
    }

    return head;
}

void list_remove(List **head, unsigned int index)
{
    if (!head || !*head || !index || index > list_sizeof(*head))
        return;    

    List **cursor = head;
    List **before_cursor = cursor;
    for (unsigned int i = 1; i < index; i++)
    {
        if ((*cursor)->next == NULL)
            break;

        before_cursor = cursor;
        cursor = &(*cursor)->next;
    }

    (*before_cursor)->next = (*cursor)->next;    
    
    free(*cursor);
    *cursor = NULL;
}

#endif