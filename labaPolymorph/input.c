#define _POSIX_C_SOURCE 200809L
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

void inputMatrixDimensions(unsigned int* rows, unsigned int* cols) {
    *rows = 0;
    *cols = 0;

    while (*rows <= 0) {
        printf("Enter the number of rows: ");
        scanf("%u", rows);
        clearInputBuffer();
    }

    while (*cols <= 0) {
        printf("Enter the number of columns: ");
        scanf("%u", cols);
        clearInputBuffer();
    }
}
