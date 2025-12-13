#include <stdlib.h>
#include <stdio.h>
#include "../templates/dynamic_array.h"
#include "../types.h"

#define one_million 1000000
#define expected_memsize 0b01 << 20

Result test_insert_back_when_empty() {
  GENERIC_TYPEDynArr arr = {0};
  arr = GENERIC_TYPE_insert_back_or_die(arr, 100);
  if (arr.memsize == DYNAMIC_ARRAY_START_SIZE && arr.size == 1 && arr.arr[0] == 100) {
    GENERIC_TYPE_free(arr);
    return SUCCESS;
  }

  GENERIC_TYPE_free(arr);
  return FAIL;
}

Result test_resizing() {
  GENERIC_TYPEDynArr a = {0};
  u64 i;
  for (i = 0; i < one_million; i++) {
    GENERIC_TYPE_insert_back_or_die(a, i);
  }
  if (a.memsize == expected_memsize && a.size == one_million) {
    for (i = 0; i < one_million; i++) {
      if (GENERIC_TYPE_at_or_die(a, i) != i) {
        GENERIC_TYPE_free(a);
        return FAIL;
      }
    }

    GENERIC_TYPE_free(a);
    return SUCCESS;
  } else {
    GENERIC_TYPE_free(a);
    return FAIL;
  }
}

int main() {
  puts("Starting dynamic array tests.");
  if (
      test_insert_back_when_empty() == SUCCESS &&
      test_resizing() == SUCCESS
  ) {
    puts("Tests completed successfully!");
    exit(0);
  }


  puts("There were test failures.");
  exit(0);
}
