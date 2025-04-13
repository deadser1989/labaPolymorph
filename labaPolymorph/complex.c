#include "complex_impl.h"
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

}
