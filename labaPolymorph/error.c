
#include "matrix.h"
#include "error.h"
#include <stdio.h>

ErrorCode isNullMatrix(const Matrix* matrix) {
    if (matrix == NULL) return ERROR_NULL_MATRIX;
    if (matrix->data == NULL) return ERROR_NULL_DATA;
    if (matrix->typeInfo == NULL) return ERROR_NULL_TYPEINFO;
    return ERROR_NONE;
}

ErrorCode areMatricesSameSize(const Matrix* matrix1, const Matrix* matrix2) {
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols)
        return ERROR_SIZE_MISMATCH;
    return ERROR_NONE;
}

ErrorCode areMatricesCompatibleForMultiplication(const Matrix* matrix1, const Matrix* matrix2) {
    if (matrix1->cols != matrix2->rows)
        return ERROR_INCOMPATIBLE_MULTIPLICATION;
    return ERROR_NONE;
}

ErrorCode haveMatchingTypes(const Matrix* matrix1, const Matrix* matrix2) {
    if (matrix1->typeInfo != matrix2->typeInfo)
        return ERROR_TYPE_MISMATCH;
    return ERROR_NONE;
}

ErrorCode isValidRowOperation(const Matrix* matrix, unsigned int targetRow, const unsigned int* sourceRows, unsigned int sourceCount) {
    if (targetRow >= matrix->rows)
        return ERROR_INVALID_ROW_OPERATION;

    for (unsigned int i = 0; i < sourceCount; i++) {
        if (sourceRows[i] >= matrix->rows)
            return ERROR_INVALID_ROW_OPERATION;
    }

    return ERROR_NONE;
}

const char* getErrorMessage(ErrorCode code) {
    switch (code) {
    case ERROR_NONE: return "No error.";
    case ERROR_NULL_MATRIX: return "Matrix pointer is null.";
    case ERROR_NULL_DATA: return "Matrix data is null.";
    case ERROR_NULL_TYPEINFO: return "Matrix typeInfo is null.";
    case ERROR_SIZE_MISMATCH: return "Matrix sizes do not match.";
    case ERROR_TYPE_MISMATCH: return "Matrix types do not match.";
    case ERROR_INCOMPATIBLE_MULTIPLICATION: return "Incompatible sizes for matrix multiplication.";
    case ERROR_INVALID_ROW_OPERATION: return "Invalid row index for row operation.";
    default: return "Unknown error.";
    }
}
