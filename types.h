#ifndef TYPES_H

  #define TYPES_H

  #include <stdint.h>
  #include <stdio.h>
  #include <stdlib.h>
  typedef uint8_t u8;
  typedef uint16_t u16;
  typedef uint32_t u32;
  typedef uint64_t u64;

  typedef int8_t i8;
  typedef int16_t i16;
  typedef int32_t i32;
  typedef int64_t i64;

  typedef enum {
      FAIL = 0,
      SUCCESS = 1
  } Result;

  typedef enum {
      NONE = 0,
      INVALID_ARGUMENT = 1,
      MEMORY_ALLOCATION_FAILED = 2,
      DISK_IO_FAILED = 3,
      NETWORK_IO_FAILED = 4,
      MATH_OPERATION_FAILED = 5
  } ERROR;

  #define DYNAMIC_ARRAY_START_SIZE 256
#endif
