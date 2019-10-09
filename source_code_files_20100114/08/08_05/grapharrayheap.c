#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grapharrayheap.h"

// �ִ� ������ ����
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount)
{
	ArrayMaxHeap *pReturn = NULL;
	int i = 0;

	// �ִ� ���� ���� ����
	if (maxElementCount > 0) {
		pReturn = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));

		// �޸� �Ҵ� ���� ����
		if (pReturn != NULL) {
			// �ִ� ��� ����, ���� ��� ����, �迭 ������ �ʱ�ȭ.
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("Error, malloc() in createArrayList()\n");
			return NULL;
		}
	}
	else {
		printf("Max Element Count must be greater than 0\n");
		return NULL;
	}

	// ��� ������ ���� 1���� array �Ҵ�
	pReturn->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1));
	if (pReturn->pElement == NULL) {
		printf("Error, 2'nd malloc() in createArrayList()\n");
		return NULL;
	}

	// ��� ������ �ʱ�ȭ.
	memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount+1));

	return pReturn;
}

// �ִ� ������ ����
void insertMaxHeapAH(ArrayMaxHeap* pHeap, HeapNode element)
{
	int i = 0;

	if (pHeap != NULL) {
		if (pHeap->currentElementCount ==  pHeap->maxElementCount) {
			printf("Error, heap is full [%d],insertMaxHeapAH()\n", 
				pHeap->maxElementCount);
			return;
		}
		
		pHeap->currentElementCount++;
		i =  pHeap->currentElementCount;
		while((i != 1) && (element.key > pHeap->pElement[i/2].key)) {
			pHeap->pElement[i] = pHeap->pElement[i/2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

// �ִ� ������ ����
HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int i = 0;
	int parent =0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount >  0) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL) {
			printf("Error, malloc() in deleteMaxHeapAH()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[ 1 ];

		i =  pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[ i ]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while(child <= pHeap->currentElementCount) {
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[ child ].key < pHeap->pElement[ child+1 ].key) {
				child++;
			}
			if (pTemp->key >= pHeap->pElement[ child ].key) {
				break;
			}

			pHeap->pElement[ parent ] = pHeap->pElement[ child ];
			parent = child;
			child *= 2;
		}
		pHeap->pElement[ parent ] = *pTemp;
	}

	return pReturn;
}

// �ִ� ������ ����
void deleteArrayMaxHeap(ArrayMaxHeap* pHeap)
{
	if (pHeap != NULL) {
		if (pHeap->pElement != NULL) {
			free(pHeap->pElement);
		}
		free(pHeap);
	}
}


// �ּ� ������ ����
ArrayMinHeap* createArrayMinHeap(int maxElementCount)
{
	return createArrayMaxHeap(maxElementCount);
}

// �ּ� ������ ����
void deleteArrayMinHeap(ArrayMaxHeap* pHeap)
{
	deleteArrayMaxHeap(pHeap);
}

// �ּ� ������ ����
void insertMinHeapAH(ArrayMinHeap* pHeap, HeapNode element)
{
	int i = 0;

	if (pHeap != NULL) {
		if (pHeap->currentElementCount ==  pHeap->maxElementCount) {
			printf("Error, heap is full [%d],insertMinHeapAH()\n", 
				pHeap->maxElementCount);
			return;
		}
		
		pHeap->currentElementCount++;
		i =  pHeap->currentElementCount;
		while((i != 1) && (element.key < pHeap->pElement[i/2].key)) {
			pHeap->pElement[i] = pHeap->pElement[i/2];
			i /= 2;
		}
		pHeap->pElement[i] = element;
	}
}

// �ּ� ������ ����
HeapNode* deleteMinHeapAH(ArrayMinHeap* pHeap)
{
	HeapNode* pReturn = NULL;
	HeapNode* pTemp = NULL;

	int i = 0;
	int parent =0, child = 0;

	if (pHeap != NULL && pHeap->currentElementCount >  0) {
		pReturn = (HeapNode*)malloc(sizeof(HeapNode));
		if (pReturn == NULL) {
			printf("Error, malloc() in deleteMinHeapAH()\n");
			return NULL;
		}
		*pReturn = pHeap->pElement[ 1 ];

		i =  pHeap->currentElementCount;
		pTemp = &(pHeap->pElement[ i ]);
		pHeap->currentElementCount--;

		parent = 1;
		child = 2;
		while(child <= pHeap->currentElementCount) {
			if ((child < pHeap->currentElementCount)
				&& pHeap->pElement[ child ].key > pHeap->pElement[ child+1 ].key) {
				child++;
			}
			if (pTemp->key <= pHeap->pElement[ child ].key) {
				break;
			}

			pHeap->pElement[ parent ] = pHeap->pElement[ child ];
			parent = child;
			child *= 2;
		}
		pHeap->pElement[ parent ] = *pTemp;
	}

	return pReturn;
}

// ���� ���� ���
void displayArrayHeap(ArrayMaxHeap* pHeap)
{
	int i = 0;
	if (pHeap != NULL) {
		for(i = 1; i <= pHeap->currentElementCount; i++) {
			printf("[%d],%d\n", i, pHeap->pElement[i]);
		}
	}
}