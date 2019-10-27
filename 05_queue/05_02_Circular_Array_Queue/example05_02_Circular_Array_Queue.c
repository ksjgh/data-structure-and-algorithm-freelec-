#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

// ref sol, see my sol
void displayArrayQueue(ArrayQueue* pQueue)
{
	int i = 0;
	int maxElementIndex = 0;
	int pos = 0;

	if (pQueue != NULL) {
		printf("Queue Max Node Size: %d, Current Number of Nodes: %d\n",
			pQueue->maxElementCount,
			pQueue->currentElementCount);

		maxElementIndex = pQueue->front + pQueue->currentElementCount;
		for (i = pQueue->front + 1; i <= maxElementIndex; i++) {
		//for (i = pQueue->front + 1; i <= pQueue->currentElementCount; i++) {
			pos = i % pQueue->maxElementCount;
			printf("[%d]-[%c]\n", i, pQueue->pElement[pos].data);
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
		printf("You will see no error when circular queue is used.\n\n");
		printf("Linear Array Queue problem is solved in Circular Queue\n");
		enqueueAQChar(pQueue, 'E');
		displayArrayQueue(pQueue);
	}
	return 0;
}
