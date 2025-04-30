#include "ui.h"
#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "complex.h"
#include "input.h"
#include "error.h"
#include <stdio.h>
#include <stdlib.h>

void printMainMenu() {
    printf("\n========================================\n");
    printf("          Matrix Calculator           \n");
    printf("========================================\n");
    printf("1. Add matrices\n");
    printf("2. Multiply matrices\n");
    printf("3. Transpose matrix\n");
    printf("4. Exit\n");
    printf("========================================\n");
}

int getOperationChoice(int min, int max) {
    int choice;
    do {
        printf("► Select operation (%d-%d): ", min, max);
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
        }
    } while (choice < min || choice > max);
    return choice;
}

void inputMatrixDimensions(unsigned int* rows, unsigned int* cols) {
    printf("Enter number of rows: ");
    scanf("%u", rows);
    printf("Enter number of columns: ");
    scanf("%u", cols);
}

void determineMatrixType(Matrix* matrix) {
    printf("\nSelect matrix element type:\n");
    printf("1. Integer (e.g., -5, 10)\n");
    printf("2. Double (e.g., 3.14, -2.5)\n");
    printf("3. Complex (e.g., (1.2, -3.4))\n");
    matrix->typeInfo = NULL;

    while (!matrix->typeInfo) {
        int typeChoice = getOperationChoice(1, 3);
        switch (typeChoice) {
        case 1: matrix->typeInfo = getTypeInfoInteger(); break;
        case 2: matrix->typeInfo = getTypeInfoDouble(); break;
        case 3: matrix->typeInfo = getTypeInfoComplex(); break;
        }
    }
}

int readMatrixWithRetry(Matrix* matrix, const char* name) {
    while (1) {
        printf("\n▸ Enter elements for matrix %s row-wise:\n", name);
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

    printf("\nMatrix A:\n");
    inputMatrixDimensions(&A.rows, &A.cols);
    determineMatrixType(&A);
    createNewMatrix(A.rows, A.cols, A.typeInfo, &A);
    readMatrixWithRetry(&A, "A");

    printf("\nMatrix B:\n");
    inputMatrixDimensions(&B.rows, &B.cols);
    B.typeInfo = A.typeInfo;
    createNewMatrix(B.rows, B.cols, B.typeInfo, &B);
    readMatrixWithRetry(&B, "B");

    // Проверка ошибок
    if ((err = haveMatchingTypes(&A, &B)) != ERROR_NONE) {
        printf("Error: %s\n", getErrorMessage(err));
        removeInternal(&A);
        removeInternal(&B);
        return;
    }

    if ((err = areMatricesSameSize(&A, &B)) != ERROR_NONE) {
        printf("Error: %s\n", getErrorMessage(err));
        removeInternal(&A);
        removeInternal(&B);
        return;
    }

    if (addMatrix(&A, &B, &result) == ERROR_NONE) {
        printf("\nResult:\n");
        printMatrix(&result);
    }
    else {
        printf("Addition failed.\n");
    }

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void handleMatrixMultiplication() {
    Matrix A, B, result;
    ErrorCode err;

    printf("\n=== Matrix Multiplication ===\n");

    printf("\nMatrix A:\n");
    inputMatrixDimensions(&A.rows, &A.cols);
    determineMatrixType(&A);
    createNewMatrix(A.rows, A.cols, A.typeInfo, &A);
    readMatrixWithRetry(&A, "A");

    printf("\nMatrix B (rows must be %u):\n", A.cols);
    inputMatrixDimensions(&B.rows, &B.cols);
    B.typeInfo = A.typeInfo;
    createNewMatrix(B.rows, B.cols, B.typeInfo, &B);
    readMatrixWithRetry(&B, "B");

    // Проверка ошибок
    if ((err = haveMatchingTypes(&A, &B)) != ERROR_NONE) {
        printf("Error: %s\n", getErrorMessage(err));
        removeInternal(&A);
        removeInternal(&B);
        return;
    }

    if ((err = areMatricesCompatibleForMultiplication(&A, &B)) != ERROR_NONE) {
        printf("Error: %s\n", getErrorMessage(err));
        removeInternal(&A);
        removeInternal(&B);
        return;
    }

    if (multiplyMatrix(&A, &B, &result) == ERROR_NONE) {
        printf("\nResult:\n");
        printMatrix(&result);
    }
    else {
        printf("Multiplication failed.\n");
    }

    removeInternal(&A);
    removeInternal(&B);
    removeInternal(&result);
}

void handleMatrixTransposition() {
    Matrix A;

    printf("\n=== Matrix Transposition ===\n");

    printf("\nMatrix:\n");
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