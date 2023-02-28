#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct arraylist {
    void *elements;
    size_t size;
    size_t elementSize;
    size_t capacity; // The max number of elements to be held (Not the number of bytes)
    char *type;
    bool (*add)(struct arraylist *self, void *element);
    void *(*get)(struct arraylist *self, size_t index);
    bool (*insert)(struct arraylist *self, void *element, size_t index);
    void (*remove)(struct arraylist *self, size_t index);
    bool (*isEmpty)(struct arraylist *self);
    void (*clear)(struct arraylist *self);
    char *(*toString)(struct arraylist *self, char *(elementToString)(void *element));
} ArrayList;

ArrayList* newArrayList(size_t initialCapacity, size_t elementSize); 

#endif 
