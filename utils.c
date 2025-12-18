#include "utils.h"
#include "./types.h"

u64Result i64_to_u64(i64 i) {
  u64Result res;
  if (i < 0) {
    res.status = FAIL;
    res.err.err_code = INVALID_ARG;
    res.err.err_msg = "Attempting to cast negative i64 to u64";
    return res;
  }
  res.res = (u64)i;
  res.status = SUCCESS;
  return res;
}

