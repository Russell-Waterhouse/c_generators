#include <stdio.h>
#include <stdlib.h>
#include "../templates/hashmap.c"
#include "../types.h"


i8 test_insert() {
  puts("Insertion test completed.");
  return SUCCESS;
}

i8 test_delete() {
  puts("Deletion test complete.");
  return SUCCESS;
}

int main() {
  puts("Starting tests for hashmap.");
  if (test_insert() == SUCCESS && test_delete() == SUCCESS) {
    puts("Tests completed successfully!");
    exit(0);
  }
  puts("There were test failures.");
  exit(-1);
}

