#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"

int main(int argc, char* argv[])
{
	int i = 0;
	int arrayCount = 0;
	ArrayList* pList = NULL;
	ArrayListNode* pValue = NULL;

	pList = createList(6);
	if (pList != NULL)
	{
		ArrayListNode node;

		// add node
		printf("Add note test\n");
		node.data = 1;
		addALElement(pList, 0, node);

		node.data = 3;
		addALElement(pList, 1, node);

		node.data = 5;
		addALElement(pList, 2, node);

		displayArrayList(pList);
		printf("\n\n\n");

		// remove element
		printf("remove first node\n");
		removeElement(pList, 0);
		displayArrayList(pList);
		printf("\n\n\n");

		// test other function
		printf("Test getArrayListLenght() , getALElement()\n");
		arrayCount = getArrayListLength(pList);
		for (i = 0; i < arrayCount; i++)
		{
			pValue = getALElement(pList, i);
			printf("index[%d]-[%d]\n", i, pValue->data);
		}
		printf("\n\n\n");
		
		printf("delete array\n");
		deleteArrayList(pList);
	}

	return 0;
}