#include <stdlib.h>
#include <stdio.h>
#include "../strings.c"
#include "../types.h"

Result test_cstr_to_str() {
  char s1[] = "";
  char s2[] = "This is a string";
  char s3[] = "This is another string";
  String* s = cstr_to_str(s1, strlen(s1));
  if (s->size != 0 || s->memsize != 0) {
    printf("case 1 failed; size: %ld; memsize: %ld;\n", s->size, s->memsize);
    return FAIL;
  }
  free_str(s);

  s = cstr_to_str(s2, strlen(s2));
  if (s->size != 31 || s->memsize != 31 || !strcmp(s1, s->str)) {
    printf("case 2 failed; string: %s\n", s->str);
    return FAIL;
  }
  free_str(s);

  s = cstr_to_str(s3, strlen(s3));
  if (s->size != 36 || s->memsize != 36 || !strcmp(s2, s->str)) {
    printf("case 3 failed\n");
    return FAIL;
  }
  free_str(s);

  return SUCCESS;
}

Result test_equal() {
  return SUCCESS;
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
