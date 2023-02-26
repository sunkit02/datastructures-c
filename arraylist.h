#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct arraylist {
    void *elements;
    size_t size;
    size_t elementSize;
    size_t capacity;
    char *type;
    bool (*add)(struct arraylist *self, void *element);
    bool (*insert)(struct arraylist *self, void *element, size_t index);
    void *(*get)(struct arraylist *self, size_t index);
    void *(*remove)(struct arraylist *self, size_t index);
    bool (*isEmpty)();
    void (*clear)();
} ArrayList;

ArrayList* newArrayList(size_t initialCapacity, size_t elementSize); 

#endif 
