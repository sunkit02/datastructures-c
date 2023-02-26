#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"


// ensures that the index given is not out of bounds
void validateIndex(const LinkedList *list, size_t index) {
  if (index >= list->size) {
    fprintf(stderr, "Index out of bounds. Max: %zu, Given: %zu\n",
            list->size - 1, index);
    exit(1);
  }
}

// appends a new node to the end of the given linked list
void append(LinkedList *list, void* value) {
  // handle empty linked list
  if (list->size == 0) {
    Node *new = (Node *)malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;

    list->head = new;
    list->size++;
    return;
  }

  // get pointer to head node and iterate to end of list
  Node *itr = list->head;
  while (itr->next != NULL) {
    itr = itr->next;
  }

  // allocate memory and initialize new node
  Node *new = (Node *)malloc(sizeof(Node));
  new->value = value;
  new->next = NULL;
  // append new node to end of list
  itr->next = new;
  // increment list stackSize
  list->size++;
}

// makes the newNode the new head to a linked list
void push(LinkedList *list, void* value) {
  // get pointer to head
  Node *headPtr = list->head;
  // allocate memory and create new node
  Node *newNodePtr = (Node *)malloc(sizeof(Node));
  newNodePtr->value = value;
  newNodePtr->next = headPtr;
  // assign new node to be the head of linked list
  list->head = newNodePtr;
  // increment list stackSize
  list->size++;
}

void insert(LinkedList *list, void* value, size_t index) {
  validateIndex(list, index);

  // check if target index is at the beginning
  // or end of the linked list
  if (index == 0) {
    push(list, value);
    return;
  } else if (index == (list->size - 1)) {
    append(list, value);
    return;
  }

  size_t i = 0;
  Node *itr = list->head;
  while (i < (index - 1)) {
    itr = itr->next;
    i++;
  }
  // get pointer to the next node
  Node *next = itr->next;
  // allocate memory and initialize the new node
  Node *new = (Node *)malloc(sizeof(Node));
  new->value = value;
  new->next = next;
  // insert the node
  itr->next = new;
  // increment list stackSize
  list->size++;
}

// prints out all the values of a given linked list
void printLinkedList(LinkedList *list, char* (*toString)(void*)) {
  Node *head = list->head;
  printf("%s", "[");
  while (head != NULL) {
    printf("%s%s", toString(head->value), head->next ? ", " : "");
    head = head->next;
  }
  printf("%s\n", "]");
}

// get the value stored inside the linked list at the given index
void* getValue(LinkedList *list, size_t index) {
  validateIndex(list, index);

  // iterate through linked list to given index
  size_t i = 0;
  Node *itr = list->head;
  while (i < index) {
    itr = itr->next;
    i++;
  }
  // return value at the given index
  return itr->value;
}

// removes a node at the specified index in the linked list
int unlink(LinkedList *list, size_t index) {
  validateIndex(list, index);

  Node *targetNode = NULL;

  // check if removing head node
  if (index == 0) {
    // set node next to head to be the new head
    targetNode = list->head;
    list->head = targetNode->next;

  } else {
    // Get reference to the head node
    Node *itr = list->head;
    size_t i = 0;  // index to keep track of position

    // find the node right before node to get removed
    while (i < index - 1) {
      itr = itr->next;
      i++;
    }

    // set unlink target node and free its memory
    targetNode = itr->next;
    itr->next = targetNode->next;
  }
  // decrement list stackSize
  list->size--;
  // free the memory for the old head
  free(targetNode);
  // return 1 to indicate successful operation
  return 1;
}

// gets the length of a linked list
size_t linkedLen(Node *head) {
  // increments len for every node
  size_t len = 0;
  while (head != NULL) {
    len++;
    head = head->next;
  }
  return len;
}

LinkedList *newLinkedList() {
  LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
  list->size = 0;
  list->append = append;
  list->push = push;
  list->insert = insert;
  list->getValue = getValue;
  list->unlink = unlink;
  return list;
}
