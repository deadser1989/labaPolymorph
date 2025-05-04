#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "complex.h"
#include "input.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void printMainMenu(void) {
    printf("\n========================================\n");
    printf("          Matrix Calculator           \n");
    printf("========================================\n");
    printf("1. Add matrices\n");
    printf("2. Multiply matrices\n");
    printf("3. Transpose matrix\n");
    printf("4. Exit\n");
    printf("========================================\n");
}


void determineMatrixType(Matrix* matrix) {
    printf("\nSelect matrix element type:\n");
    printf("1. Integer\n");
    printf("2. Double\n");
    printf("3. Complex\n");
    matrix->typeInfo = NULL;

    while (!matrix->typeInfo) {
        int typeChoice = getOperationChoice("Select type (1-3): ", 1, 3);
        switch (typeChoice) {
        case 1: matrix->typeInfo = getTypeInfoInteger(); break;
        case 2: matrix->typeInfo = getTypeInfoDouble(); break;
        case 3: matrix->typeInfo = getTypeInfoComplex(); break;
        }
    }
}

int readMatrixWithRetry(Matrix* matrix, const char* name) {
    while (1) {
        printf("\nEnter elements for matrix %s row-wise:\n", name);
        ErrorCode err = readMatrixComponents(matrix);
        if (err == ERROR_NONE) return 1;
        printf("Error: %s\n", getErrorMessage(err));
        clearInputBuffer();
    }
}

void handleMatrixAddition() {
    Matrix A, B, result;
    ErrorCode err;

    printf("\n=== Matrix Addition ===\n");
    inputMatrixDimensions(&A.rows, &A.cols);
    determineMatrixType(&A);
    createNewMatrix(A.rows, A.cols, A.typeInfo, &A);
    readMatrixWithRetry(&A, "A");

    inputMatrixDimensions(&B.rows, &B.cols);
    B.typeInfo = A.typeInfo;
    createNewMatrix(B.rows, B.cols, B.typeInfo, &B);
    readMatrixWithRetry(&B, "B");

    if ((err = addMatrix(&A, &B, &result)) == ERROR_NONE) {
        printf("\nResult:\n");
        printMatrix(&result);
    }
    else {
        printf("Error: %s\n", getErrorMessage(err));
    }

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void handleMatrixMultiplication() {
    Matrix A, B, result;
    ErrorCode err;

    printf("\n=== Matrix Multiplication ===\n");
    inputMatrixDimensions(&A.rows, &A.cols);
    determineMatrixType(&A);
    createNewMatrix(A.rows, A.cols, A.typeInfo, &A);
    readMatrixWithRetry(&A, "A");

    printf("\nMatrix B (rows must be %u):\n", A.cols);
    inputMatrixDimensions(&B.rows, &B.cols);
    B.typeInfo = A.typeInfo;
    createNewMatrix(B.rows, B.cols, B.typeInfo, &B);
    readMatrixWithRetry(&B, "B");

    if ((err = multiplyMatrix(&A, &B, &result)) == ERROR_NONE) {
        printf("\nResult:\n");
        printMatrix(&result);
    }
    else {
        printf("Error: %s\n", getErrorMessage(err));
    }

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void handleMatrixTransposition() {
    Matrix A;
    printf("\n=== Matrix Transposition ===\n");
    inputMatrixDimensions(&A.rows, &A.cols);
    determineMatrixType(&A);
    createNewMatrix(A.rows, A.cols, A.typeInfo, &A);
    readMatrixWithRetry(&A, "A");

    if (transposeMatrix(&A) == ERROR_NONE) {
        printf("\nTransposed matrix:\n");
        printMatrix(&A);
    }
    else {
        printf("Transposition failed.\n");
    }

    removeInternal(&A);
}