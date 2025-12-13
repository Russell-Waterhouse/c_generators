#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../strings.h"
#include "../types.h"

Result test_cstr_to_str_or_die() {
  char s1[] = "";
  char s2[] = "This is a string";
  char s3[] = "This is another string";
  String s = cstr_to_str_or_die(s1, strlen(s1));
  if (s.size != 0 || s.memsize != 0) {
    printf("case 1 failed; size: %ld; memsize: %ld;\n", s.size, s.memsize);
    return FAIL;
  }
  free_str_or_die(s);

  s = cstr_to_str_or_die(s2, strlen(s2));
  if (s.size != 16 || s.memsize != 16 || !strcmp(s1, s.str)) {
    printf("case 2 failed; size: %ld, memsize: %ld, string: %s\n",s.size, s.memsize, s.str);
    return FAIL;
  }
  free_str_or_die(s);

  s = cstr_to_str_or_die(s3, strlen(s3));
  if (s.size != 22 || s.memsize != 22 || !strcmp(s2, s.str)) {
    printf("case 3 failed\n");
    return FAIL;
  }
  free_str_or_die(s);

  return SUCCESS;
}

Result test_equal() {
  return SUCCESS;
}

Result test_split() {
  String s1 = cstr_to_str_or_die("2000-01-99", strlen("2000-01-99"));
  String e1 = cstr_to_str_or_die("2000", strlen("2000"));
  String e2 = cstr_to_str_or_die("01", strlen("01"));
  String e3 = cstr_to_str_or_die("99", strlen("99"));
  SplitResultOption split_strings = split_str(s1, '-');
  String r1 = split_strings.strs.arr[0];
  String r2 = split_strings.strs.arr[1];
  String r3 = split_strings.strs.arr[2];

  if (
    split_strings.status == SUCCESS &&
    split_strings.strs.size == 3 &&
    str_equal(e1, r1) &&
    str_equal(e2, r2) &&
    str_equal(e3, r3)
  ) {
    return SUCCESS;
  }
  return FAIL;
}

int main() {
  puts("Starting string tests.");
  if (
      test_cstr_to_str_or_die() == SUCCESS &&
      test_equal() == SUCCESS &&
      test_split() == SUCCESS
  ) {
    puts("Tests completed successfully!");
    exit(0);
  }


  puts("There were test failures.");
  exit(1);
}
