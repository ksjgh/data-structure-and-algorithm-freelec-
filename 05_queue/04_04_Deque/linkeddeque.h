#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

// Deque Node data type
typedef struct DequeNodeType
{
	char data;
	struct DequeNodeType* pRLink;
	struct DequeNodeType* pLLink;
} DequeNode;

// Doubly Linked Deque
typedef struct LinkedQequeType
{
	int currentElementCount;
	DequeNode* pFrontNode;
	DequeNode* pRearNode;
} LinkedDeque;

LinkedDeque* createLinkedDeque();
int insertFrontLD(LinkedDeque* pDeque, DequeNode element);
int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

#endif // !_LINKED_DEQUE_

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif