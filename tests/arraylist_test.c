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
    Integer *ninety_nine = malloc(sizeof(Integer));
    ninety_nine->value = 99;
    list->insert(list, ninety_nine, 9);
    printf("size: %zu\n", list->size);

    for (size_t i = 0; i < list->size; i++) {
        printf("list[%zu]=Integer(value=%d)\n", i, ((Integer *)list->get(list, i))->value);
    }


}
