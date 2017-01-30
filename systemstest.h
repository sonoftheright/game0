/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-29 14:01
*/
#define CHUNK_SIZE 64
#define MAP_SIDE_SIZE 64
#define MAP_HEIGHT_SIZE 16

typedef struct POS
{
	float X;
	float Y;
} POS;

typedef struct MAP_BUFFER
{
	struct POS GRID[CHUNK_SIZE * MAP_SIDE_SIZE * MAP_SIDE_SIZE * MAP_HEIGHT_SIZE];
} MAP_BUFFER;

typedef struct MAP_PROPERTIES
{
	int X_OFFSET;
	int Y_OFFSET;
} MAP_PROPERTIES;

