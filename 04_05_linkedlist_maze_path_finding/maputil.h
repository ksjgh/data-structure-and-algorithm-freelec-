#ifndef _MAP_UTIL_
#define _MAP_UTIL_

void findpath(int mazeArray[HEIGHT][WIDTH],
				MapPosition startPos,
				MapPosition endPos,
				LinkedStack* pStack);

int pushLSMapPosition(LinkedStack* pStack, MapPosition data);
void showPath(LinkedStack* pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif // !_MAP_UTIL_
