#pragma once 
#include <stdlib.h>

typedef void (*binaryOperator)(const void* a, const void* b, void* result);
typedef void (*assignment)(void* destination,const void* source);
typedef size_t(*getSize)();
typedef void (*print)(const void* element);
typedef void (*destroy)(void* element);
typedef void (*swapElements)(void* element1, void* element2);


typedef struct typeInfo{
	binaryOperator add;
	binaryOperator multiply;
	binaryOperator substract;

} TypeInfo; 
