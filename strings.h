#ifndef MY_STIRINGS_H
#define MY_STIRINGS_H

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

String* cstr_to_str_or_die(char* cstr, u32 size);
String* u64_to_str_or_die(u64 v);
Result strip_in_place(String* s);
void free_str_or_die(String* s);
SplitResult split_str_or_die(String* s, char split_char);
SplitResultOption split_str(String* s, char split_char);
String* cstr_to_str_or_die(char* cstr, u32 size) {


endif /* MY_STRINGS_H */