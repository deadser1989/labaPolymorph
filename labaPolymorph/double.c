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
	printf("%lf", *(const double*)element);
}

void freeDouble(void* ptr) {
	free(ptr);
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
	};
	return &doubleTypeInfo;
}