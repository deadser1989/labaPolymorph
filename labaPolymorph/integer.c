#include "integer_impl.h"
#include "integer.h"

#include <stdio.h>
#include <stdlib.h>

void intAdd(const void* a, const void* b, void* res) {
    *(int*)res = (*(const int*)a + *(const int*)b);
}

void intMultiply(const void* a, const void* b, void* res) {
    *(int*)res = (*(const int*)a) * (*(const int*)b);
}

void intSubstract(const void* a, const void* b, void* res) {
    *(int*)res = (*(const int*)a - *(const int*)b);
}

void intAssign(void* destination, const void* source) {
    *(int*)destination = *(const int*)source;
}

void intSwap(void* element1, void* element2) {
    int temp = *(int*)element1;
    *(int*)element1 = *(int*)element2;
    *(int*)element2 = temp;
}

size_t intGetSize(void) {
    return sizeof(int);
}

void intPrint(const void* element) {
    printf("%d", *(const int*)element);
}

void freeInteger(void* ptr) {
    free(ptr);
}

isSuccess intRead(void* destination) {
    char input[256]; // Массив фиксированного размера для ввода
    int valueHolder;

    printf("Enter an integer: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error: Invalid input\n");
        return ERROR;
    }

    char* endPtr;
    valueHolder = (int)strtol(input, &endPtr, 10);

    // Проверка на успешное преобразование
    if (*endPtr != '\n' && *endPtr != '\0') {
        printf("Error: Please enter a valid integer number.\n");
        return ERROR;
    }

    *(int*)destination = valueHolder;
    return SUCCESS;
}

const TypeInfo* getTypeInfoInteger(void) {
    static const TypeInfo integerTypeInfo = {
        .add = intAdd,
        .multiply = intMultiply,
        .substract = intSubstract,
        .assign = intAssign,
        .swap = intSwap,
        .size = intGetSize,
        .print = intPrint,
        .destroy = freeInteger,
        .input = intRead,
    };
    return &integerTypeInfo;
}
