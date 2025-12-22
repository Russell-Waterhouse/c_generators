#ifndef ARENAS_H
#define ARENAS_H

#include <stdlib.h>
#include "./types.h"
typedef struct {
  void* start_position;
  void* current_position;
  size_t len;
} Arena;


#define ARENA_ALIGN (sizeof(void*))

Result arena_create(Arena* arena, size_t size);
PointerResult arena_push(Arena* arena, size_t size);
Result arena_free(Arena* arena);

#endif
