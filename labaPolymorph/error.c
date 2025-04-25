#include "error.h"
#include <stdio.h>

bool isNullMatrix(const Matrix* matrix) {
    if (matrix == NULL) {
        printf("Error: matrix pointer is NULL.\n");
        return true;
    }
    if (matrix->data == NULL) {
        printf("Error: matrix data is NULL.\n");
        return true;
    }
    if (matrix->typeInfo == NULL) {
        printf("Error: matrix typeInfo is NULL.\n");
        return true;
    }
    return false;
}

bool areMatricesSameSize(const Matrix* matrix1, const Matrix* matrix2) {
    if (isNullMatrix(matrix1) || isNullMatrix(matrix2)) {
        printf("Error: one or both matrices are NULL.\n");
        return false;
    }
    if (matrix1->rows != matrix2->rows || matrix1->cols != matrix2->cols) {
        printf("Error: matrices have different sizes (%ux%u vs %ux%u).\n",
            matrix1->rows, matrix1->cols, matrix2->rows, matrix2->cols);
        return false;
    }
    return true;
}

bool areMatricesCompatibleForMultiplication(const Matrix* matrix1, const Matrix* matrix2) {
    if (isNullMatrix(matrix1) || isNullMatrix(matrix2)) {
        printf("Error: one or both matrices are NULL.\n");
        return false;
    }
    if (matrix1->cols != matrix2->rows) {
        printf("Error: incompatible dimensions for multiplication (%u cols vs %u rows).\n",
            matrix1->cols, matrix2->rows);
        return false;
    }
    return true;
}

bool haveMatchingTypes(const Matrix* matrix1, const Matrix* matrix2) {
    if (isNullMatrix(matrix1) || isNullMatrix(matrix2)) {
        printf("Error: one or both matrices are NULL.\n");
        return false;
    }
    if (matrix1->typeInfo != matrix2->typeInfo) {
        printf("Error: matrices have different types.\n");
        return false;
    }
    return true;
}

bool isValidRowOperation(const Matrix* matrix, unsigned int targetRow, const unsigned int* sourceRows, unsigned int sourceCount) {
    if (isNullMatrix(matrix)) {
        printf("Error: matrix is NULL or invalid.\n");
        return false;
    }

    if (sourceRows == NULL) {
        printf("Error: source row array is NULL.\n");
        return false;
    }

    if (sourceCount == 0) {
        printf("Error: source row count is zero.\n");
        return false;
    }

    if (targetRow >= matrix->rows) {
        printf("Error: target row index %u out of bounds (max %u).\n", targetRow, matrix->rows - 1);
        return false;
    }

    for (unsigned int i = 0; i < sourceCount; i++) {
        if (sourceRows[i] >= matrix->rows) {
            printf("Error: source row index %u out of bounds (max %u).\n", sourceRows[i], matrix->rows - 1);
            return false;
        }
        if (sourceRows[i] == targetRow) {
            printf("Error: source row %u is the same as target row %u.\n", sourceRows[i], targetRow);
            return false;
        }
    }

    return true;
}
