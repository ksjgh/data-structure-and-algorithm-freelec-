#ifndef _POLYLIST_
#define _POLYLIST_

//#include "linkedlist.h"

int addPolyNodeLast(LinkedList* pList, float coef, int degree);
LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB);
void displayPolyList(LinkedList* pList);

#endif // !_POLYLIST_
