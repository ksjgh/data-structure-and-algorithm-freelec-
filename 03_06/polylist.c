#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "polylist.h"

//// template
//int addPolyNodeLast(LinkedList* pList, float coef, int degree)
//{
//
//}
//
//LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB)
//{
//
//}
//
//void displayPolyList(LinkedList* pList)
//{
//
//}


int addPolyNodeLast(LinkedList * pList, float coef, int degree)
{
	int ret = FALSE, i = 0;

	ListNode node = { 0, };
	node.coef = coef;
	node.degree = degree;

	if (pList != NULL) {
		int length = getLinkedListLength(pList);
		ret = addLLElement(pList, length, node);
	}

	return ret;
}

LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB)
{
	LinkedList* pReturn = NULL; // result polynomial
	ListNode* pNodeA = NULL, *pNodeB = NULL;
	float coefSum = 0;
	
	if (pListA != NULL && pListB != NULL) {
		pReturn = createLinkedList();
		if (pReturn == NULL) {
			printf("Error : pReturn malloc\n");
		}
		
		pNodeA = pListA->headerNode.pLink;
		pNodeB = pListB->headerNode.pLink;
		// start sum A,B term by term		
		while (pNodeA != NULL && pNodeB != NULL) {
			int degreeA = pNodeA->degree;
			int degreeB = pNodeB->degree;

			if (degreeA > degreeB) {
				coefSum = pNodeA->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);
				pNodeA = pNodeA->pLink;
			}
			else if (degreeA == degreeB) {
				coefSum = pNodeA->coef + pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeA);

				pNodeA = pNodeA->pLink;
				pNodeB = pNodeB->pLink;
			}
			else {
				coefSum = pNodeB->coef;
				addPolyNodeLast(pReturn, coefSum, degreeB);
				pNodeB = pNodeB->pLink;
			}
		}

		// if terms of polynomial A exist
		while (pNodeA != NULL) {
			//coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, pNodeA->coef, pNodeA->degree);
			pNodeA = pNodeA->pLink;
		}

		// if terms of polynomial B exist
		while (pNodeB != NULL) {
			//coefSum = pNodeA->coef;
			addPolyNodeLast(pReturn, pNodeB->coef, pNodeB->degree);
			pNodeB = pNodeB->pLink;
		}
	}
	else {
		printf("Error : There is empty polynomial!!!\n");
	}

	return pReturn;
}

void displayPolyList(LinkedList* pList)
{
	int i = 0;
	if (pList != NULL) {
		for (i = 0; i < pList->currentElementCount; i++) {
			ListNode* pNode = getLLElement(pList, i);
			if (pNode != NULL) {
				printf("%4.1fx^%d", pNode->coef, pNode->degree);

				if (i == pList->currentElementCount - 1) {
					printf("\n");
				}
				else {
					printf(" + ");
				}
			}
		}
	}
	else {
		printf("Empty polynomial!!!\n");
	}
}

