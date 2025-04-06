#include "integer_impl.h"
#include <stdio.h>

void intAdd(const void* a, const void* b, void* res) {
	*(int*)res = (*(const int*) a + *(const int*) b); //значение на которое указывает res
}

void intMultiply(const void* a, const void* b, void* res) {
	*(int*)res = (*(const int*)a + *(const int*)b);
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

void freeInteger(void* ptr)
{
	free(ptr);
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
		.destroy = freeInteger
	};
	return &integerTypeInfo;
}