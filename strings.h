#ifndef MY_STRINGS_H
#define MY_STRINGS_H

#include <stddef.h>
#include "./types.h"
#include "implementations/size_t_dynamic_array.h"
#include "implementations/i64_dynamic_array.h"

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

typedef struct {
  Result status;
  String str;
  Error err;
} MakeStrResult;

typedef struct {
  Result status;
  Error err;
} ResultFoo;

typedef struct {
  Result status;
  DynStringArr dyn_arr;
  Error err;
} DynStrArrResult;

/* _or_die functions */
MakeStrResult u64_to_str_or_die(u64 v);
String concat_or_die(String s1, String s2);
String at_or_die(DynStringArr a, size_t index);
char* to_cstr_or_die(String s);

/* save optional/result type functions */
DynStrArrResult insert_back(DynStringArr a, String value);
MakeStrResult cstr_to_str(char* cstr, u64 size);
ResultFoo free_str(String s);
SliceResult slice(String s1, u64 start, u64 end);
SplitResultOption split_str(String s, char split_char);
u64 str_equal(String s1, String s2);
ToU64Result str_to_u64(String s);
String trim(String s);
u64 blank(String s);
i64 find_first(String s, String search_str);
i64DynArr make_kmp_fail_table(String w);
SizeTDynArr find_all(String s, String search_str);
u8 ends_with(String s, String search_str);
u8 starts_with(String s, String search_str);

/* not yet implemented functions */
u64 replace_first(String s, String search_str, String replacement_str);
u64 replace_all(String s, String search_str, String replacement_str);

/* _in_place functions */
Result strip_in_place(String s);

#endif /* MY_STRINGS_H */
