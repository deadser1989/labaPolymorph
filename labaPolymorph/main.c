#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "integer.h"
#include "double.h"
#include "complex.h"
#include "input.h"
#include "error.h"

void printTypeMenu() {
    printf("\nChoose data type:\n");
    printf("1. Integer\n");
    printf("2. Double\n");
    printf("3. Complex\n");
}

void printOperationMenu() {
    printf("\nChoose operation:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    printf("4. Transpose first matrix\n");
    printf("5. Exit\n");
}

int main() {
    const TypeInfo* type = NULL;

    // Выбор типа
    printTypeMenu();
    unsigned int typeChoice = getOperationChoice(1, 3);

    switch (typeChoice) {
    case 1:
        type = getTypeInfoInteger();
        break;
    case 2:
        type = getTypeInfoDouble();
        break;
    case 3:
        type = getTypeInfoComplex();
        break;
    default:
        printf("Invalid type.\n");
        return 1;
    }

    // Ввод размеров матриц
    unsigned int rows1, cols1;
    printf("\nMatrix A:\n");
    inputMatrixDimensions(&rows1, &cols1);

    unsigned int rows2, cols2;
    printf("\nMatrix B:\n");
    inputMatrixDimensions(&rows2, &cols2);

    // Создание и ввод матриц
    Matrix* A = createNewMatrix(rows1, cols1, type);
    Matrix* B = createNewMatrix(rows2, cols2, type);

    printf("\nEnter elements for Matrix A:\n");
    readMatrixComponents(A);

    printf("\nEnter elements for Matrix B:\n");
    readMatrixComponents(B);

    int running = 1;
    while (running) {
        printOperationMenu();
        unsigned int op = getOperationChoice(1, 5);

        Matrix* result = NULL;

        switch (op) {
        case 1:
            if (!areMatricesSameSize(A, B)) {
                printError(INVALID_DIMENSIONS);
                break;
            }
            result = addMatrix(A, B);
            printf("\nResult of A + B:\n");
            printMatrix(result);
            removeInternal(result);
            break;

        case 2:
            if (!areMatricesSameSize(A, B)) {
                printError(INVALID_DIMENSIONS);
                break;
            }
            result = subtractMatrix(A, B);
            printf("\nResult of A - B:\n");
            printMatrix(result);
            removeInternal(result);
            break;

        case 3:
            if (!areMatricesCompatibleForMultiplication(A, B)) {
                printError(INCOMPATIBLE_MULTIPLICATION);
                break;
            }
            result = multiplyMatrix(A, B);
            printf("\nResult of A * B:\n");
            printMatrix(result);
            removeInternal(result);
            break;

        case 4:
            result = transposeMatrix(A);
            printf("\nTranspose of Matrix A:\n");
            printMatrix(result);
            removeInternal(result);
            break;

        case 5:
            running = 0;
            break;

        default:
            printf("Invalid option.\n");
            break;
        }
    }

    // Очистка памяти
    removeInternal(A);
    removeInternal(B);

    return 0;
}
