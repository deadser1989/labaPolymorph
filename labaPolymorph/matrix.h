#pragma once

#include "typeInfo.h"

typedef struct Matrix {
    unsigned int rows;
    unsigned int cols;
    void* data;
    const TypeInfo* typeInfo;
} Matrix;

isSuccess addMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result);
isSuccess multiplyMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result);
isSuccess transposeMatrix(Matrix* matrix);
isSuccess readMatrixComponents(Matrix* matrix);

isSuccess printMatrixElement(const Matrix* matrix, unsigned int row, unsigned int col);
isSuccess readMatrixElement(Matrix* matrix, unsigned int row, unsigned int col);

isSuccess createNewMatrix(unsigned int rows, unsigned int cols, const TypeInfo* typeInfo, Matrix* matrix);
void printMatrix(const Matrix* matrix);
void removeInternal(Matrix* matrix);
