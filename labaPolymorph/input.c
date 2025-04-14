#include <stdio.h>
#include <stdlib.h>
#include "input.h"

void clearInputBuffer(void) {
    int inputChar;
    while ((inputChar = getchar()) != '\n' || inputChar != EOF) {}
}

