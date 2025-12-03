#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../types.h"

#define START_SIZE 255

typedef i32 GENERIC_VALUE;

typedef struct DynStringArr {
  size_t memsize;
  size_t size;
  GENERIC_VALUE* arr;
} DynArr;

DynArr* insert_back(DynArr* a, GENERIC_VALUE value) {
  if (a == NULL) {
    a = calloc(1, sizeof *a);
    if (a == NULL) {
      printf("Failed to allocate memory for array holder\n");
      exit(-1);
    }

    a->arr = calloc(START_SIZE, sizeof(GENERIC_VALUE));
    if (!a->arr) {
      printf("Failed to allocate memory for array\n");
      exit(-1);
    }

    a->memsize = START_SIZE;
    a->arr[a->size] = value;
    a->size++;
    return a;
  }

  if (a->size >= a->memsize) {
    size_t new_memsize = a->memsize * 2;
    a = realloc(a, new_memsize);
    if (a == NULL) {
      printf("Failed to allocate memory for array");
      exit(-1);
    }
    a->memsize = new_memsize;
  }
  a->arr[a->size] = value;
  a->size++;
  return a;
}

inline GENERIC_VALUE at(DynArr* a, size_t index) {
  if (a == NULL) {
    printf("Passed a null dynamic array to the 'at' function. Exiting the program.");
    exit(-1);
  }
  if (index >= a->size) {
    printf("Attempted to index an array outsize of its size. Exiting the program.");
    exit(-1);
  }

  return a->arr[index];
}


