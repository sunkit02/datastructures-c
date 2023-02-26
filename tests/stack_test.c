#include <stdio.h>

#include "../stack.h"
#include "test.h"

void printStack(ArrayStack *stack);

void arrayStackTest(void) {
  ArrayStack *stack = initStack(10);
  printStack(stack);
  for (int i = 0; i < 11; i++) {
    if (!stackPush(stack, i)) {
      puts("Stack overflow");
      break;
    }
    printStack(stack);
    printf("%d\n", stackPeek(stack));
  }
}

void printStack(ArrayStack *stack) {
  printf("%s", "[");
  size_t k = 0;
  size_t i = 0;
  while (k < stack->size) {
    printf("%d", stack->elements[i++]);
    if (i >= stack->maxSize) {
      i = 0;
    }
    if (k < stack->size - 1) {
      printf("%s", ", ");
    }
    k++;
  }
  printf("%s\n", "]");
}