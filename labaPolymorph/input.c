#include "input.h"
#include <stdio.h>
#include <stdlib.h>

void clearInputBuffer(void) {
    int inputChar;
    while ((inputChar = getchar()) != '\n' && inputChar != EOF) {
        // Просто очищаем буфер до конца строки или EOF
    }
}

unsigned int getPositiveDimension(const char* prompt) {
    char* inputLine = NULL;
    size_t bufferSize = 0;
    unsigned int value = 0;
    int validInput = 0;

    do {
        printf("%s", prompt);

        if (getline(&inputLine, &bufferSize, stdin) == -1) {
            printf("Error: Failed to read input. Please try again.\n");
            free(inputLine);
            inputLine = NULL;
            continue;
        }

        if (inputLine == NULL) {
            fprintf(stderr, "Unexpected null input.\n");
            continue;
        }

        char* endPtr;
        long tempValue = strtol(inputLine, &endPtr, 10);

        if (*endPtr != '\n' && *endPtr != '\0') {
            printf("Invalid input: Please enter a valid number.\n");
        }
        else if (tempValue <= 0) {
            printf("Error: Value must be greater than zero.\n");
        }
        else {
            value = (unsigned int)tempValue;
            validInput = 1;
        }

    } while (!validInput);

    free(inputLine);
    return value;
}

unsigned int getOperationChoice(int min, int max) {
    unsigned int choice;
    do {
        // Просто просим ввести выбор, без указания диапазона
        choice = getPositiveDimension("Enter your choice: ");

        // Проверяем, что число в пределах от min до max
        if (choice < min || choice > max) {
            printf("Error: Please choose a number between %d and %d.\n", min, max);
        }
    } while (choice < min || choice > max); // Повторяем до тех пор, пока число не в пределах диапазона

    return choice;
}


void inputMatrixDimensions(unsigned int* rows, unsigned int* cols) {
    *rows = getPositiveDimension("Enter the number of rows for the matrix: ");
    *cols = getPositiveDimension("Enter the number of columns for the matrix: ");
}
