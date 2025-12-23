#!/bin/bash
set -e

rm -f ./test_ll && gcc --std=c89 -Werror -Wall ./test/linked_list.c -I. -o test_ll && ./test_ll
rm -f ./test_hashmap && gcc --std=c89 -Werror -Wall ./test/hashmap.c -I. -o test_hashmap && ./test_hashmap

# Testing dynamic array
rm -f ./test_dynamic_array

gcc \
  --std=c89 \
  -Werror \
  -Wall \
  -Wconversion \
  ./test/dynamic_array.c \
  ./templates/dynamic_array.c \
  ./utils.c \
  -I. \
  -o \
  test_dynamic_array

./test_hashmap

# Testing strings
rm -f ./test_string

gcc \
  --std=c89 \
  -Werror \
  -Wall \
  -Wconversion \
  ./test/strings.c \
  ./strings.c \
  ./implementations/*.c \
  ./utils.c \
  -I. \
  -o \
  test_strings

./test_strings


# Testing strings
rm -f ./test_arenas

gcc \
  --std=c89 \
  -Werror \
  -Wall \
  -Wconversion \
  ./test/arenas.c \
  ./arenas.c \
  -I. \
  -o \
  test_arenas

./test_arenas
