#pragma once

#include <stdbool.h>
#include "matrix.h"

bool isNullMatrix(const Matrix* matrix);

bool areMatricesSameSize(const Matrix* matrix1, const Matrix* matrix2);

bool areMatricesCompatibleForMultiplication(const Matrix* matrix1, const Matrix* matrix2);

bool haveMatchingTypes(const Matrix* matrix1, const Matrix* matrix2);

bool isValidRowOperation(const Matrix* matrix, unsigned int targetRow, const unsigned int* sourceRows, unsigned int sourceCount);
