#include <stdio.h>
#include <stdlib.h>
#include "../templates/linked_list.c"
#include "../types.h"

Result test_insert() {
  u64 i;
  Node* head = insert_front(NULL, 0);
  for(i = 0; i < 8; i++) {
    head = insert_front(head, i);
  }
  Node* curr = head;
  for(i = 7; i >= 0; i--) {
    if (curr -> value != i) {
      printf("TEST FAIL: %lu != %lu\n", curr -> value, i);
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

void test_ll() {
  puts("Starting Linked Lists tests.");
  if (test_insert() == SUCCESS && test_delete() == SUCCESS) {
    puts("Tests completed Linked Lists successfully!");
    return;
  }
  puts("There were test failures.");
  return;
}

