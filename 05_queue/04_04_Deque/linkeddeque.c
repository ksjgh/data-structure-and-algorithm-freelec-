#include <stdarg.h>
#include <stdlib.h>
#include "linkeddeque.h"

////template
//LinkedDeque* createLinkedDeque()
//{
//
//}
//
//int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
//{
//
//}
//
//int insertRearLD(LinkedDeque* pDeque, DequeNode element)
//{
//
//}
//
//DequeNode* deleteFrontLD(LinkedDeque* pDeque)
//{
//
//}
//
//DequeNode* deleteRearLD(LinkedDeque* pDeque)
//{
//
//}
//
//DequeNode* peekFrontLD(LinkedDeque* pDeque)
//{
//
//}
//
//DequeNode* peekRearLD(LinkedDeque* pDeque)
//{
//
//}
//
//void deleteLinkedDeque(LinkedDeque* pDeque)
//{
//
//}
//
//int isLinkedDequeFull(LinkedDeque* pDeque)
//{
//
//}
//
//int isLinkedDequeEmpty(LinkedDeque* pDeque)
//{
//
//}
///////////////////////////////////////////////////////////////////////////



//ref sol
LinkedDeque* createLinkedDeque()
{
	LinkedDeque* pReturn = NULL;
	
	pReturn = (LinkedDeque*)malloc(sizeof(LinkedDeque));
	if (pReturn != NULL) {
		memset(pReturn, 0, sizeof(LinkedDeque));
	}
	else {
		printf("Error : createLinkedDeque(), \n");
	}
	
	return pReturn;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	int ret = FALSE;
	DequeNode* pNode = NULL;

	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));
		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = pNode;
				pDeque->pRearNode = pNode;
			}
			else {
				pDeque->pFrontNode->pLLink = pNode;
				pNode->pRLink = pDeque->pFrontNode;
				pDeque->pFrontNode = pNode;
			}
			pDeque->currentElementCount++;
			ret = TRUE;
		}
	}

	return ret;
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	int ret = FALSE;
	DequeNode* pNode = NULL;
	if (pDeque != NULL) {
		pNode = (DequeNode*)malloc(sizeof(DequeNode));

		if (pNode != NULL) {
			*pNode = element;
			pNode->pLLink = NULL;
			pNode->pRLink = NULL;

			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = pNode;
				pDeque->pRearNode = pNode;
			}
			else {
				pDeque->pRearNode->pRLink = pNode;
				pNode->pLLink = pDeque->pRearNode;
				pDeque->pRearNode = pNode;
			}
			pDeque->currentElementCount++;
			ret = TRUE;
		}
	}

	return ret;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pFrontNode;
			pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
			pReturn->pRLink = NULL;

			pDeque->currentElementCount--;
			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pRearNode = NULL;
			}
			else {
				pDeque->pFrontNode->pLLink = NULL;
			}
		}
	}

	return pReturn;
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pRearNode;
			pDeque->pRearNode = pDeque->pRearNode->pLLink;
			pReturn->pLLink = NULL;

			pDeque->currentElementCount--;
			if (isLinkedDequeEmpty(pDeque) == TRUE) {
				pDeque->pFrontNode = NULL;
			}
			else {
				pDeque->pRearNode->pRLink = NULL;
			}
		}
	}
	return pReturn;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pFrontNode;
		}
	}

	return pReturn;
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	DequeNode* pReturn = NULL;
	if (pDeque != NULL) {
		if (isLinkedDequeEmpty(pDeque) == FALSE) {
			pReturn = pDeque->pRearNode;
		}
	}

	return pReturn;
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode* pNode = NULL;
	DequeNode* pDelNode = NULL;

	if (pDeque != NULL) {
		pNode = pDeque->pFrontNode;
		while (pNode != NULL) {
			pDelNode = pNode;
			pNode = pNode->pRLink;
			free(pDelNode);
		}
		free(pDeque);
	}
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
	int ret = FALSE;
	return ret;
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	int ret = FALSE;

	if (pDeque != NULL) {
		if (pDeque->currentElementCount == 0) {
			ret = TRUE;
		}
	}

	return ret;
}