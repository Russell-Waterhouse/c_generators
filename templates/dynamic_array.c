// TODO: I didn't do the memory correct here. The array needs to be dynamically sized,
// not a dynamically sized array of DynArr structs.
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "../types.h"

#define START_SIZE 255

typedef i32 T;

typedef struct DynArr {
  size_t memsize;
  size_t size;
  T arr[];
} DynArr;

DynArr* insert_back(DynArr* a, T value) {
  if (a == NULL) {
    a = calloc(sizeof(*a), START_SIZE);
    if (a == NULL) {
      printf("Failed to allocate memory for array");
      exit(-1);
    }

    a->memsize = START_SIZE;
    a->arr[a->size] = value;
    a->size++;
    return a;
  }

  if (a-> size >= a-> memsize) {
    size_t new_memsize = a->memsize * 2;
    a = realloc(a, a->memsize * 2);
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

T at(DynArr* a, size_t index) {
  if (a == NULL) {
    printf("Passed a null dynamic array to the at function. Exiting the program.");
    exit(-1);
  }
  if (index >= a->size) {
    printf("Attempted to index an array outsize of its size. Exiting the program.");
    exit(-1);
  }

  return a->arr[index];
}

