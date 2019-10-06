#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistop.h"


//// template
//void iterateLinkedList(LinkedList* pList)
//{
//
//}
//
//void concateLinkedList(LinkedList* pListA, LinkedList* pListB)
//{
//
//}
//
//void reverseLinkedList(LinkedList* pList)
//{
//
//}


// using getLLElement(pList,i) is not efficient in displayLinkedList()
// improved version of displayLinkedList() function
void iterateLinkedList(LinkedList* pList)
{
	ListNode* pNode = NULL;
	int count = 0;
	if (pList != NULL) {
		pNode = pList->headernode.pLink;
		while (pNode != NULL) {
			printf("[%d]:%d\n", count, pNode->data);
			count++;

			pNode = pNode->pLink;
		}
		printf("Numer of nodes : %d\n",count);
	}
	else {
		printf("List is empty!!!\n");
	}

}

// concatenate List A and B
void concatLinkedList(LinkedList* pListA, LinkedList* pListB)
{
	ListNode* pNodeA = NULL, *pNodeB = NULL;

	if (pListA != NULL && pListB != NULL) {
		// find last node of List A
		pNodeA = pListA->headernode.pLink;
		while (pNodeA->pLink != NULL) {
			pNodeA = pNodeA->pLink;
		}

		// connect last node of List A to first node of List B
		pNodeA->pLink = pListB->headernode.pLink;
		
		// add element number of List B
		pListA->currentElementCount += pListB->currentElementCount;

		// clean List B
		pListB->headernode.pLink = NULL;
		pListB->currentElementCount = 0;
	}
}

// reorder linked list as reversed
void reverseLinkedList(LinkedList* pList)
{
	// Need three node :  left , mid , right
	ListNode* pLeftNode = NULL;
	ListNode* pMidNode = NULL;
	ListNode* pRightNode = NULL;

	if (pList != NULL) {
		pRightNode = pList->headernode.pLink;
		while (pRightNode != NULL) {
			// shift nodes to right direction
			pLeftNode = pMidNode;
			pMidNode = pRightNode;
			pRightNode=pRightNode->pLink;

			// reversed link
			pMidNode->pLink = pLeftNode;
		}

		pList->headernode.pLink = pMidNode;
	}
}