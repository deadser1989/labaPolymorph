#include "complex_impl.h"
#include <stdio.h>
#include <stdlib.h>

void complexAdd(const void* a, const void* b, void* res) {
	complex* result = (complex*)res;
	const complex* num1 = (const complex*)a;
	const complex* num2 = (const complex*)b;   
	result->real = num1->real + num2->real;
	result->imag = num1->imag + num2->imag;
}