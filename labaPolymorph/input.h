#pragma once
#include "error.h"

void clearInputBuffer(void);
int getOperationChoice(const char* prompt, int min, int max);
ErrorCode  inputMatrixDimensions(unsigned int* rows, unsigned int* cols);