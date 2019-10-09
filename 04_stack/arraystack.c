#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"


 //push to AS(Array Stack)

//ArrayStack* createArrayStack(int maxElement)
//{
//
//}
//
//int pushAS(ArrayStack* pStack, ArrayStackNode element)
//{
//
//}
//
//ArrayStackNode* popAS(ArrayStack* pStack)
//{
//
//}
//
//ArrayStackNode* peekAS(ArrayStack* pStack)
//{
//
//}
//
//void deleteArrayStack(ArrayStack* pStack)
//{
//
//}
//
//int isArrayStackFull(ArrayStack* pStack)
//{
//
//}
//
//int isArrayStackEmpty(ArrayStack* pStack)
//{
//
//}
//
//



ArrayStack* createArrayStack(int size)
{
	ArrayStack* pReturn = NULL;
	int i = 0;

	if (size > 0) {
		pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayStack));
			pReturn->maxElementCount = size;
			//pReturn->currentElementCount = 0;
		}
		else {
			printf("Error : createArrayStack(), pReturn malloc\n");
			return NULL;
		}

		pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * size);
		if (pReturn->pElement != NULL) {
			memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);
		}
		else {
			printf("Error : pReturn->Element malloc\n");
			free(pReturn);
			return NULL;
		}
	}
	else {
		printf("Error: size should be larger than 0\n");
		return NULL;
	}

	return pReturn;
}


// push to AS(Array Stack)
int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
	int ret = FALSE;
	int i = 0;

	if (pStack != NULL) {
		if (isArrayStackFull(pStack) == FALSE ) {
			pStack->pElement[pStack->currentElementCount] = element;
			pStack->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("Push : Stack is Full!!!\n");
		}
	}
	else {
		printf("Push : Invalid Stack\n");
	}

	return ret;
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
			if (pReturn != NULL) {
				*pReturn = pStack->pElement[pStack->currentElementCount];
				pStack->currentElementCount--;
			}
			else {
				printf("Error : popAS(), pReturn malloc\n");
			}

		}
		else {
			printf("Stack is empty!!!\n");			
		}
	}
	else {
		printf("Invalid Stack\n");
	}

	return pReturn;
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
	ArrayStackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isArrayStackEmpty(pStack) == FALSE) {
			pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
		}		
	}
	else {
		printf("Invalid Stack\n");
	}

	return pReturn;
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (pStack != NULL) {
		if (pStack->pElement != NULL) {
			free(pStack->pElement);
		}
		free(pStack);
	}
}

int isArrayStackFull(ArrayStack* pStack)
{
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentElementCount == pStack->maxElementCount) {
			ret = TRUE;
		}
	}

	return ret;
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}