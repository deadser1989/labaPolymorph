#pragma once

typedef struct Matrix Matrix;  

typedef enum {
    ERROR_NONE,
    ERROR_NULL_MATRIX,
    ERROR_NULL_DATA,
    ERROR_NULL_TYPEINFO,
    ERROR_SIZE_MISMATCH,
    ERROR_TYPE_MISMATCH,
    ERROR_INCOMPATIBLE_MULTIPLICATION,
    ERROR_INVALID_ROW_OPERATION
} ErrorCode;

ErrorCode isNullMatrix(const Matrix* matrix);
ErrorCode areMatricesSameSize(const Matrix* matrix1, const Matrix* matrix2);
ErrorCode areMatricesCompatibleForMultiplication(const Matrix* matrix1, const Matrix* matrix2);
ErrorCode haveMatchingTypes(const Matrix* matrix1, const Matrix* matrix2);
ErrorCode isValidRowOperation(const Matrix* matrix, unsigned int targetRow, const unsigned int* sourceRows, unsigned int sourceCount);

const char* getErrorMessage(ErrorCode code);

