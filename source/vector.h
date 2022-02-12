#pragma once

#include <stdlib.h>

/*  Macro functions to make the calling of the below defined function less verbose. */

#define VECTOR_INIT(vec) vector_init(&vec)
#define VECTOR_ADD(vec, item) add(&vec, (void *) item)
#define VECTOR_REMOVE(vec, index) delete(&vec, index)
#define VECTOR_GET(vec, type, index) ((type) get(&vec, index))
#define VECTOR_FREE(vec) vector_free(&vec)
#define VECTOR_SIZE(vec) get_size(&vec)

typedef struct {
    // An array of pointers to structs.
    void ** data;
    // Current max size of the array.
    int capacity;
    // Number of elements in the array.
    int size;
} Vector;

void vector_init(Vector *);
static void resize(Vector *, int);
void add(Vector *, void *);
void delete(Vector *, int);
void * get(Vector *, int);
void vector_free(Vector *);
int get_size(Vector *);
