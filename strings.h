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
  String slice;
} SliceResult;

typedef struct {
  Result status;
  String str;
  Error err;
} StrResult;

typedef struct {
  Result status;
  DynStringArr dyn_arr;
  Error err;
} DynStrArrResult;


/* save optional/result type functions */
String str_at(DynStringArr a, size_t index);
StrResult u64_to_str(u64 v);
StrResult concat(String s1, String s2);
DynStrArrResult insert_back(DynStringArr a, String value);
StrResult cstr_to_str(char* cstr, u64 size);
StrResult cstrs_to_str_unsafe(char** cstr);
ActionResult free_str(String s);
SliceResult slice(String s1, u64 start, u64 end);
SplitResultOption split_str(String s, char split_char);
u8 str_equal(String s1, String s2);
u64Result str_to_u64(String s);
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
