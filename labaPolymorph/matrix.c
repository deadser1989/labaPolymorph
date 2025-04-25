#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "error.h"

isSuccess createNewMatrix(unsigned int rows, unsigned int cols, const TypeInfo* typeInfo, Matrix* matrix) {
    if (!typeInfo || !matrix || rows == 0 || cols == 0 || !typeInfo->size)
        return ERROR;

    matrix->rows = rows;
    matrix->cols = cols;
    matrix->typeInfo = typeInfo;

    size_t elementSize = typeInfo->size();
    matrix->data = calloc(rows * cols, elementSize);

    if (!matrix->data)
        return ERROR;

    return SUCCESS;
}

void removeInternal(Matrix* matrix) {
    if (!matrix) return;

    if (matrix->data && matrix->typeInfo->destroy) {
        unsigned int total = matrix->rows * matrix->cols;

        for (unsigned int i = 0; i < total; i++) {
            void* element = (char*)matrix->data + i * matrix->typeInfo->size();
            matrix->typeInfo->destroy(element);
        }
    }

    free(matrix->data);
    matrix->data = NULL;
}

isSuccess readMatrixComponents(Matrix* matrix) {
    for (unsigned int i = 0; i < matrix->rows; i++) {
        for (unsigned int j = 0; j < matrix->cols; j++) {
            void* element = (char*)matrix->data + (i * matrix->cols + j) * matrix->typeInfo->size();
            if (matrix->typeInfo->input(element) != SUCCESS) {
                return ERROR;
            }
        }
    }
    return SUCCESS;
}

void printMatrix(const Matrix* matrix) {
    for (unsigned int i = 0; i < matrix->rows; ++i) {
        for (unsigned int j = 0; j < matrix->cols; ++j) {
            void* element = (char*)matrix->data + (i * matrix->cols + j) * matrix->typeInfo->size();
            matrix->typeInfo->print(element);
            printf("\t");
        }
        printf("\n");
    }
}

isSuccess printMatrixElement(const Matrix* matrix, unsigned int row, unsigned int col) {
    if (!matrix || row >= matrix->rows || col >= matrix->cols)
        return ERROR;

    void* element = (char*)matrix->data + (row * matrix->cols + col) * matrix->typeInfo->size();
    matrix->typeInfo->print(element);
    return SUCCESS;
}

isSuccess readMatrixElement(Matrix* matrix, unsigned int row, unsigned int col) {
    if (!matrix || row >= matrix->rows || col >= matrix->cols)
        return ERROR;

    void* element = (char*)matrix->data + (row * matrix->cols + col) * matrix->typeInfo->size();
    return matrix->typeInfo->input(element);
}

isSuccess addMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result) {
    if (!areMatricesSameSize(matrix1, matrix2) || !haveMatchingTypes(matrix1, matrix2))
        return ERROR;

    if (createNewMatrix(matrix1->rows, matrix1->cols, matrix1->typeInfo, result) != SUCCESS)
        return ERROR;

    for (unsigned int i = 0; i < matrix1->rows * matrix1->cols; ++i) {
        void* a = (char*)matrix1->data + i * matrix1->typeInfo->size();
        void* b = (char*)matrix2->data + i * matrix2->typeInfo->size();
        void* r = (char*)result->data + i * result->typeInfo->size();
        result->typeInfo->add(a, b, r);
    }
    return SUCCESS;
}

isSuccess multiplyMatrix(const Matrix* matrix1, const Matrix* matrix2, Matrix* result) {
    if (!areMatricesCompatibleForMultiplication(matrix1, matrix2) || !haveMatchingTypes(matrix1, matrix2))
        return ERROR;

    if (createNewMatrix(matrix1->rows, matrix2->cols, matrix1->typeInfo, result) != SUCCESS)
        return ERROR;

    for (unsigned int i = 0; i < result->rows; ++i) {
        for (unsigned int j = 0; j < result->cols; ++j) {
            void* sum = calloc(1, result->typeInfo->size());
            if (!sum)
                return ERROR;

            for (unsigned int k = 0; k < matrix1->cols; ++k) {
                void* a = (char*)matrix1->data + (i * matrix1->cols + k) * matrix1->typeInfo->size();
                void* b = (char*)matrix2->data + (k * matrix2->cols + j) * matrix2->typeInfo->size();

                void* temp = calloc(1, result->typeInfo->size());
                if (!temp) {
                    free(sum);
                    return ERROR;
                }

                result->typeInfo->multiply(a, b, temp);
                result->typeInfo->add(sum, temp, sum);
                free(temp);
            }

            void* dest = (char*)result->data + (i * result->cols + j) * result->typeInfo->size();
            result->typeInfo->assign(dest, sum);
            free(sum);
        }
    }
    return SUCCESS;
}

isSuccess transposeMatrix(Matrix* matrix) {
    Matrix temp;
    if (createNewMatrix(matrix->cols, matrix->rows, matrix->typeInfo, &temp) != SUCCESS)
        return ERROR;

    for (unsigned int i = 0; i < matrix->rows; ++i) {
        for (unsigned int j = 0; j < matrix->cols; ++j) {
            void* src = (char*)matrix->data + (i * matrix->cols + j) * matrix->typeInfo->size();
            void* dest = (char*)temp.data + (j * matrix->rows + i) * temp.typeInfo->size();
            temp.typeInfo->assign(dest, src);
        }
    }

    removeInternal(matrix);
    *matrix = temp;
    return SUCCESS;
}
