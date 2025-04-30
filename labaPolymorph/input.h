#pragma once

#include <stdio.h>
#include <stdlib.h>
extern void clearInputBuffer(void);
unsigned int getPositiveDimension(const char* prompt);
unsigned int getOperationChoice(unsigned min, unsigned max);
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);