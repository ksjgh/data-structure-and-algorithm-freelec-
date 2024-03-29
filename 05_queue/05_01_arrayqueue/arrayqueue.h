#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNodeType
{
	char data;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
	int maxElementCount;
	int currentElementCount;
	int front;					// front index
	int rear;					// rear index
	ArrayQueueNode* pElement;   // linear 1D array to save nodes
} ArrayQueue;

ArrayQueue* createArrayQueue(int maxElement);
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode* dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode* peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);
int isArrayQueueEmpty(ArrayQueue* pQueue);

#endif // !_ARRAY_QUEUE_

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif