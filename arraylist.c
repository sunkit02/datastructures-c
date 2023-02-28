#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arraylist.h"

#include "tests/integer.h"


bool arrayListResize(ArrayList *self, size_t newSize) {
    void *temp = realloc(self->elements, newSize);
    if (temp == NULL) {
        return false;
    }
    self->elements = temp;
    return true;
}


bool arrayListAdd(ArrayList *self, void *element) {

    // double capacity when not enough space
    if (self->size >= self->capacity) {
        size_t newCapacity = self->capacity * 2;
        printf("Target new capacity: %zu\n", newCapacity);
        bool resizeSuccess = arrayListResize(self, newCapacity * self->elementSize);
        self->capacity = newCapacity;
        printf("resized array. new capacity: %zu\n", self->capacity);
        if (!resizeSuccess) {
            puts("Failed to resize array");
            exit(EXIT_FAILURE);
        }
    }

    // append new element to end of elements
    size_t size = self->size;
    void *start = self->elements + (size * self->elementSize);
    memcpy(start, element, self->elementSize);
    self->size++;
    return true;
}


bool arrayListInsert(ArrayList *self, void* element, size_t index) {
    // validate index
    if (index > self->size) {
        printf("Insert(). Index out of bounds. Max=%zu, Given=%zu\n", self->size, index);
        exit(EXIT_FAILURE);
    }

    // resize array if needed
    if (self->size >= self->capacity - 1) {
        size_t newCapacity = self->capacity * 2;
        printf("Target new capacity: %zu\n", newCapacity);
        bool resizeSuccess = arrayListResize(self, newCapacity * self->elementSize);
        self->capacity = newCapacity;
        printf("resized array. new capacity: %zu\n", self->capacity);
        if (!resizeSuccess) {
            puts("Failed to resize array");
            exit(EXIT_FAILURE);
        }
    }

    // copy elements in the way to temp address
    void *startCpy = self->elements + (index * self->elementSize);
    void *temp = malloc(self->elementSize * (self->size - index));
    memcpy(temp, startCpy, self->elementSize * (self->size - index));

    // insert the element
    void *startPtr = self->elements + (index * self->elementSize);
    memcpy(startPtr, element, self->elementSize);

    // copy rest of elements one index down
    memcpy(startPtr + (self->elementSize), temp, self->elementSize * (self->size - index));

    // free temp address
    free(temp);

    // increment list size
    self->size++;
    return true;
}


void arrayListRemove(ArrayList *self, size_t index) {
    // validate index
    if (index >= self->size) {
        printf("Remove(). Index out of bounds. Max=%zu, Given=%zu\n", self->size - 1, index);
        exit(EXIT_FAILURE);
    }

    // copy elements behind element to be removed
    void *temp = malloc(self->elementSize * (self->size - index - 1));
    memcpy(temp, self->elements + ((index + 1) * self->elementSize), self->elementSize * (self->size - index - 1));

    // move elements behind one index forward
    memcpy(self->elements + (index * self->elementSize), temp, self->elementSize * (self->size - index - 1));

    // decrement list size
    self->size--;
}


void *arrayListGet(ArrayList *self, size_t index) {
    if (index >= self->size) {
        printf("Get(). Index out of bounds. Max: %zu, Given: %zu\n", self->size - 1, index);
        exit(EXIT_FAILURE);
    }

    return self->elements + (self->elementSize * index);
}

bool arrayListIsEmpty(ArrayList *self) {
    return self->size == 0;
}

char *arrayListToString(ArrayList *self, char *(elementToString)(void *element)) { 
    printf("%s", "[");
    for (size_t i = 0; i < self->size; i++) {
        printf("%s", elementToString(self->get(self, i)));
        if (i < self->size - 1) printf("%s", ", ");
    }
    puts("]");

    return NULL;
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
    list->remove = arrayListRemove;
    list->isEmpty = arrayListIsEmpty;
    list->toString = arrayListToString;

    return list;
}
