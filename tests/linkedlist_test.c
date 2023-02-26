#include <stdio.h>
#include <string.h>

#include "integer.h"
#include "../linkedlist.h"
#include "test.h"

void reverseLinkedList(LinkedList *list);

void singlyLinkedlistTest(void) {
    LinkedList *list = newLinkedList();
    for (int i = 0; i < 10; i++) {
        Integer *num = (Integer *)malloc(sizeof(Integer));
        num->value = i;
        list->append(list, num);
        printLinkedList(list, integerToString);
    }
    Integer eleven = {11};
    list->insert(list, &eleven, 5);
    printLinkedList(list, integerToString);
    list->unlink(list, 0);
    printLinkedList(list, integerToString);
    list->unlink(list, list->size - 1);
    printLinkedList(list, integerToString);
    size_t index = list->size - 1;
    printf("The value at index '%zu' is '%d'\n", index, ((Integer *)list->getValue(list, index))->value);
    printf("Length of linked list: %zu\n", linkedLen(list->head));
    puts("Reversing the list");
    reverseLinkedList(list);
    printLinkedList(list, integerToString);

    puts("Clearing the list");
    while (list->head != NULL) {
        list->unlink(list, list->size - 1);
        printLinkedList(list, integerToString);
    }
}

void reverseLinkedList(LinkedList *list) {
    Node *prev = NULL;
    Node *curr = list->head;
    Node *next = NULL;

    while (curr != NULL) {
        // set next value
        next = curr->next;

        // reverse curr pointer direction
        curr->next = prev;

        // rotate pointers to the next curr
        prev = curr;
        curr = next;
    }
    list->head = prev;
}


