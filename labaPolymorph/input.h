#pragma once

#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void);
unsigned int getPositiveDimension(const char* prompt);
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);