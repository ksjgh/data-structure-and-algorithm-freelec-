
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"

//////////////////////////////////////////////////////////////////////////////////
// practice template
//CircularList* createCircularList()
//{
//
//}
//
//void deleteCircularList(CircularList* pList)
//{
//
//}
//
//int addCLElement(CircularList* pList, int position, CircularListNode element)
//{
//
//}
//
//int removeCLElement(CircularList* pList, int position)
//{
//
//}
//
//void clearCircularList(CircularList* pList)
//{
//
//}
//
//int getCircularListLength(CircularList* pList)
//{
//
//}
//
//CircularList* getCLElement(CircularList* pList, int position)
//{
//
//}
//
//void displayCircularList(CircularList* pList)
//{
//
//}
//////////////////////////////////////////////////////////////////////////////////

CircularList* createCircularList()
{
	CircularList* pReturn = NULL;
	int i = 0;

	pReturn = (CircularList*)malloc(sizeof(CircularList));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(CircularList));
	}
	else {
		printf("Error:createCircularList, pReturn malloc\n");
	}

	return pReturn;
}

void deleteCircularList(CircularList* pList)
{
	if (pList != NULL) {
		clearCircularList(pList);
		free(pList);

	}
}

// insert a node in front of position
int addCLElement(CircularList* pList, int position, CircularListNode element)
{
	int ret = FALSE;
	int i = 0;
	CircularListNode* pPreNode = NULL, * pNewNode = NULL, * pLastNode = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pNewNode = (CircularListNode*)malloc(sizeof(CircularListNode));
			if (pNewNode == NULL) {
				printf("Error : addCLElement pNewNode alloc !!!\n");
				return ret;
			}
			
			*pNewNode = element;
			pNewNode->pLink = NULL;

			if (position == 0) {
				if (pList->currentElementCount == 0) {
					pList->pLink = pNewNode;
					pNewNode->pLink = pNewNode;
				}
				else {
					// find last node
					pLastNode = pList->pLink;
					while (pLastNode->pLink != pList->pLink) {
						pLastNode = pLastNode->pLink;
					}
					
					// org sol
					//pList->pLink = pNewNode;
					//pNewNode->pLink = pLastNode->pLink;
					//pLastNode->pLink = pNewNode;

					//my sol
					pNewNode->pLink = pList->pLink;
					pList->pLink = pNewNode;
					pLastNode->pLink = pNewNode;
				}

			}
			else { //position != 0
				// find previous node
				pPreNode = pList->pLink;
				for (i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				}
				pNewNode->pLink = pPreNode->pLink;
				pPreNode->pLink = pNewNode;
			}
			pList->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("Error : Index position out of bound!!!\n");
		}
	}
}

int removeCLElement(CircularList* pList, int position)
{
	int ret = FALSE;
	int i = 0, arrayCount = 0;
	CircularListNode* pPreNode = NULL, * pDelNode = NULL, * pLastNode = NULL;

	if (pList != NULL) {
		arrayCount = getCircularListLength(pList);
		if (position >= 0 && position < arrayCount) {
			if (position == 0) {
				pDelNode = pList->pLink;
				if (arrayCount == 1) {
					pList->pLink = NULL;
					free(pDelNode);
				}
				else {
					// find last node
					pLastNode = pList->pLink;
					while (pLastNode != pList->pLink) {
						pLastNode = pLastNode->pLink;
					}
					pLastNode->pLink = pDelNode->pLink;
					pList->pLink = pDelNode->pLink;
					free(pDelNode);
				}
			}
			else {
				pPreNode = pList->pLink;
				for (i = 0; i < position - 1; i++) {
					pPreNode = pPreNode->pLink;
				}
				pDelNode = pPreNode->pLink;
				pPreNode->pLink = pDelNode->pLink;
				free(pDelNode);
			}

			pList->currentElementCount--;
			ret = TRUE;
		}
		else {
			printf("Error:Index out of bound\n");
		}
	}

	return ret;
}

void clearCircularList(CircularList* pList)
{
	if (pList != NULL) {
		while (pList->currentElementCount > 0) {
			removeCLElement(pList, 0);
		}
	}
}

int getCircularListLength(CircularList* pList)
{
	int ret = 0;
	if (pList != NULL) {
		ret = pList->currentElementCount;
	}

	return ret;
}

CircularListNode* getCLElement(CircularList* pList, int position)
{
	int i = 0;
	CircularListNode* pNode = NULL;
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount) {
			pNode = pList->pLink;
			for (i = 0; i < position; i++) {
				pNode = pNode->pLink;
			}
		}
	}

	return pNode;
}

void displayCircularList(CircularList* pList)
{
	int i = 0;
	if (pList != NULL) {
		printf("Number of nodes : %d\n", pList->currentElementCount);
		for (i = 0; i < pList->currentElementCount; i++) {
			printf("[%d],%d\n", i, getCLElement(pList, i)->data);
		}
	}
	else {
		printf("Error : displayCircularLsit, no nodes\n");
	}
}