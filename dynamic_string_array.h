#ifndef DYNAMIC_STRING_AREAY_H
#define DYNAMIC_STRING_AREAY_H

typedef struct DynStringArr {
  size_t memsize;
  size_t size;
  String* arr;
} DynStringArr;

#endif