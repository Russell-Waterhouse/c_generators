#!/bin/bash
rm -f ./test_ll && gcc --std=c89 -Werror -Wall ./test/linked_list.c -I. -o test_ll && ./test_ll
rm -f ./test_hashmap && gcc --std=c89 -Werror -Wall ./test/hashmap.c -I. -o test_hashmap && ./test_hashmap
rm -f ./test_dynamic_array && gcc --std=c89 -Werror -Wall ./test/dynamic_array.c -I. -o test_dynamic_array && ./test_hashmap
rm -f ./test_string && gcc --std=c89 -Werror -Wall ./test/strings.c -I. -o test_strings && ./test_strings
