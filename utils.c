#include "./types.h"
#include <stdio.h>
#include <stdlib.h>

u64 i64_to_u64_or_die(i64 i) {
  if (i < 0) {
    printf("Attempting to cast negative i64 value %ld to u64\n", i);
    exit(-1);
  }
  return (u64)i;
}

