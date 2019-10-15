#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"

LinkedStack* createLinkedStack()
{
	LinkedStack* pReturn = NULL;
	pReturn = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedStack));
	}
	else {
		printf("Error : createLinkedStack(), pReturn malloc\n");
		return NULL;
	}

	return pReturn;
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	int ret = FALSE;
	StackNode* pNode = NULL;

	if (pStack != NULL) {
		pNode = (StackNode*)malloc(sizeof(StackNode));
		if (pNode != NULL) {
			memset(pNode, 0, sizeof(StackNode));
			*pNode = element;
			pNode->pLink = pStack->pTopElement;
			pStack->pTopElement = pNode;

			pStack->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("Error : pushLS(), pNode malloc\n");
		}
	}
	else {
		printf("Error : pushLS(), Stack is Empty\n");
	}

	return ret;
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE) {
			pReturn = pStack->pTopElement;
			pStack->pTopElement = pStack->pTopElement->pLink;
			pReturn->pLink = NULL;

			pStack->currentElementCount--;
		}

	}

	return pReturn;
}

StackNode* peekLS(LinkedStack* pStack)
{
	StackNode* pReturn = NULL;
	if (pStack != NULL) {
		if (isLinkedStackEmpty(pStack) == FALSE)
		{
			pReturn = pStack->pTopElement;
		}
	}

	return pReturn;
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode* pNode = NULL;
	StackNode* pDelNode = NULL;

	if (pStack != NULL) {
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pStack);
	}
}

int isLinkedStackFull(LinkedStack* pStack)
{
	int ret = FALSE;
	return ret;
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	int ret = FALSE;
	if (pStack != NULL) {
		if (pStack->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}

void displayLinkedStack(LinkedStack* pStack)
{
	StackNode* pNode = NULL;
	int i = 1;
	if (pStack != NULL) {
		printf("Nodes in stack : %d\n", pStack->currentElementCount);
		pNode = pStack->pTopElement;
		while (pNode != NULL) {
			printf("[%d]-[%c]\n", pStack->currentElementCount - i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}