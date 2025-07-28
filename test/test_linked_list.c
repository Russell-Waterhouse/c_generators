#include <stdio.h>
#include <stdlib.h>
#include "../templates/linked_list.c"

#define SUCCESS 1
#define FAIL 0

int test_insert() {
  return SUCCESS;
}
int test_delete() {

  return SUCCESS;
}

int main() {
  printf("Starting tests.\n");
  if (test_insert() == SUCCESS && test_delete() == SUCCESS) {
    printf("Tests completed successfully!\n");
    exit(0);
  }
  printf("There were test failures.\n");
  exit(-1);
}

