#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

#define _CRT_SECURE_NO_WARNINGS // strcpy,strcat unsafe error

////templeaate
//char* reverseString(char* pSource)
//{
//
//}
//
//int checkBraketMatching(char* pSource)
//{
//
//}

//// using stack , see another using array solution below
char* reverseString(char* pSource)
{
	char* pReturn = NULL;
	int i = 0, size = 0;
	LinkedStack* pStack = NULL;
	StackNode* pNode = NULL;

	if (pSource == NULL) {
		return NULL;
	}

	size = strlen(pSource);
	if (size == 0) {
		return NULL;
	}
	
	// consider '\0' charactor
	pReturn = (char*)malloc(sizeof(char) * (size+1));
	if (pReturn == NULL) {
		printf("Error : pReturn malloc\n");
		return NULL;
	}

	//create Stack
	pStack = createLinkedStack();
	if (pStack != NULL) {
		StackNode node;
		for (i = 0; i < size; i++) {
			node.data = pSource[i];
			pushLS(pStack, node);
		}		
		
		for (i = 0; i < size; i++) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				pReturn[i] = pNode->data;
				free(pNode);
			}			
		}

		//pReturn[i] = '0'; // Error!!!
		pReturn[i] = '\0';
		deleteLinkedStack(pStack);
	}
	else {		
		free(pReturn);
		pReturn = NULL;
	}


	return pReturn;
}

//// using array
//char* reverseString(char* pSource)
//{
//	int size = strlen(pSource);
//	char* reverse=NULL;
//
//	reverse = (char*)malloc(sizeof(char) * (size+1));
//	if (reverse != NULL) {
//		for (int i = 0; i < size; i++) {
//			reverse[i] = pSource[size - 1 - i];
//		}
//		reverse[size] = '\0';		
//	}
//
//	return reverse;
//}

// ref sol
int checkBracketMatching(char* pSource)
{
	int ret = TRUE, i = 0, size = 0;
	char symbol = '\0', checkSymbol = '\0';
	//char left = '\0', right = '\0';
	LinkedStack* pStack = NULL;
	StackNode* pNode = NULL;

	if (pSource == NULL) {
		ret = TRUE;
		return ret;
	}

	size = strlen(pSource);
	if (size == 0) {
		ret = TRUE;
		return ret;
	}

	pStack = createLinkedStack();
	if (pStack != NULL) {
		StackNode node;		
		// check bracket matching shifting chracters in string
		for (i = 0; i < size && ret == TRUE; i++) {
			symbol = pSource[i];
			switch (symbol) {
			case '(':
			case '[':
			case '{':
				node.data = symbol;
				pushLS(pStack, node);
				break;
			case')':
			case']':
			case'}':
				pNode = popLS(pStack);
				if (pNode == NULL) {
					ret = FALSE;
					break;
				}
				else {
					checkSymbol = pNode->data;
					if ((symbol==')'&&checkSymbol=='(')
						|| (symbol == '}' && checkSymbol == '{')
						|| (symbol == ']' && checkSymbol == '[')) {
						// Right case. do nothing
					}
					else {
						ret = FALSE;
					}
					free(pNode);
				}
				break;
			} // end of switch
		}// end for

		if (isLinkedStackEmpty(pStack)==FALSE) {
			ret = FALSE;
		}
		deleteLinkedStack(pStack);
	}
	else {
		printf("Error : Fail to create stack\n");
	}

	return ret;
}
