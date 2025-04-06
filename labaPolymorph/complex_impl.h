#pragma once

#include "complex.h"

typedef struct {
    double real;
    double imag;
} Complex;

void complexAdd(const void* a, const void* b, void* res);
void complexSubstract(const void* a, const void* b, void* res);
void complexMultiply(const void* a, const void* b, void* res);
void complexAssign(void* destination, const void* source);
void complexSwap(void* element1, void* element2);
size_t complexGetSize(void);
void complexPrint(const void* element);
void freeComplex(void* ptr);