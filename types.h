#ifndef TYPES

  #define TYPES

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
    INVALID_ARG = 1,
    MEM_ALLOC_FAIL = 2,
    IO_DISK_FAIL = 3,
    IO_NETWORK_FAIL = 4,
  } ErrCode;

  typedef struct {
    ErrCode err_code;
    char* err_msg;
  } Error;

  #define DYNAMIC_ARRAY_START_SIZE 256
#endif
