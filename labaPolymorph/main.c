#include "ui.h"
#include <stdio.h>

int main() {
    int choice;
    do {
        printMainMenu();
        choice = getOperationChoice(1, 4);

        switch (choice) {
        case 1: handleMatrixAddition(); break;
        case 2: handleMatrixMultiplication(); break;
        case 3: handleMatrixTransposition(); break;
        case 4: printf("Exiting...\n"); break;
        }
    } while (choice != 4);

    return 0;
}