#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void displayLinkedQueue(LinkedQueue* pQueue) {
	QueueNode* pNode = NULL;
	int i = 0;
	if (pQueue != NULL) {
		printf("Current Node Size: %d\n", pQueue->currentElementCount);
		pNode = pQueue->pFrontNode;
		while (pNode != NULL) {
			printf("[%d]-[%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pLink;
		}
	}
}

// enQueue Wrapper function
int enqueueLQChar(LinkedQueue* pQueue, char data)
{
	QueueNode node = { 0, };
	node.data = data;
	return enqueueLQ(pQueue, node);
}


int main(int argc, char* argv[])
{
	LinkedQueue* pQueue = NULL;
	QueueNode* pNode = NULL;
	char value = 0;

	// create Linked Queue
	pQueue = createLinkedQueue();
	if (pQueue != NULL) {
		// enqueue : 'A', 'B', 'C', 'D'
		printf("Enque Test\n");
		enqueueLQChar(pQueue, 'A');
		enqueueLQChar(pQueue, 'B');
		enqueueLQChar(pQueue, 'C');
		enqueueLQChar(pQueue, 'D');
		displayLinkedQueue(pQueue);

		
		printf("\n");
		printf("Dequeue Test\n");
		pNode = dequeueLQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			
			// !!!!!! important here !!!!!!!
			free(pNode);
		}
		else {
			printf("Error: main , deque fail\n");
		}

		pNode = dequeueLQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n", pNode->data);
			free(pNode);
		}
		else {
			printf("Error: main , deque fail\n");
		}
		displayLinkedQueue(pQueue);

		printf("\n");
		printf("Peek Test\n");
		pNode = peekLQ(pQueue);
		if (pNode != NULL) {
			printf("Peek Value-[%c]\n", pNode->data);
		}
		displayLinkedQueue(pQueue);

		// enqueue 'E'
		printf("\n");
		printf("More enqueue\n");
		enqueueLQChar(pQueue, 'E');

		displayLinkedQueue(pQueue);

		deleteLinkedQueue(pQueue);
	}

	return 0;
}

