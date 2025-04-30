#pragma once
#include "typeInfo.h"
#include "error.h"

typedef struct Matrix {
    unsigned int rows;
    unsigned int cols;
    void* data;
    const TypeInfo* typeInfo;
} Matrix;

ErrorCode createNewMatrix(unsigned int rows, unsigned int cols, const TypeInfo* typeInfo, Matrix* matrix);
void removeInternal(Matrix* matrix);
ErrorCode readMatrixComponents(Matrix* matrix);
void printMatrix(const Matrix* matrix);
ErrorCode printMatrixElement(const Matrix* matrix, unsigned int row, unsigned int col);
ErrorCode readMatrixElement(Matrix* matrix, unsigned int row, unsigned int col);
ErrorCode addMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result);
ErrorCode multiplyMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result);
ErrorCode transposeMatrix(Matrix* matrix);
