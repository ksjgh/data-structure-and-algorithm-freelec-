#include <stdio.h>
#include <stdlib.h>
#include "mapdef.h"
#include "maplinkedstack.h"
#include "maputil.h"


//// template
//void findpath(int mazeArray[HEIGHT][WIDTH],
//	MapPosition startPos,
//	MapPosition endPos,
//	LinkedStack* pStack)
//{
//
//}
//
//int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
//{
//
//}
//
//void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH])
//{
//
//}
//
//void printMaze(int mazeArray[HEIGHT][WIDTH])
//{
//
//}


// my refactoring
void findpath(int mazeArray[HEIGHT][WIDTH],
				MapPosition startPos,
				MapPosition endPos,
				LinkedStack* pStack)
{
	StackNode* pNode = NULL;
	int isEmpty = FALSE, isFound = FALSE, i = 0;
	int markArray[HEIGHT][WIDTH] = { 0, };

	if (pStack != NULL) {
		MapPosition currentPosition = startPos;
		currentPosition.direction = -1;
		pushLSMapPosition(pStack, currentPosition);
		while (isEmpty == FALSE && isFound == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;
				int direction = pNode->data.direction + 1; // next direction

				while (isFound == FALSE && direction < NUM_DIRECTIONS) {
					int newX = x + DIRECTION_OFFSETS[direction][0];
					int newY = y + DIRECTION_OFFSETS[direction][1];

					if (newX >= 0 && newX <= WIDTH && newY >= 0 && newY <= HEIGHT
						&& mazeArray[newY][newX] != WALL
						&& markArray[newY][newX] == NOT_VISIT) {

						//MapPosition currentPosition;
						currentPosition.x = x;
						currentPosition.y = y;
						//currentPosition.direction = direction + 1;
						currentPosition.direction = direction;

						pushLSMapPosition(pStack, currentPosition);
						markArray[y][x] = VISIT;

						x = newX;
						y = newY;
						direction = UP;

						if (newX == endPos.x && newY == endPos.y) {
							isFound = TRUE;
							currentPosition.x = newX;
							currentPosition.y = newY;
							currentPosition.direction = UP;
							pushLSMapPosition(pStack, currentPosition);
							markArray[newX][newY] = VISIT;
						}
					}
					else { // if new position is not available
						direction++; // search next direction
					}
				}// end-of-inner-while

				 // poped element should be deleted , cf) pNode = popLS(pStack)
				free(pNode);
			}//end-of-if			
			isEmpty = isLinkedStackEmpty(pStack);
		}//end-of-outer-while		
	}

}


//// ref sol
//void findpath(int mazeArray[HEIGHT][WIDTH],
//	MapPosition startPos,
//	MapPosition endPos,
//	LinkedStack* pStack)
//{
//	StackNode* pNode = NULL;
//	int isEmpty = FALSE, isFound = FALSE, i = 0;
//	int markArray[HEIGHT][WIDTH] = { 0, };
//
//	if (pStack != NULL) {
//		MapPosition newPosition = startPos;
//		newPosition.direction = UP;
//		pushLSMapPosition(pStack, newPosition);
//		while (isEmpty == FALSE && isFound == FALSE) {
//			pNode = popLS(pStack);
//			if (pNode != NULL) {
//				int x = pNode->data.x;
//				int y = pNode->data.y;
//				int direction = pNode->data.direction;
//
//				while (isFound == FALSE && direction < NUM_DIRECTIONS) {
//					int newX = x + DIRECTION_OFFSETS[direction][0];
//					int newY = y + DIRECTION_OFFSETS[direction][1];
//
//					if (newX >= 0 && newX <= WIDTH && newY >= 0 && newY <= HEIGHT
//						&& mazeArray[newY][newX] == NOT_VISIT
//						&& markArray[newY][newX] == NOT_VISIT) {
//						MapPosition newPosition;
//						newPosition.x = x;
//						newPosition.y = y;
//						newPosition.direction = direction + 1;
//						pushLSMapPosition(pStack, newPosition);
//						markArray[y][x] = VISIT;
//
//						x = newX;
//						y = newY;
//						direction = 0;
//
//						if (newX == endPos.x && newY == endPos.y) {
//							isFound = TRUE;
//							newPosition.x = newX;
//							newPosition.y = newY;
//							newPosition.direction = 0;
//							pushLSMapPosition(pStack, newPosition);
//							markArray[newX][newY] = VISIT;
//						}
//					}
//					else {
//						direction++;
//					}
//				}// end-of-inner-while
//				free(pNode);
//			}//end-of-if			
//			isEmpty = isLinkedStackEmpty(pStack);
//		}//end-of-outer-while		
//	}
//	
//}

int pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
	StackNode node = { 0, };
	node.data = data;
	return pushLS(pStack, node);
}

//void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH])
//{
//	StackNode* pNode = NULL;
//	int resultArray[HEIGHT][WIDTH] = { 0, };
//	int isEmpty = FALSE;
//
//	int i, j;
//	for (i = 0; i < HEIGHT; i++) {
//		for (j = 0; j < WIDTH; j++) {
//			resultArray[i][j] = mazeArray[i][j];
//		}
//	}
//
//	if (pStack != NULL) {
//		i = 0;
//		while (isEmpty == FALSE) {
//			pNode = popLS(pStack);
//			if (pNode != NULL) {
//				int x = pNode->data.x;
//				int y = pNode->data.y;
//				resultArray[y][x] = VISIT;
//
//				if (i > 0) {
//					printf("<-");
//				}
//				printf("(%d,%d) ", x, y);
//
//				i++;
//				free(pNode);
//			}
//			isEmpty = isLinkedStackEmpty(pStack);
//		}
//		printf("\n");
//		printMaze(resultArray);
//	}
//}

// my sol , display arrow
void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode* pNode = NULL;
	int resultArray[HEIGHT][WIDTH] = { 0, };
	int isEmpty = FALSE;

	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			resultArray[i][j] = mazeArray[i][j];
		}
	}

	if (pStack != NULL) {
		i = 0;
		while (isEmpty == FALSE) {
			pNode = popLS(pStack);
			if (pNode != NULL) {
				int x = pNode->data.x;
				int y = pNode->data.y;
				int direction = pNode->data.direction;

				switch (direction) {
					case UP:
						resultArray[y][x] = '^';
						break;
					case RIGHT:
						resultArray[y][x] = '>';
						break;
					case DOWN:
						resultArray[y][x] = 'v';
						break;
					case LEFT:
						resultArray[y][x] = '<';
						break;
				}				

				if (i > 0) {
					printf("<-");
				}
				printf("(%d,%d) ", x, y);

				i++;
				free(pNode); // see, pNode = popLS(pStack)
			}
			isEmpty = isLinkedStackEmpty(pStack);
		}
		printf("\n");
		printMaze(resultArray);
	}
}


//// ref sol
//void printMaze(int mazeArray[HEIGHT][WIDTH])
//{
//	int i, j;
//	for (i = 0; i < HEIGHT; i++) {
//		for (j = 0; j < WIDTH; j++) {
//			if (mazeArray[i][j] == WALL) {
//				printf("*");
//			}
//			else if (mazeArray[i][j] == VISIT){
//				printf(".");
//			}
//			else {
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//}

// my sol , diplay arrow
void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			if (mazeArray[i][j] == WALL) {
				printf("*");
			}
			else if (mazeArray[i][j] == NOT_VISIT) {
				printf(" ");
			}
			else {
				printf("%c", mazeArray[i][j]);
			}
		}
		printf("\n");
	}
}


