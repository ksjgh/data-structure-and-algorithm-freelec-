#include <stdio.h>
#include <stdlib.h>

#include "mapdef.h"
#include "maplinkedstack.h"
#include "maputil.h"

int main(int argc, char* argv[]) {

	LinkedStack* pStack = NULL;
	MapPosition startPos, endPos;

	int mazeArray[HEIGHT][WIDTH] = {
		{0, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0}
	};

	// create stack
	pStack = createLinkedStack();
	if (pStack != NULL) {
		startPos.x = 0;
		startPos.y = 0;
		endPos.x = 7;
		endPos.y = 7;

		printMaze(mazeArray);

		findpath(mazeArray, startPos, endPos, pStack);
		showPath(pStack, mazeArray);
		
		deleteLinkedStack(pStack);
	}

	return 0;
}