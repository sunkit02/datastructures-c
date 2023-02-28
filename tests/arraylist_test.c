#include <stdio.h>
#include "test.h"
#include "integer.h"
#include "../arraylist.h"


void arraylistTest() {
    ArrayList *list = newArrayList(10, sizeof(Integer *));
    for (int i = 0; i < 20; i++) {
        Integer *num = malloc(sizeof(Integer));
        num->value = i;
        list->add(list, num);
    }
    list->toString(list, integerToString);
    list->remove(list, list->size - 1);
    list->toString(list, integerToString);
    puts("1");
    while (!list->isEmpty(list)) {
        list->remove(list, list->size - 1);
        printf("size: %zu\n", list->size);
    }
    puts("2");
    list->toString(list, integerToString);
}
