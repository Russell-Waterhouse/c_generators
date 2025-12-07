#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include "./types.h"
#include "./dynamic_string_array.h"

typedef struct String {
  size_t size;
  size_t memsize;
  char* str;
} String;

typedef struct SplitResultOption {
  Result status;
  u32 num_strs;
  DynStringArr* strs;
} SplitResultOption;

typedef struct SplitResult {
  u32 num_strs;
  DynStringArr* strs;
} SplitResult;

String* cstr_to_str_or_die(char* cstr, u32 size);
String* u64_to_str_or_die(u64 v);
Result strip_in_place(String* s);
void free_str_or_die(String* s);
SplitResult split_str_or_die(String* s, char split_char);
SplitResultOption split_str(String* s, char split_char);

endif /* MY_STRINGS_H */