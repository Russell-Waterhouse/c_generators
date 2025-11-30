// I wrote this on my phone in a hotel room, idk if it compiles or works
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <bool.h>
#include "./types.h"

typedef struct String {
  size_t size;
  size_t memsize;
  char str[];
} String;

String* cstr_to_str(char* cstr, u32 size) {
    u32 i;
    String* s = calloc(1, sizeof String);
    if (!s) {
        printf("failed to allocate memory for cstr");
        exit(-1);
    }
    s->str = calloc(size, sizeof char);
    if (!s->str) {
        printf("failed to allocate memory for cstr arr\n");
        exit(-1);
    }
    for(i = 0; i < size; i++) {
        s->str[i] = cstr[i];
    }
    
    s->size = size;
    s->memsize = size;
    
    return s;
}

void free_str(String* s) {
  if (NULL == s || NULL == s->str) {
    printf("Double free attempt\n");
    exit(-1);
  }
  free(s->str);
  free(s);
}

char* to_cstr(String* s);
bool equal(String* s1, String* s2) {
  u32 i;
  if (NULL == s1 || NULL == s2) {
    return false;
  }
  if (s1->size != s2->size) {
    return false;
  }
  for(i = 0; i < s1->size; i++) {
    if (s1->str[i] != s2->str[i]) {
      return false;
    }
  }
  return true;
}

char char_at(String* s, u32 idx) {
  if (s->size < idx) {
    printf("accessing char_at with invalid index %d", idx) {
    exit(-1);
  }
  
  return s->str[idx];
}

String* concat(String* s1, String* s2) {
    u32 i, j;
    String* s = calloc(1, sizeof String);
    if (!s1 || !s2 || !s1->str || !s2->str) {
      printf("Called concat with null string(s)\n");
      exit(-1);
    }
    
    if (!s) {
        printf("failed to allocate memory for cstr");
        exit(-1);
    }
    
    s->str = calloc(size, sizeof char);
    if (!s->str) {
        printf("failed to allocate memory for cstr arr\n");
        exit(-1);
    }
    
    for(i = 0; i < s1->size; i++) {
        s->str[i] = s1->str[i];
    }
    for(j = 0; j < s2->size; j++, i++) {
        s->str[i] = s2->str[j];
    }
    
    return s;
}

bool ends_with(String* s1, String* search_str);
bool starts_with(String* s1, String* search_str);
bool includes(String* s1, String* search_str);
i32 index_of(String* s1, String* search_str);
bool replace(String* s1, String* search_str, String* replacement_str);
bool replace_all(String* s1, String* search_str, String* replacement_str);
String* slice(String* s1, u32 start, u32 end) {
    /* TODO input validation */
    u32 i;
    String* s = calloc(1, sizeof String);
    if (!s) {
        printf("failed to allocate memory for cstr");
        exit(-1);
    }
    s->str = calloc(size, sizeof char);
    if (!s->str) {
        printf("failed to allocate memory for cstr arr\n");
        exit(-1);
    }
    for(i = 0; i < end - start; i++) {
        s->str[i] = sq->str[i+start];
    }
    s->size = size;
    s->memsuze = size;
    return s;
}

typedef Struct SplitResult {
  u32 num_strs;
  String* strs[];
} SplitResult;

SplitResult* Split(String* s, char split_char);
String* trim(String* s);
inline bool blank(String* s) {
  u32 i;
  if (NULL == s || NULL == s->str) {
    return true;
  }
  for (i = 0; i < s->size; i++) {
    /* TODO OTHER WHITESPACE */
    if (s->str[i] != ' ' && s->str[i] != '\t') {
      return true;
    }
  }
  return false;
}
