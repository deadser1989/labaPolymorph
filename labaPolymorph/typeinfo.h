#pragma once 
#include <stdlib.h>

typedef void (*binaryOperator)(const void* a, const void* b, void* result);
typedef size_t(*getSize)(void* destination,const void* source);

typedef struct typeInfo{
	binaryOperator add;
	binaryOperator multiply;
	binaryOperator substract;

} TypeInfo; 
