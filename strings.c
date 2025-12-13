#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include "./types.h"
#include "./strings.h"
#include "./implementations/size_t_dynamic_array.h"

#define START_SIZE 255

String cstr_to_str_or_die(char* cstr, u32 size) {
  String s = {0};
  u32 i;

  s.str = (char*)calloc(size, sizeof(char));
  if (NULL == s.str) {
    printf("failed to allocate memory for cstr arr\n");
    exit(-1);
  }

  for(i = 0; i < size; i++) {
    s.str[i] = cstr[i];
  }

  s.size = size;
  s.memsize = size;

  return s;
}

void free_str_or_die(String s) {
  if (NULL == s.str) {
    printf("Double free attempt\n");
    exit(-1);
  }
  free(s.str);
}

char* to_cstr_or_die(String s) {
  u32 i;
  char* cstr = calloc(sizeof(char), s.size + 1);
  if (NULL == cstr) {
    puts("Failed to allocate memory for cstr");
    exit(-1);
  }

  for (i = 0; i < s.size; i++) {
    cstr[i] = s.str[i];
  }
  cstr[s.size] = '\0';
  return cstr;
}


u32 str_equal(String s, String s2) {
  u32 i;
  if (s.size != s2.size) {
    return 0;
  }
  for(i = 0; i < s.size; i++) {
    if (s.str[i] != s2.str[i]) {
      return 0;
    }
  }
  return 1;
}

char char_at_or_die(String s, u32 idx) {
  if (s.size < idx) {
    printf("accessing char_at with invalid index %d", idx);
    exit(-1);
  }

  return s.str[idx];
}

String concat_or_die(String s1, String s2) {
  u32 i, j;
  String s = {0};
  u32 size;
  if (NULL == s1.str || NULL == s2.str) {
    printf("Called concat with null string(s)\n");
    exit(-1);
  }
  size = s1.size + s2.size;


  s.str = calloc(size, sizeof(char));
  if (NULL == s.str) {
    printf("failed to allocate memory for concatenated arr\n");
    exit(-1);
  }

  for(i = 0; i < s1.size; i++) {
    s.str[i] = s1.str[i];
  }
  for(j = 0; j < s2.size; j++, i++) {
    s.str[i] = s2.str[j];
  }

  return s;
}

u8 ends_with(String s, String search_str) {
  size_t i;
  if (NULL == s.str || NULL == search_str.str) {
    return 0;
  }

  if (search_str.size > s.size) {
    return 0;
  }

  for (i = search_str.size; i > 0; i--) {
    if (search_str.str[i] != s.str[i]) {
      return 0;
    }
  }

  return 1;
}

u8 starts_with(String s, String search_str) {
  size_t i;
  if (NULL == s.str || NULL == search_str.str) {
    return 0;
  }

  if (search_str.size > s.size) {
    return 0;
  }

  for (i = 0; i > search_str.size; i++) {
    if (search_str.str[i] != s.str[i]) {
      return 0;
    }
  }

  return 1;
}

/* substring search returning the index of the first result
 * in a string, or -1 if the search_str was not found in s.
 * Uses the Knuth–Morris–Pratt (KMP) algorithm.
 */
i64 first_index_of(String s, String search_str) {
  /*size_t m, i; */
  SizeTDynArr t = {0};
  t = size_t_insert_back_or_die(t, -1);

  printf("size of t is now %zu", t.size);
  return -1;
}

/* substring search returning an array of indexes to all substring matches
 * in a string, or -1 if the search_str was not found in s.
 * Uses the Knuth–Morris–Pratt (KMP) algorithm.
 */
SizeTDynArr indexes_of(String s, String search_str) {
  size_t m, i;
  SizeTDynArr t = {0};
}

u32 replace_first(String s, String search_str, String replacement_str);
u32 replace_all(String s, String search_str, String replacement_str);


