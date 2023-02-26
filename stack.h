#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *elements;
  int size;
  size_t top;
  size_t maxSize;
} ArrayStack;

ArrayStack *initStack(size_t n);
int stackPush(ArrayStack *stack, int element);
int stackPop(ArrayStack *stack);
int stackPeek(ArrayStack *stack);
int stackSize(ArrayStack *stack);
int stackClear(ArrayStack *stack);

#endif