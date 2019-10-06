#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"

//// template
//DoublyList* createDoublyList()
//{
//
//}
//
//void deleteDoublyList(DoublyList* pList)
//{
//
//}
//
//int addDLElement(DoublyList* pList, int position, DoublyListNode element)
//{
//
//}
//
//int removeDLElement(DoublyList* pList, int position)
//{
//
//}
//
//void clearDoublyList(DoublyList* pList)
//{
//
//}
//
//int getDoublyListLength(DoublyList* pList)
//{
//
//}
//
//DoublyListNode* getDLElement(DoublyList* pList, int position)
//{
//
//}
//
//void displayDoublyList(DoublyList* pList)
//{
//
//}



DoublyList* createDoublyList()
{
	DoublyList* pReturn = NULL;
	int i = 0;
	
	pReturn = (DoublyList*)malloc(sizeof(DoublyList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(DoublyList));
		pReturn->headernode.pLLink = &(pReturn->headernode);
		pReturn->headernode.pRLink = &(pReturn->headernode);

	}
	else {
		printf("Error: createDoublyList(), pReturn malloc\n");
	}

	return pReturn;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	int ret = FALSE;
	int i = 0;
	DoublyListNode* pPreNode = NULL, * pNewNode = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pNewNode = (DoublyListNode*)malloc(sizeof(DoublyListNode));
			if (pNewNode == NULL) {
				printf("Error: addDLElement, pNewNode malloc\n");
			}

			*pNewNode = element;
			pNewNode->pLLink = NULL;
			pNewNode->pRLink = NULL;

			pPreNode = &(pList->headernode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}

			pNewNode->pLLink = pPreNode;
			pNewNode->pRLink = pPreNode->pRLink;
			pPreNode->pRLink = pNewNode;
			pNewNode->pRLink->pLLink = pNewNode;

			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("Error : addDLElement(), Index out of bound\n");
		}
	}
	return ret;

}

int removeDLElement(DoublyList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	DoublyListNode* pPreNode = NULL, * pDelNode = NULL;
	if (pList != NULL) {
		arrayCount = getDoublyListLength(pList);
		if (position >= 0 && position < arrayCount) {
			
			// find preNode
			pPreNode = &(pList->headernode);
			for (i = 0; i < position; i++) {
				pPreNode = pPreNode->pRLink;
			}
			
			// Delete Node
			pDelNode = pPreNode->pRLink;

			// Link reorder
			pPreNode->pRLink = pDelNode->pRLink;
			pDelNode->pRLink->pLLink = pPreNode;
			free(pDelNode);

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("Error : removeDLElement(), index out of bound\n");
		}
	}

	return ret;
}

void deleteDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		clearDoublyList(pList);
		free(pList);
	}
}

void clearDoublyList(DoublyList* pList)
{
	if (pList != NULL) {
		while (pList->currentElementCount > 0) {
			removeDLElement(pList, 0);
		}
	}
}

int getDoublyListLength(DoublyList* pList)
{
	int ret = 0;
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}
	return ret;
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode* pReturn = NULL;
	DoublyListNode* pNode = NULL;
	int i = 0;

	if (pList != NULL) {
		if (position >= 0 && position < pList->currentElementCount) {
			pNode = pList->headernode.pRLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pRLink;
			}
			pReturn = pNode;
		}
		else {
			printf("Error : getDLElement(), index out of bound\n");
		}
	}

	return pReturn;
}

void displayDoublyList(DoublyList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("Number of elements : %d\n", pList->currentElementCount);
		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d]:%d\n", i, getDLElement(pList, i)->data);
		}
	}
	else {
		printf("No elements!!!\n");
	}
}