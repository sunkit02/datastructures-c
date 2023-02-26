#include "hashmap.h"
#include "linkedlist.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int hashstr(char *str, size_t len);

HashMap *mapnew(size_t bucketWidth) {
    LinkedList *buckets;
    size_t initialSize = 0;

    if ((buckets = calloc(bucketWidth, sizeof(LinkedList))) == NULL) {
        exit(EXIT_FAILURE);
    }
    
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    map->buckets = buckets;
    map->bucketWidth = bucketWidth;
    map->size = initialSize;
    return map;
}

bool mapcontains(HashMap* map, char* key) {
    return false;
}

void mapput(HashMap* map, char *key, void* value) {
    int hash = hashstr(key, strlen(key));
    // check if exists
    if (mapcontains(map, key)) {
        // replace previous value
    } else {
        // insert value at hash
       append(&map->buckets[hash], value);
    }
    // increment stackSize
    
}

int hashstr(char *str, size_t len) {
    return len;
}
