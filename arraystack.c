#include "stack.h"

// Initialize a stack with the stackSize specified by user
ArrayStack *initStack(size_t n) {
  ArrayStack *stackPtr = (ArrayStack *)calloc(1, sizeof(ArrayStack));
  stackPtr->elements = (int *)calloc(n, sizeof(int));
  stackPtr->maxSize = n;
  stackPtr->top = -1;
  stackPtr->size = 0;
  return stackPtr;
}

int stackPush(ArrayStack *stack, int element) {
  // check if the elements array is full
  if (stack->size >= stack->maxSize) {
    // exit and return error code
    return 0;
  }

  // increment top index (wrap around end of array if needed)
  if (stack->top >= stack->maxSize) {
    // wrap around to the start of array
    stack->top = 0;
  } else {
    // simply increment
    stack->top++;
  }

  // insert element into the stack
  stack->elements[stack->top] = element;
  // increment stackSize index
  stack->size++;
}

int stackPop(ArrayStack *stack) {}

int stackPeek(ArrayStack *stack) {
  if (stack->size == 0) {
    puts("Stack is empty");
    exit(1);
  }
  return stack->elements[stack->top];
}

int stackSize(ArrayStack *stack) { return stack->size; }
int stackClear(ArrayStack *stack) {
  int *oldElements = stack->elements;
  stack->elements = (int *)calloc(stack->maxSize, sizeof(int));
  free(oldElements);
}