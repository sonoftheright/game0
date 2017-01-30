/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-30
*/
#define CHUNK_SIZE 		16
#define MAP_WIDTH_SIZE 	32
#define MAP_HEIGHT_SIZE 32
#define MAP_DEPTH_SIZE 	8

typedef struct POS
{
	float X;
	float Y;
	float Z;
} POS;

typedef struct MAP_BUFFER
{
	struct POS GRID[CHUNK_SIZE * MAP_SIDE_SIZE * MAP_SIDE_SIZE * MAP_HEIGHT_SIZE];
} MAP_BUFFER;

typedef struct MAP_PROPERTIES
{
	POS *X_ORIGIN;
	POS *Y_ORIGIN;
	POS *Z_ORIGIN;
} MAP_PROPS;

typedef enum DIRECTION
{
	NORTH, NORTHWEST, WEST, SOUTHWEST,
	SOUTH, SOUTHEAST, EAST, NORTHEAST,
	UP, DOWN
} DIRECTION;

void MoveMapFocus(DIRECTION);