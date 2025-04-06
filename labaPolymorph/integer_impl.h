#pragma once
#include "integer.h"

void intAdd(const void* a, const void* b, void* result);
void intSubstract(const void* a, const void* b, void* res);
void intMultiply(const void* a, const void* b, void* res);

void intAssign(void* destination, const void* source);
void intSwap(void* element1, void* element2);
size_t intGetSize(void);
void intPrint(const void* element);
void freeInteger(void* ptr);

