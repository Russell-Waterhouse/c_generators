#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <float.h>

typedef enum Algorithms {
  alg_linked_list,
  alg_none,
} Algorithms;

int is_help_arg(char** argv) {
  const char* help = "--help";
  const char* help_short = "-h";
  return !strncmp(help, argv[1], strlen(help)) || !strncmp(help_short, argv[1], strlen(help_short));
}

void print_help() {
  printf("Usage:\n");
  printf("generate [algorithm] type1 type2 type3...\n");
  printf("Algorithm options:\n");
  printf("  --linked-list\n");
  printf("\n");
  printf("Examples:\n");
  printf("  $ ./generate --linked-list u8 # generates a lined list implementation for 8-bit unsigned integers\n");
}

Algorithms str_to_alg(char* arg) {
  const char* ll = "--linked-list";
  if (!strncmp(ll, arg, strlen(ll))) {
    printf("Generating linked list\n");
    return alg_linked_list;
  }
  return alg_none;
}

int main(int argc, char** argv) {
  if (argc < 2 || (argc == 2 && is_help_arg(argv))) {
    print_help();
    exit(0);
  }
  Algorithms alg = str_to_alg(argv[1]);
  if (alg_none == alg) {
    printf("Unknown option %s", argv[1]);
    exit(-1);
  }

  printf("Unfortunately, you've compiled and ran a version that is incomplete. This program does not yet do anything. Exiting now :)\n");
  exit(0);
}
