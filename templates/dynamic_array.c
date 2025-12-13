#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../types.h"

#define START_SIZE 256

typedef i32 GENERIC_TYPE;

typedef struct {
  size_t size;
  size_t memsize;
  GENERIC_TYPE* arr;
} DynArr;

DynArr GENERIC_TYPE_insert_back_or_die(DynArr a, GENERIC_TYPE value) {
  if (a.size >= a.memsize) {
    if (a.memsize == 0) {
      a.memsize = START_SIZE;
    } else {
      a.memsize *= 2;
    }
    a.arr = realloc(a.arr, a.memsize * sizeof(GENERIC_TYPE));
    if (a.arr == NULL) {
      printf("Failed to allocate memory for array holder\n");
      exit(-1);
    }
  }

  a.arr[a.size++] = value;

  return a;
}

GENERIC_TYPE GENERIC_TYPE_at_or_die(DynArr a, size_t index) {
  if (a.arr == NULL) {
    printf("Passed a null dynamic array to the 'at' function. Exiting the program.");
    exit(-1);
  }
  if (index >= a.size) {
    printf("Attempted to index an array outsize of its size. Exiting the program.");
    /* TODO: print size, line number, index, callstack here. */
    exit(-1);
  }

  return a.arr[index];
}

void GENERIC_TYPE_free_or_die(DynArr a) {
  if (NULL == a.arr) {
    puts("Double free on dynamic array of type GENERIC_TYPE");
    exit(-1);
  }

  free(a.arr);
  a.arr = NULL;
}
