#pragma once
#include "matrix.h"
#include "error.h"
#include "input.h"

void printMainMenu(void);
void handleMatrixAddition(void);
void handleMatrixMultiplication(void);
void handleMatrixTransposition(void);
void determineMatrixType(Matrix* matrix);
int readMatrixWithRetry(Matrix* matrix, const char* name);