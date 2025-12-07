#include "./strings.h
#include "./types.h"
#include "./dynamic_string_array.h"

DynStringArr* insert_back_or_die(DynStringArr* a, String value) {
  if (a == NULL) {
    a = calloc(1, sizeof *a);
    if (a == NULL) {
      printf("Failed to allocate memory for array holder\n");
      exit(-1);
    }

    a->arr = calloc(START_SIZE, sizeof(String));
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

String at_or_die(DynStringArr* a, size_t index) {
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
