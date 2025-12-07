#ifndef DYNAMIC_STRING_AREAY_H
#define DYNAMIC_STRING_AREAY_H

#include "./strings.h
#include "./types.h"
#include "./dynamic_string_array.h"

typedef struct DynStringArr {
  size_t memsize;
  size_t size;
  String* arr;
} DynStringArr;

DynStringArr* insert_back_or_die(DynStringArr* a, String value);
String at_or_die(DynStringArr* a, size_t index);

#endif