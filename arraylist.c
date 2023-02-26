#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arraylist.h"


bool arrayListResize(ArrayList *list, size_t newSize) {
    void *temp = realloc(list->elements, newSize);
    if (temp == NULL) {
        return false;
    }
    list->elements = temp;
    return true;
}


bool arrayListAdd(ArrayList *self, void *element) {
    if (self->size >= self->capacity) {
        bool resizeSuccess = arrayListResize(self, self->capacity * self->elementSize * 2);
        if (!resizeSuccess) {
            puts("Failed to resize array");
            exit(EXIT_FAILURE);
        }
    }

    size_t size = self->size;
    void *start = self->elements + (size * self->elementSize);
    memcpy(start, element, self->elementSize);
    self->size++;
    return true;
}


bool arrayListInsert(ArrayList *self, void* element, size_t index) {
    if (self->size >= self->capacity) {
        bool resizeSuccess = arrayListResize(self, self->capacity * self->elementSize * 2);
        if (!resizeSuccess) {
            puts("Failed to resize array");
            exit(EXIT_FAILURE);
        }
    }

    // copy elements in the way to temp address
    void *startCpy = self->elements + (self->size * self->elementSize) + 1;
    void *temp = malloc(self->elementSize * (self->size - index));
    memcpy(temp, startCpy, self->elementSize * (self->size - index));

    // insert the element
    void *startPtr = self->elements + (index * self->elementSize);
    memcpy(startPtr, element, self->elementSize);
    
    // copy rest of elements one index down
    memcpy(startPtr + (self->elementSize), temp, self->elementSize * (self->size - index));

    // free temp address
    free(temp);

    return true;
}


void* arrayListGet(ArrayList *list, size_t index) {
    if (index >= list->size) {
        printf("Index out of bounds. Max: %zu, Given: %zu\n", list->size, index);
        exit(EXIT_FAILURE);
    }
    return list->elements + (list->elementSize * index);
}


ArrayList *newArrayList(size_t initialCapacity, size_t elementSize) {
    ArrayList *list = malloc(sizeof(ArrayList));
    list->elements = calloc(initialCapacity, elementSize);
    list->size = 0;
    list->capacity = initialCapacity;
    list->elementSize = elementSize;
    list->add = arrayListAdd;
    list->get = arrayListGet;
    list->insert = arrayListInsert;

    return list;
}
