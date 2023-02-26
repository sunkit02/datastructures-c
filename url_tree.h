#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

typedef struct urlTreeNode{
    struct urlTreeNode *parent;
    LinkedList *children;
    char *endpoint;
    void (*callback)();
} UrlTreeNode;


typedef struct urlTree {
    UrlTreeNode *root;
    size_t size;
    void (*registerEndPoint)(struct urlTree *self, char* url, void (*callback)());
    void (*handleRequest)(struct urlTree *self, char *url);

} UrlTree;

UrlTree *newUrlTree();


#endif 