SliceResult slice(String s, u32 start, u32 end) {
  SliceResult res;
  u32 i;
  u32 size;
  String slice = {0};

  if (start > end || NULL == s.str) {
    res.status = FAIL;
    return res;
  }
  size = end - start;

  slice.str = (char*)calloc(size, sizeof(char));
  if (NULL == slice.str) {
    puts("Failed to allocate memory for string slice");
    res.status = FAIL;
    return res;
  }

  for(i = 0; i < end - start; i++) {
    slice.str[i] = s.str[i+start];
  }
  slice.size = size;
  slice.memsize = size;
  res.status = SUCCESS;
  res.slice = slice;
  return res;
}

SplitResultOption split_str(String s, char split_char) {
  SplitResultOption res;
  DynStringArr strs = {0};
  u32 i;
  u32 start;

  start = 0;
  for (i = 0; i < s.size; i++) {
    if (s.str[i] == split_char) {
      SliceResult slice_result = slice(s, start, i);
      /* TODO: if sliceresult.status == success, do the rest*/
      strs = insert_back_or_die(strs, slice_result.slice);
      start = i + 1;
    }
  }
  if (start != i) {
      SliceResult slice_result = slice(s, start, i);
      /* TODO: if sliceresult.status == success, do the rest*/
      strs = insert_back_or_die(strs, slice_result.slice);
      start = i + 1;
  }
  res.status = SUCCESS;
  res.strs = strs;
  return res;
}

DynStringArr split_str_or_die(String s, char split_char) {
  DynStringArr strs = {0};
  u32 i;
  u32 start;

  start = 0;
  for (i = 0; i < s.size; i++) {
    if (s.str[i] == split_char) {
      SliceResult slice_result = slice(s, start, i);
      /* TODO: if sliceresult.status == success, do the rest*/
      strs = insert_back_or_die(strs, slice_result.slice);
      start = i + 1;
    }
  }
  if (start != i) {
      SliceResult slice_result = slice(s, start, i);
      /* TODO: if sliceresult.status == success, do the rest*/
      strs = insert_back_or_die(strs, slice_result.slice);
      start = i + 1;
  }
  return strs;
}

String trim(String s);

u32 blank(String s) {
  u32 i;
  if (NULL == s.str) {
    return 1;
  }
  for (i = 0; i < s.size; i++) {
    if (s.str[i] != ' ' && s.str[i] != '\t' && s.str[i] != '\0' && s.str[i] != '\n') {
      return 0;
    }
  }
  return 1;
}

ToU64Result str_to_u64(String s) {
  ToU64Result res;
  u64 result = 0;
  if (NULL == s.str) {
    res.status = FAIL;
    return res;
  }

  u64 i;
  for (i = 0; i < s.size; i++) {
    char c = s.str[i];
    if (c < '0' || c > '9') {
      printf("Failed to parse ascii code %d\n", c);
      res.status = FAIL;
      return res;
    }
    result *= 10;
    result += (c - '0');
  }


  res.status = SUCCESS;
  res.result = result;

  return res;
}


String u64_to_str_or_die(u64 v) {
  /* u32 has a max of 20 digits */
  char str[32];
  sprintf(str, "%lu", v);
  String s = cstr_to_str_or_die(str, strlen(str));

  return s;
}


Result strip_in_place(String s) {
  /* TODO: Finish the rest of this */
  if (s.str[s.size - 1] == '\n') {
    s.size--;
  }

  return SUCCESS;
}

DynStringArr insert_back_or_die(DynStringArr a, String value) {
  if (a.size >= a.memsize) {
    if (a.memsize <= a.size) {
      a.memsize = START_SIZE;
    } else {
      a.memsize *= 2;
    }
    a.arr = realloc(a.arr, a.memsize);
    if (a.arr == NULL) {
      printf("Failed to allocate memory for array");
      exit(-1);
    }
  }

  a.arr[a.size++] = value;
  return a;
}

String at_or_die(DynStringArr a, size_t index) {
  if (index >= a.size) {
    printf("Attempted to index an array outsize of its size. Exiting the program.");
    exit(-1);
  }

  return a.arr[index];
}
