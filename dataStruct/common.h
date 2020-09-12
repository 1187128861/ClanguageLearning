#ifndef _COMMON_H_
#define _COMMON_H_


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <vld.h>

#define ElemType int

void Swap(ElemType *a, ElemType *b)
{
	assert(a != NULL);
	assert(b != NULL);
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}



#endif