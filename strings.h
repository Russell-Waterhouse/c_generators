#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>
#include "./types.h"

typedef struct {
  size_t size;
  size_t memsize;
  char* str;
} String;

typedef struct {
  size_t memsize;
  size_t size;
  String* arr;
} DynStringArr;

typedef struct {
  Result status;
  DynStringArr strs;
} SplitResultOption;

typedef struct {
  Result status;
  u64 result;
} ToU64Result;

typedef struct {
  Result status;
  String slice;
} SliceResult;

/* _or_die functions */
String cstr_to_str_or_die(char* cstr, u32 size);
void free_str_or_die(String s);
char char_at_or_die(String s, u32 idx);
String u64_to_str_or_die(u64 v);
String concat_or_die(String s1, String s2);
DynStringArr split_str_or_die(String s, char split_char);
DynStringArr insert_back_or_die(DynStringArr a, String value);
String at_or_die(DynStringArr a, size_t index);
char* to_cstr_or_die(String s);

/* save optional/result type functions */
SliceResult slice(String s1, u32 start, u32 end);
SplitResultOption split_str(String s, char split_char);
u32 str_equal(String s1, String s2);
ToU64Result str_to_u64(String s);
String trim(String s);
u32 blank(String s);
i64 index_of(String s1, String search_str);
u8 ends_with(String s1, String search_str);
u8 starts_with(String s1, String search_str);

/* not yet implemented functions */
u32 replace_first(String s1, String search_str, String replacement_str);
u32 replace_all(String s1, String search_str, String replacement_str);

/* _in_place functions */
Result strip_in_place(String s);

#endif /* MY_STRINGS_H */
