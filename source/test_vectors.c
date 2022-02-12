#include <stdio.h>

#include "vector.h"

void main() {
    int i;
    Vector v;
    VECTOR_INIT(v);

    VECTOR_ADD(v, "Bonjour");
    VECTOR_ADD(v, "tout");
    VECTOR_ADD(v, "le");
    VECTOR_ADD(v, "monde");

    for (i = 0; i < VECTOR_SIZE(v); i++)
        printf("%s ", VECTOR_GET(v, char *, i));
    printf("\n");


    VECTOR_REMOVE(v, 3);
    VECTOR_REMOVE(v, 2);
    VECTOR_REMOVE(v, 1);
    VECTOR_REMOVE(v, 0);

    VECTOR_ADD(v, "Hello");
    VECTOR_ADD(v, "World");

    for (i = 0; i < VECTOR_SIZE(v); i++)
        printf("%s ", VECTOR_GET(v, char *, i));
    printf("\n");
}