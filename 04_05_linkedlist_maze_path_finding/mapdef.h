#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

// direction offset
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
	{0,-1}, // up
	{1,0},// right
	{0,1}, // down
	{-1,0}	// left
};

enum PosStatus {NOT_VISIT=0,WALL=1,VISIT=2};

typedef struct MapPositionType
{
	int x;
	int y;
	int direction;
} MapPosition;

#endif // !_MAP_DEF_
