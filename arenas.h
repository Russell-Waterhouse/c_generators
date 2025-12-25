#ifndef ARENAS_H
#define ARENAS_H

#include <stdlib.h>
#include "./types.h"
typedef struct Arena {
  void* start_position;
  void* current_position;
  size_t len;
  struct Arena* next;
} Arena;

#define ARENA_ALIGN (sizeof(void*))

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

Result arena_create(Arena* arena, size_t size);
PointerResult arena_push(Arena* arena, size_t size);
Result arena_free(Arena* arena);

#endif
