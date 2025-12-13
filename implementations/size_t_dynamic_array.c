#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "./size_t_dynamic_array.h"

#define START_SIZE 256


SizeTDynArr size_t_insert_back_or_die(SizeTDynArr a, size_t value) {
  if (a.size >= a.memsize) {
    if (a.memsize == 0) {
      a.memsize = START_SIZE;
    } else {
      a.memsize *= 2;
    }
    a.arr = realloc(a.arr, a.memsize * sizeof(size_t));
    if (a.arr == NULL) {
      printf("Failed to allocate memory for array holder\n");
      exit(-1);
    }
  }

  a.arr[a.size++] = value;

  return a;
}

size_t size_t_at_or_die(SizeTDynArr a, size_t index) {
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

void size_t_free_or_die(SizeTDynArr a) {
  if (NULL == a.arr) {
    puts("Double free on dynamic array of type size_t");
    exit(-1);
  }

  free(a.arr);
  a.arr = NULL;
}
