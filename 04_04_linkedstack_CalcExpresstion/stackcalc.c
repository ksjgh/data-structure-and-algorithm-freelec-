#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"
#include "stackcalc.h"

//// template
//void calcExpr(ExprToken* pExprTokens, int tokenCount)
//{
//
//}
//
//int pushLSExprToken(LinkedStack* pStack, ExprToken data)
//{
//
//}
//
//void convertInfixToPostfix(ExprToken* pExprTokens, int tokenCount)
//{
//
//}
//
//int inStackPrecedence(Precedence oper)
//{
//
//}
//
//int outStackPrecedence(Precedence oper)
//{
//
//}
//
//void printToken(ExprToken element)
//{
//
//}
//////////////////////////////////////////////////////////////////////////

int pushLSExprToken(LinkedStack* pStack, ExprToken data)
{
	StackNode node = { 0, };
	node.data = data;
	return pushLS(pStack, node);
}


void calcExpr(ExprToken* pExprTokens, int tokenCount)
{

}



void convertInfixToPostfix(ExprToken* pExprTokens, int tokenCount)
{

}

int inStackPrecedence(Precedence oper)
{

}

int outStackPrecedence(Precedence oper)
{

}

void printToken(ExprToken element)
{

}