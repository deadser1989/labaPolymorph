#pragma once
#include "matrix.h"
#include "error.h"

void printMainMenu();
int getOperationChoice(int min, int max);
void handleMatrixAddition();
void handleMatrixMultiplication();
void handleMatrixTransposition();
void inputMatrixDimensions(unsigned int* rows, unsigned int* cols);
void determineMatrixType(Matrix* matrix);
int readMatrixWithRetry(Matrix* matrix, const char* name);