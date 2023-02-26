#include <stdlib.h>
#include "integer.h"

char *integerToString(void* ptr) {
    Integer *integer = (Integer *)ptr;
    char *string = calloc(2, sizeof(char));
    sprintf(string, "%d", integer->value);
    return string;
}
