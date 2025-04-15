#pragma once

#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void);
unsigned int getPositiveDimension(const char* prompt);
unsigned int getOperationChoice(int min, int max);
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);