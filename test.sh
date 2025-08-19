#!/bin/bash
gcc --std=c11 -Werror -Wall ./test/linked_list.c -I. -o test_ll && ./test_ll
gcc --std=c11 -Werror -Wall ./test/hashmap.c -I. -o test_hashmap && ./test_hashmap
gcc --std=c11 -Werror -Wall ./test/dynamic_array.c -I. -o test_dynamic_array && ./test_hashmap
