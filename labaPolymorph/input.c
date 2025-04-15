#include "input.h"

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
            perror("Error: Failed to read input");
            free(inputLine);
            exit(EXIT_FAILURE);
        }

        if (inputLine == NULL) {
            fprintf(stderr, "Unexpected null input.\n");
            exit(EXIT_FAILURE);
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

void inputMatrixDimensions(unsigned int* rows, unsigned int* cols) {
    *rows = getPositiveDimension("Enter the number of rows for the matrix: ");
    *cols = getPositiveDimension("Enter the number of columns for the matrix: ");
}
