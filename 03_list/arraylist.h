#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// 최대 원소 개수
	int currentElementCount;	// 현재 원소의 개수
	ArrayListNode* pElement;	// 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList* createList(int maxElement);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

#endif // _ARRAYLIST_

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif // _COMMON_LIST_DEF_
