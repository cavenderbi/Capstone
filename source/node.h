#pragma once

#include <stdbool.h>
#include <malloc.h>

/*  Node is a basic linked list with a void pointer data item. 
    Be careful with void pointers and be sure to cast them
    to their intended datatype. */
typedef struct {
    struct Node * next;
    void * data;
} Node;

Node * insert(Node *, void *);
Node * remove(Node *, int);
