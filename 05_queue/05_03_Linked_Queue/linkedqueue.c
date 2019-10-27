#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

// template
//LinkedQueue* createLinkedQueue()
//{
//
//}
//
//int enqueueLQ(LinkedQueue* pQueue, QueueNode element)
//{
//
//}
//
//QueueNode* dequeueLQ(LinkedQueue* pQueue)
//{
//
//}
//
//QueueNode* peekLQ(LinkedQueue* pQueue)
//{
//
//}
//
//void deleteLinkedQueue(LinkedQueue* pQueue)
//{
//
//}
//
//int isLinkedQueueFull(LinkedQueue* pQueue)
//{
//
//}
//
//int isLinkedQueueEmpty(LinkedQueue* pQueue)
//{
//
//}

LinkedQueue* createLinkedQueue()
{
	LinkedQueue* pReturn = NULL;
	pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedQueue));
	}
	else {
		printf("Error : createLinkedQueue(),!!!\n");
	}

	return pReturn;
}

int enqueueLQ(LinkedQueue* pQueue, QueueNode element)
{
	int ret = FALSE;
	QueueNode* pNode = NULL;

	if (pQueue != NULL) {
		pNode = (QueueNode*)malloc(sizeof(QueueNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLink = NULL;

			if (isLinkedQueueEmpty(pQueue) == TRUE) {
				pQueue->pFrontNode = pNode;
				pQueue->pRearNode = pNode;
			}
			else {				
				pQueue->pRearNode->pLink = pNode;
				pQueue->pRearNode = pNode;
			}

			pQueue->currentElementCount++;
			ret = TRUE;
		}
		else {
			printf("Error:enqueLQ(),pNode NULL");
		}
	}
	else {
		printf("Error : enqueueLQ(), pQueue NULL");
	}
	return ret;
}

QueueNode* dequeueLQ(LinkedQueue* pQueue)
{
	QueueNode* pReturn = NULL;
	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
			pQueue->pFrontNode = pQueue->pFrontNode->pLink;
			pReturn->pLink = NULL;

			pQueue->currentElementCount--;
			if (isLinkedQueueEmpty(pQueue) == TRUE) {
				pQueue->pRearNode = NULL;
			}
		}
	}

	return pReturn;
}

QueueNode* peekLQ(LinkedQueue* pQueue)
{
	QueueNode* pReturn = NULL;
	if (pQueue != NULL) {
		if (isLinkedQueueEmpty(pQueue) == FALSE) {
			pReturn = pQueue->pFrontNode;
		}
	}

	return pReturn;
}

void deleteLinkedQueue(LinkedQueue* pQueue)
{
	QueueNode* pNode = NULL;
	QueueNode* pDelNode = NULL;

	if (pQueue != NULL) {
		pNode = pQueue->pFrontNode;
		while (pNode!=NULL)
		{
			pDelNode = pNode;
			pNode = pNode->pLink;
			free(pDelNode);
		}
		free(pQueue);
	}
}

int isLinkedQueueFull(LinkedQueue* pQueue)
{
	int ret = FALSE;
	return ret;
}

int isLinkedQueueEmpty(LinkedQueue* pQueue)
{
	int ret = FALSE;
	if (pQueue != NULL) {
		if (pQueue->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}
