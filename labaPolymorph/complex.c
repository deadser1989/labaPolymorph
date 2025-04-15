#include "complex_impl.h"
#include "complex.h"

#include <stdio.h>
#include <stdlib.h>

void complexAdd(const void* a, const void* b, void* res) {
	complex* complexRes = (complex*)res;
	const complex* complexA = (const complex*)a;
	const complex* complexB = (const complex*)b;   
	complexRes->real = complexA->real + complexB->real;
	complexRes->imag = complexA->imag + complexB->imag;
}

void complexSubstract(const void* a, const void* b, void* res) {
	complex* complexRes = (complex*)res;
	const complex* complexA = (const complex*)a;
	const complex* complexB = (const complex*)b;
	complexRes->real = complexA->real - complexB->real;
	complexRes->imag = complexA->imag - complexB->imag;
}

void complexMultiply(const void* a, const void* b, void* res) {
	complex* complexRes = (complex*)res;
	const complex* complexA = (const complex*)a;
	const complex* complexB = (const complex*)b;
	complexRes->real = (complexA->real * complexB->real) - (complexA->imag * complexB->imag);
	complexRes->imag = (complexA->real * complexB->imag) + (complexA->imag * complexB->real);
}


void complexAssign(void* destination, const void* source) {
	complex* complexDestination = (complex*)destination;
	const complex* complexSource = (const complex*)source;
	complexDestination->real = complexSource->real;
	complexDestination->imag = complexSource->imag;
}

void complexSwap(void* element1, void* element2) {
	complex* complex1 = (complex*)element1;
	complex* complex2 = (complex*)element2;

	complex temp = *complex1;
	*complex1 = *complex2;
	*complex2 = temp;
}

size_t complexGetSize(void) {
	return sizeof(complex);
}

void complexPrint(const void* a)
{
	const complex* complexA = (const complex*)a;

	printf("[");

	printf("%g", complexA->real);

	if (complexA->imag > 0)
	{
		printf(" + %gi", complexA->imag);
	}
	else if (complexA->imag < 0)
	{
		printf(" - %gi", -(complexA->imag));
	}

	printf("]");
}

void freeComplex(void* ptr) {
	free(ptr);
}

void clearInputBuffer() {
	int characterFromInput;
	while ((characterFromInput = getchar()) != '\n' && characterFromInput != EOF) {}
}

isSuccess readComplex(void* destination)
{
	complex* value = (complex*)destination;

	double tempReal, tempImag;

	printf("Enter complex number (real, imag): ");
	if (scanf(" (%lf, %lf)", &tempReal, &tempImag) != 2)
	{
		printf("Error: invalid format. Try again.\n");
		clearInputBuffer();
		return ERROR;
	}

	value->real = tempReal;
	value->imag = tempImag;

	clearInputBuffer(); // очистка от мусора

	return SUCCESS;
}

static struct typeInfo* type = NULL;

const struct typeInfo* getTypeInfoComplex() {
	if (type == NULL) {
		type = malloc(sizeof(struct typeInfo));
		if (type == NULL) {
			printf("Error: memory allocation failed.\n");
			exit(1);
		}
		type->add = complexAdd;
		type->multiply = complexMultiply;
		type->substract = complexSubstract;
		type->assign = complexAssign;
		type->swap = complexSwap;
		type->size = complexGetSize;
		type->print = complexPrint;
		type->destroy = freeComplex;
		type->input = readComplex;
	}

	return type;
}