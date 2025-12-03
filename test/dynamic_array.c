#include <stdlib.h>
#include <stdio.h>
#include "../templates/dynamic_array.c"
#include "../types.h"

Result test_insert_back_when_empty() {
    DynArr* arr = insert_back(NULL, 100);
    if (arr->memsize == START_SIZE && arr->size == 1 && arr->arr[0] == 100) {
        return SUCCESS;
    }

    return FAIL;
}

int main() {
    puts("Starting dynamic array tests.");
    if (test_insert_back_when_empty() == SUCCESS) {
        puts("Tests completed successfully!");
        exit(0);
    }


    puts("There were test failures.");
    exit(0);
}
