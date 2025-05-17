#define _POSIX_C_SOURCE 200809L
#include "error.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void) {
    int inputChar;
    while ((inputChar = getchar()) != '\n' && inputChar != EOF) {}
}

int getOperationChoice(const char* prompt, int min, int max) {
    int value;
    int validInput = 0;

    do {
        printf("%s", prompt);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        if (value < min || value > max) {
            printf("Error: Value must be between %d and %d.\n", min, max);
        }
        else {
            validInput = 1;
        }

        clearInputBuffer();
    } while (!validInput);

    return value;
}

ErrorCode inputMatrixDimensions(unsigned int* rows, unsigned int* cols) {
    int input;
    int scanfResult;

    do {
        printf("Enter the number of rows (must be > 0): ");
        scanfResult = scanf("%d", &input);
        clearInputBuffer(); 

        if (scanfResult != 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        if (input <= 0) {
            printf("Number must be greater than 0.\n");
            continue;
        }

        *rows = (unsigned int)input;
        break;
    } while (1);

    do {
        printf("Enter the number of columns (must be > 0): ");
        scanfResult = scanf("%d", &input);
        clearInputBuffer();

        if (scanfResult != 1) {
            printf("Invalid input. Please enter a positive integer.\n");
            continue;
        }

        if (input <= 0) {
            printf("Number must be greater than 0.\n");
            continue;
        }

        *cols = (unsigned int)input;
        break;
    } while (1);

    return ERROR_NONE;
}
