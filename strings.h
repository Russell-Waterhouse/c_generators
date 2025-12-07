#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>
#include "./types.h"

typedef struct String {
  size_t size;
  size_t memsize;
  char* str;
} String;

typedef struct DynStringArr {
  size_t memsize;
  size_t size;
  String* arr;
} DynStringArr;

typedef struct SplitResultOption {
  Result status;
  u32 num_strs;
  DynStringArr* strs;
} SplitResultOption;

typedef struct SplitResult {
  u32 num_strs;
  DynStringArr* strs;
} SplitResult;

typedef struct ToU64Result {
  Result status;
  u64 result;
} ToU64Result;

String* cstr_to_str_or_die(char* cstr, u32 size);
void free_str_or_die(String* s);
String* u64_to_str_or_die(u64 v);
SplitResult split_str_or_die(String* s, char split_char);
DynStringArr* insert_back_or_die(DynStringArr* a, String value);
String at_or_die(DynStringArr* a, size_t index);

Result strip_in_place(String* s);
SplitResultOption split_str(String* s, char split_char);
char* to_cstr(String* s);
u32 str_equal(String* s1, String* s2);
ToU64Result str_to_u64(String* s);

#endif /* MY_STRINGS_H */
