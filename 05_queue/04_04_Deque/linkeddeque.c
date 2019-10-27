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

}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{

}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{

}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{

}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{

}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{

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