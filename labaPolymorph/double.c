#include "double_impl.h"
#include <stdio.h>
#include <stdlib.h>

void doubleAdd(const void* a, const void* b, void* res) {
	*(double*)res = *(const double*)a + *(const double*)b;
}

void doubleSubstract(const void* a, const void* b, void* res) {
	*(double*)res = *(const double*)a - *(const double*)b;
}

void doubleMultiply(const void* a, const void* b, void* res) {
	*(double*)res = *(const double*)a * *(const double*)b;
}

void doubleAssign(void* destination, const void* source) {
	*(double*)destination = *(const double*)source;
}

void doubleSwap(void* element1, void* element2) {
	double temp = *(double*)element1;
	*(double*)element1 = *(double*)element2;
	*(double*)element2 = temp;
}

size_t doubleGetSize(void) {
	return sizeof(double);
}

void doublePrint(const void* element) {
	printf("%g", *(const double*)element);
}

void freeDouble(void* ptr) { 
	free(ptr);
}

isSuccess doubleRead(void* destination) {
	char* input = NULL;
	size_t inputSize = 0;
	double value;

	if (getline(&input, &inputSize, stdin) == -1 || input == NULL) {
		printf("Error: Invalid input\n");
		free(input);
		return ERROR;
	}

	char* endPtr;
	value = strtod(input, &endPtr);

	if (*endPtr != '\n' && *endPtr != '\0') {
		printf("Error: Please enter a valid floating-point number.\n");
		free(input);
		return ERROR;
	}

	*(double*)destination = value;
	free(input);
	return SUCCESS;
}

const TypeInfo* getTypeInfoDouble(void) {
	static const TypeInfo doubleTypeInfo = {
		.add = doubleAdd,
		.multiply = doubleMultiply,
		.substract = doubleSubstract,
		.assign = doubleAssign,
		.swap = doubleSwap,
		.size = doubleGetSize,
		.print = doublePrint,
		.destroy = freeDouble,
		.input = doubleRead
	};
	return &doubleTypeInfo;
}