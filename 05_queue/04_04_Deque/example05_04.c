#include <stdio.h>
#include <stdlib.h>
#include "linkeddeque.h"

int insertFrontLDChar(LinkedDeque* pDeque, char data)
{
	DequeNode node = { 0, };
	node.data = data;
	return insertFrontLD(pDeque, node);
}

int insertRearLDChar(LinkedDeque* pDeque, char data)
{
	DequeNode node = { 0, };
	node.data = data;
	return insertRearLD(pDeque, node);
}

void displayLinkedDeque(LinkedDeque* pDeque)
{
	DequeNode* pNode = NULL;
	int i = 0;

	if (pDeque != NULL) {
		printf("Current Node Size : %d\n",
			pDeque->currentElementCount);
		pNode = pDeque->pFrontNode;
		while (pNode != NULL) {
			printf("[%d]-[%c]\n", i, pNode->data);
			i++;
			pNode = pNode->pRLink;
		}
	}
}

int main(int argc, char* argv[])
{
	LinkedDeque* pDeque = NULL;
	DequeNode* pNode = NULL;

	pDeque = createLinkedDeque();
	if (pDeque != NULL) {

		printf("Insert Test\n");
		insertFrontLDChar(pDeque, 'A');
		insertFrontLDChar(pDeque, 'B');
		insertRearLDChar(pDeque, 'C');
		insertRearLDChar(pDeque, 'D');
		displayLinkedDeque(pDeque);

		printf("Delete Rear Node Test\n");
		pNode = deleteRearLD(pDeque);
		if (pNode != NULL) {
			printf("deletedRearLD Value-[%c]\n", pNode->data);
			free(pNode);
		}
		displayLinkedDeque(pDeque);

		printf("Detele Front Node Test\n");
		pNode = deleteFrontLD(pDeque);
		if (pNode != NULL) {
			printf("deleteFrontLD Value-[%c]\n", pNode->data);
			free(pNode);
		}
		displayLinkedDeque(pDeque);

		deleteLinkedDeque(pDeque);
	}
	return 0;
}
