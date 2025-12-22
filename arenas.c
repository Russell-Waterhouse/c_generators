#include "./arenas.h"
#include "types.h"
#include <stdlib.h>

Result arena_create(Arena* arena, size_t len) {
  arena->start_position = malloc(len);
  if (NULL == arena->start_position) {
    return FAIL;
  }
  arena->current_position = arena->start_position;
  arena->len = len;

  return SUCCESS;
}

PointerResult arena_push(Arena* arena, size_t size) {
  PointerResult p;
  if (arena->len == 0 || arena->start_position == NULL) {
    p.status = FAIL;
    p.val.err.err_code = INVALID_ARG;
    p.val.err.err_msg = "Passed a null arena to arena_push";
    return p;
  }

  /* TODO: Alignment */
  void* aligned_current_pos = arena->current_position;

  void* new_pos = aligned_current_pos + size;

  if (new_pos >= arena->current_position + arena->len) {
    p.status = FAIL;
    p.val.err.err_code = MEM_ALLOC_FAIL;
    p.val.err.err_msg = "Overran arena allocator";
    return p;
  }
  arena->current_position = new_pos;

  p.status = SUCCESS;
  p.val.res = (u8*)aligned_current_pos;

  return p;
}

Result arena_free(Arena* arena) {
  if (NULL == arena->start_position) {
    return FAIL;
  }
  free(arena->start_position);
  return SUCCESS;
}

