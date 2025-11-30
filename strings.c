// I wrote this on my phone in a hotel room, idk if it works
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "./types.h"

typedef struct String {
  size_t size;
  size_t memsize;
  char str[];
} String;

String* cstr_to_str(char* cstr, u32 size) {
    u32 i;
    String* s = calloc(1, sizeof *String);
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
