#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "./types.h"
#include "./strings.h"

Result compile(char* inputs, char* output) {
  char* compile_cmd[] = {
    "gcc --std=c89 -Werror -Wall -Wconversion -I.",
    inputs,
    "-o ",
    output,
  };
  String compile_cmd_str = cstrs_to_str_or_die(compile_cmd);

  free_str(compile_cmd_str);
}


int main() {
  char* build_dir = "build";

  rmdir(build_dir);
  // Permissions: Read/Write/Execute for owner, group, and others (0777)
  // S_IRWXU | S_IRWXG | S_IRWXO is the symbolic equivalent
  mode_t permissions = S_IRWXU | S_IRWXG | S_IRWXO;
  int success = mkdir(build_dir, permissions);


  exit(0);
}
