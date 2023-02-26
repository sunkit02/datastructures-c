#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdlib.h>

typedef struct node {
  void* value;
  struct node *next;
} Node;

typedef struct singlyLinkedList{
  size_t size;
  Node *head;
  void (*append)(struct singlyLinkedList *self, void* value);
  void (*push)(struct singlyLinkedList *self, void* value);
  void (*insert)(struct singlyLinkedList *self, void* value, size_t index);
  void* (*getValue)(struct singlyLinkedList *self, size_t index);
  int (*unlink)(struct singlyLinkedList *self, size_t index);
} LinkedList;

LinkedList *newLinkedList();
//void append(LinkedList *list, void* value);
//void push(LinkedList *list, void* value);
//void insert(LinkedList *list, void* value, size_t index);
//void* getValue(LinkedList *list, size_t index);
void printLinkedList(LinkedList *list, char* (*toString)(void*));
size_t linkedLen(Node *head);
//int unlink(LinkedList *list, size_t index);
#endif
