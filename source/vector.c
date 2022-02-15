#include "vector.h"

/*  Initializes the Vector. 
    @param vector A pointer to the vector to be initialized.
    @param size The size of the datatype to be stored. */
void vector_init(Vector * vector) {
    vector->capacity = 16;
    vector->size = 0;
    vector->data = malloc(sizeof(void *) * vector->capacity);
}

/*  Static function that resizes the array. 
    Due to how static functions work in C, you shouldn't be able to use this outside of vector.c
    @param vector A pointer to the vector to be resized. 
    @param capacity The new max capacity of the vector. */
static void resize(Vector * vector, int capacity) {
    /*  Reallocate the memory for the array. */
    void ** data = realloc(vector->data, sizeof(void *) * capacity);
    /*  If reallocation was successful (!= NULL), set the data and capacity fields to their new values. 
        Just checking the value of the pointer itself is faster, since NULL is 0 and false is also 0, 
        checking if (data) would work just the same. */
    if (data) {
        vector->data = data;
        vector->capacity = capacity;
    }
}

/*  Adds an element to the vector. 
    @param vector A pointer to the vector to be added to. 
    @param element The element to be added to the vector. */
void add(Vector * vector, void * element) {
    /*  If the vector is full, double it's size. */
    if (vector->capacity == vector->size)
        resize(vector, vector->capacity * 2);
    /*  Put the element in the next index of the array, then increment the size.
        BTW, if you wanted to increment, then use the number, ++vector->size is 
        also valid C and does just that. I've never needed it, but it's there. */
    vector->data[vector->size++] = element;
}

/*  Removes the element at the index provided and shifts all others forward. 
    @param vector A pointer to the vector to be removed from. 
    @param index The index of the element to be removed. */
void delete(Vector * vector, int index) {
    if (index < 0 || index >= vector->size)
        return;

    vector->data[index] = NULL;

    int i;
    for(i = index; i < vector->size - 1; i++) {
        vector->data[i] = vector->data[i + 1];
        vector->data[i + 1] = NULL;
    }

    vector->size--;

    if (vector->size > 0 && vector->size == vector->capacity / 4) 
        resize(vector, vector->capacity / 2);
}

/*  Gets the pointer to your data 
    @param vector A pointer to the vector to be gotten from.
    @param index The index of the element to be gotten.
    @returns A pointer to the element in the vector. */
void * get(Vector * vector, int index) {
    if (index >= 0 && index < vector->size)
        return vector->data[index];
    return NULL;
}

/*  Free's the vector's data and the vector itself. 
    @param A pointer to the vector to be free'd. */
void vector_free(Vector * vector) {
    free(vector->data);
    free(vector);
}


/*  Returns the current size of the vector, not counting empty indecies. 
    @param vector A pointer to the vector to be sized. 
    @returns The size of the vector, not counting empty indecies. */
int get_size(Vector * vector) { return vector->size; }

/*  Returns the current capacity of the vector. 
    @param vector A pointer to the vector to get the capacity of. 
    @returns The capacity of the vector. */
int get_capacity(Vector * vector) { return vector->capacity; }