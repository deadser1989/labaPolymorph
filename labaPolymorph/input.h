#pragma once

#include "typeinfo.h"

void clearInputBuffer(void);
unsigned int getPositiveDimension(const char* prompt);
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);
isSuccess inputValue(void* destination, const TypeInfo* typeInfo);