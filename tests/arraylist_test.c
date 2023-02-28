#include <stdio.h>
#include "test.h"
#include "integer.h"
#include "../arraylist.h"

void arraylistTest() {
    ArrayList *list = newArrayList(10, sizeof(Integer *));
    for (int i = 0; i < 20; i++) {
        Integer *num = malloc(sizeof(Integer));
        num->value = i;
        //list->add(list, num);
        list->insert(list, num, list->size);
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
    /*
    list->toString(list, integerToString);
    Integer *ninety_nine = malloc(sizeof(Integer));
    ninety_nine->value = 99;
    list->insert(list, ninety_nine, 9);
    list->toString(list, integerToString);
    //list->insert(list, ninety_nine, 15);
    list->insert(list, ninety_nine, 1);
    list->toString(list, integerToString);
    list->insert(list,ninety_nine, list->size);
    list->toString(list, integerToString);
    printf("size: %zu\n", list->size);
    */ }
