#include <stdio.h>
#include <stdlib.h>
#include "../templates/linked_list.c"
#include "../types.h"

Result test_insert() {
  Node* head = insert_front(NULL, 0);
  for(i32 i = 0; i < 8; i++) {
    head = insert_front(head, i);
  }
  Node* curr = head;
  for(i32 i = 7; i >= 0; i--) {
    if (curr -> value != i) {
      printf("TEST FAIL: %d != %d\n", curr -> value, i);
      return FAIL;
    }
    curr = curr -> next;
  }
  puts("Insertion test completed.");
  return SUCCESS;
}

Result test_delete() {
  return SUCCESS;
}

int main() {
  puts("Starting tests.");
  if (test_insert() == SUCCESS && test_delete() == SUCCESS) {
    puts("Tests completed successfully!");
    exit(0);
  }
  puts("There were test failures.");
  exit(-1);
}

