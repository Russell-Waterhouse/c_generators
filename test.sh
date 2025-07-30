#!/bin/bash
gcc --std=c11 -Werror -Wall ./test/test_linked_list.c -I. -o test_ll && ./test_ll
gcc --std=c11 -Werror -Wall ./test/test_hashmap.c -I. -o test_hashmap && ./test_hashmap
