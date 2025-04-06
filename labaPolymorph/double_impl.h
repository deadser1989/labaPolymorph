#pragma once

#include "typeInfo.h"


void doubleAssign(void* destination, const void* source);
void doubleSwap(void* element1, void* element2);
size_t doubleGetSize(void);
void doublePrint(const void* element);
void freeDouble(void* ptr);

const TypeInfo* getTypeInfoDouble(void);