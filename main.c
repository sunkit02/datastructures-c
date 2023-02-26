#include <string.h>
#include <stdio.h>
#include "tests/test.h"

int main(int argc, char *argv[]) {
    char *testOption = argv[1];
    printf("%s\n", testOption);
    if (strcmp("astack", testOption) == 0) {
        arrayStackTest();
    } else if (strcmp("slinkedlist", testOption) == 0) {
        singlyLinkedlistTest();
    } else if (strcmp("arraylist", testOption) == 0) {
        arraylistTest();
    } else if (strcmp("all", testOption) == 0) {
        arrayStackTest();
        singlyLinkedlistTest();
        arraylistTest();
    } else {
        puts("No tests selected");
    }
}
