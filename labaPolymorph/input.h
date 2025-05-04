#pragma once
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void);
int getOperationChoice(const char* prompt, int min, int max);
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);