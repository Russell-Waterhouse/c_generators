#include <stdlib.h>
#include <stdio.h>
#include "../strings.c"
#include "../types.h"

Result test_cstr_to_str() {
  char s1[] = "";
  char s2[] = "This is a string";
  char s3[] = "This is another string";
  String* s = cstr_to_str(s1, strlen(s1));
  if (s->size != 1 || s->memsize != 1 || !strcmp(s1, s->str)) {
    printf("case 1 failed; size: %ld; memsize: %ld\n", s->size, s->memsize);
    return FAIL;
  }
  free_str(s);

  s = cstr_to_str(s2, strlen(s2));
  if (s->size != 32 || s->memsize != 32 || !strcmp(s1, s->str)) {
    printf("case 2 failed\n");
    return FAIL;
  }
  free_str(s);

  s = cstr_to_str(s3, strlen(s3));
  if (s->size != 37 || s->memsize != 37 || !strcmp(s2, s->str)) {
    printf("case 3 failed\n");
    return FAIL;
  }
  free_str(s);

  return SUCCESS;
}

Result test_equal() {
  return FAIL;
}

int main() {
  puts("Starting string tests.");
  if (
      test_cstr_to_str() == SUCCESS &&
      test_equal() == SUCCESS
  ) {
    puts("Tests completed successfully!");
    exit(0);
  }


  puts("There were test failures.");
  exit(1);
}
