/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-29 14:01
*/


typedef CHUNK_SIZE 		64;
typedef MAP_SIDE_SIZE 	64;
typedef MAP_HEIGHT SIZE 16;

struct POS
{
	float X  ;
	float Y;
};

typedef struct MAP_BUFFER
{
	struct POS GRID[CHUNK_SIZE * MAP_SIZE * MAP_SIZE * MAP_HEIGHT_SIZE];
} MAP_BUFFER;
