#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createList(int maxElement)
{
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElement > 0)
	{
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));
		if (pReturn != NULL)
		{
			pReturn->maxElementCount = maxElement;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else
		{
			printf("Error, malloc , pReturn\n");
			return NULL;
		}
	}
	else
	{
		printf("Error : Max Element < 1");
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * maxElement);
	if (pReturn->pElement == NULL) 
	{
		printf("malloc Error pReturn->pElement\n");
		free(pReturn);
		return NULL;
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElement);
	return pReturn;
}

void deleteArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList != NULL) {
		free(pList->pElement); // delete all nodes!!!
		free(pList);
	}
}

int isArrayListFull(ArrayList* pList)
{
	int ret = FALSE;
	if (pList != NULL) {
		if (pList->currentElementCount == pList->maxElementCount) {
			ret = TRUE;
		}
	}
	return ret;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element)
{
	int ret = FALSE;
	int i = 0;
	if (pList != NULL) {
		if (isArrayListFull != TRUE) {
			if (position >= 0 && position <= pList->maxElementCount - 1) {
				for (i = pList->currentElementCount - 1; i >= position; i--) {
					pList->pElement[i + 1] = pList->pElement[i];
				}
				pList->pElement[position] = element;
				pList->currentElementCount++;
				ret = TRUE;
			}
			else {
				printf("Error : Index [%d] out of bound, addALElement()\n",position);
			}
		}
		else {
			printf("Error, List is full [%d]/[%d]\n",position,pList->maxElementCount);
		}
	}


	return ret;
}

int removeElement(ArrayList* pList, int position)
{
	int ret = FALSE;
	int i = 0;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			for (i = position; i < pList->currentElementCount - 1; i++) {
				pList->pElement[i] = pList->pElement[i + 1];
			}
			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("Error : Index [%d] out of bound\n", position);
		}
	}
	
	return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	ArrayListNode* pReturn = NULL;
	if (pList != NULL) {
		if (position >= 0 && position < getArrayListLength(pList)) {
		//if(position=0 && position<pList->currentElementCount){
			pReturn = &(pList->pElement[position]); // see '&'
			//pReturn = pList->pElement + positon;
		}
	}
	
	return pReturn;
}

void displayArrayList(ArrayList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("Max element number = %d\n", pList->maxElementCount);
		printf("Current element count = %d\n", pList->currentElementCount);

		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getALElement(pList, i)->data);
		}

		i = pList->currentElementCount;
		for (; i < pList->maxElementCount; i++) {
			printf("[%d],Empty\n", i);
		}
	}
	else {
		printf("Array List is NULL\n");
	}
}

//void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList)
{
	int ret = 0;

	if (pList != NULL) {

		ret = pList->currentElementCount;
	}

	return ret;
}