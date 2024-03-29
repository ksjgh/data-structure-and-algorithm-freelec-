#ifndef _STACK_CALC_
#define _STACK_CALC_

void calcExpr(ExprToken* pExprTokens, int tokenCount);
int pushLSExprToken(LinkedStack* pStack, ExprToken data);
void convertInfixToPostfix(ExprToken* pExprTokens, int tokenCount);
int isStackPrecedence(Precedence oper);
int outStackPrecedence(Precedence oper);
void printToken(ExprToken element);

#endif // !_STACK_CALC_
