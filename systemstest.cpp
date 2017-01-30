/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-30 15:46:50
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "systemstest.h"
//$IO
void
printMapAtPos(POS *p) 
{ 
	printf("This will only print point data... x: %.1f y: %.1f z: %.1f\n", 
			p->X, p->Y, p->Z); 
}

//$MAP
void
MoveMapFocus(DIRECTION d)
{
	switch(d)
	{
		case(NORTH): 		{ 		} break;
		case(NORTHWEST):	{ 		} break;
		case(WEST):			{ 		} break;
		case(SOUTHWEST):	{ 		} break;
		case(SOUTH):		{ 		} break;
		case(SOUTHEAST):	{ 		} break;
		case(EAST):			{ 		} break;
		case(NORTHEAST):	{ 		} break;
		case(UP):			{ 		} break;
		case(DOWN):			{ 		} break;
		default:			{ printf("Can't go in that direction, fam.\n"); } break;
	}
}

//$MAIN
int main(){
 	MAP_BUFFER *_mP = (MAP_BUFFER *)malloc(sizeof(MAP_BUFFER));
 	int w = MAP_BUFFER_WIDTH * CHUNK_SIDE_SIZE, 
 		h = MAP_BUFFER_HEIGHT * CHUNK_SIDE_SIZE, 
 		d = MAP_BUFFER_DEPTH * CHUNK_SIDE_SIZE;

 	clock_t t;
 	t = clock();
 	for(int wit = 0; wit < w; wit++)
 	{
 		for(int hit = 0; hit < h; hit++)
 		{
 			for(int dit = 0; dit < d; dit++)
 			{
				_mP->GRID[wit][hit][dit].X = (float) wit;
 				_mP->GRID[wit][hit][dit].Y = (float) hit;
				_mP->GRID[wit][hit][dit].Z = (float) dit;
 			}
 		}
 	}
 	t = clock() - t;
 	double time_taken = ((double) t)/CLOCKS_PER_SEC;
 	printf("Map population took: %.10f seconds.\n", time_taken);
 	time_t tm;
	srand((unsigned) time(&tm) * 1000);
	int x = rand() % w; 
	int y = rand() % h; 
	int z = rand() % d;
	printMapAtPos(&_mP->GRID[x][y][z]);
 	printMapAtPos(&_mP->GRID[0][23][56]);
 	printf("Size of map: %f\n", (double) sizeof(*_mP));
 	printf("Size of POS: %f\n", (double) sizeof(POS));
 	printf("Size of POS_PROPERTIES: %f\n", (double) sizeof(POS_PROPERTIES));

	system("PAUSE");
	return 0;
}