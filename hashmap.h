#ifndef HASHMAP_H
#define HASHMAP_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

typedef struct {
    LinkedList *buckets;
    size_t bucketWidth;
    size_t size;
} HashMap;

HashMap *mapnew(size_t bucketWidth);
bool mapcontains(HashMap* map, char *key);
void mapput(HashMap* map, char *key, void* value);
void* mapget(HashMap* map, char *key);
void mapprint(HashMap *map);

#endif 
