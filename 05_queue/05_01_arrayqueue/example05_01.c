#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

void displayArrayQueue(ArrayQueue* pQueue)
{
	int i = 0;

	if (pQueue != NULL) {
		printf("Queue Max Node Size: %d, Current Number of Nodes: %d\n",
			pQueue->maxElementCount,
			pQueue->currentElementCount);

		for (i = pQueue->front + 1; i <= pQueue->rear; i++) {
			printf("[%d]-[%c]\n", i, pQueue->pElement[i].data);
		}
	}
}


int enqueueAQChar(ArrayQueue* pQueue, char data)
{
	ArrayQueueNode node = { 0, };
	node.data = data;
	return enqueueAQ(pQueue, node);
}

int main(int argc, char* argv[])
{
	ArrayQueue* pQueue = NULL;
	ArrayQueueNode* pNode = NULL;
	char value = 0;

	pQueue = createArrayQueue(4);
	if (pQueue != NULL) {
		// Queue Init : 'A', 'B', 'C', 'D' add.
		enqueueAQChar(pQueue, 'A');
		enqueueAQChar(pQueue, 'B');
		enqueueAQChar(pQueue, 'C');
		enqueueAQChar(pQueue, 'D');
		displayArrayQueue(pQueue);

		pNode = dequeueAQ(pQueue);
		if (pNode != NULL) {
			printf("Dequeue Value-[%c]\n",
				pNode->data);
			free(pNode);
		}
		displayArrayQueue(pQueue);

		pNode = peekAQ(pQueue);
		if (pNode != NULL) {
			printf("Peek Value-[%c]\n",
				pNode->data);
		}
		displayArrayQueue(pQueue);

		printf("\n\n");
		printf("enqueue char [%c]\n", 'E');
		printf("You will see an error. This is the limit of Linear Array Queue\n\n");
		printf("One solution is using Circular Array Queue\n");
		enqueueAQChar(pQueue, 'E');
		displayArrayQueue(pQueue);
	}
	return 0;
}
