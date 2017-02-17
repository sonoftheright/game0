/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-02-16 14:31:45
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
#include "systemstest.h"
#include "perlin.cpp"

//$IO
void
printMapAtPos(POS *p)
{
	printf("This will only print point data... x: %.3f y: %.3f z: %.3f\n n: %.5f\n",
			p->X, p->Y, p->Z, p->N);
}

void
ToggleObjectFlag(PLAYER_PROPERTIES * e, OBJECT_FLAGS o)
{
	if((e->OBJECTS & o) == o) { e->OBJECTS |= (~o); }
	else 					 { e->OBJECTS |= o; }
}

void
ToggleEquippedFlag(PLAYER_PROPERTIES * e, EQUIPPABLE_OBJECTS q)
{
	if((e->EQUIPPED & q) == q) { e->EQUIPPED &= (~q); printf("Lamp should have been turned off.\n");}
	else 					 { e->EQUIPPED |= q; printf("Lamp should have been turned on.\n");}
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

void setSeed(char * argument)
{
	double result = 0;
	int ascii, length = 0;
	while(argument[length] != 0x00)
	{
		// current digit is in ones place, so shift things over.
		result *= 10;
		// check to see if the entry is a number; in which case, use the number
		if(argument[length] > 47 && argument[length] < 58)
			result += (double) argument[length] - 48;
		else
			result += (double) argument[length];
		length++;
	}
	SEED = result;
	printf("Using SEED: %.0f\n", SEED);
}

//$MAIN
int main(int argc, char *args[]){
	if(argc > 1) { setSeed(args[1]); }
	else
		SEED = DEFAULT_SEED;
 	printf("Allocating memory for map.\n");
 	MAP_BUFFER *_mP = (MAP_BUFFER *)malloc(sizeof(MAP_BUFFER));
 	memset(_mP, 0, sizeof(MAP_BUFFER));
 	int w = MAP_BUFFER_WIDTH,
 		h = MAP_BUFFER_HEIGHT,
 		d = WORLD_HEIGHT;
	printf("Populating map.\n");
 	clock_t t;
 	t = clock();
 	CHUNK curChunk;
 	for(int wit = 0; wit < w; wit++)
 	{
 		for(int hit = 0; hit < h; hit++)
 		{
 			curChunk = _mP->C[wit][hit];
 			for(int chunkX = 0; chunkX < CHUNK_SIDE_SIZE; chunkX++)
 			{
 				for(int chunkY = 0; chunkY < CHUNK_SIDE_SIZE; chunkY++)
 				{
 					for(int chunkZ = 0; chunkZ < d; chunkZ++)
 					{
 						curChunk.GRID[chunkX][chunkY][chunkZ].X = chunkX*0.01f;
 						curChunk.GRID[chunkX][chunkY][chunkZ].Y = chunkY*0.01f;
 						curChunk.GRID[chunkX][chunkY][chunkZ].Z = chunkZ*0.01f;
 						curChunk.GRID[chunkX][chunkY][chunkZ].N =
 							Perlin(
 									curChunk.GRID[chunkX][chunkY][chunkZ].X + wit,
 									curChunk.GRID[chunkX][chunkY][chunkZ].Y + hit,
 									curChunk.GRID[chunkX][chunkY][chunkZ].Z + chunkZ
 							);
 					}
 				}
 			}
 		}
 	}
 	printf("Initializing permutation array.\n");
 	initPermArray(SEED);
 	t = clock() - t;
 	double time_taken = ((double) t)/CLOCKS_PER_SEC;
 	printf("Map population took: %.5f seconds.\n", time_taken);
	int x = rand() % w, y = rand() % h, z = rand() % d;
	printMapAtPos(&_mP->C[x][y].GRID[x][y][z]);
	printMapAtPos(&_mP->C[0][0].GRID[0][0][65]);
 	printMapAtPos(&_mP->C[0][1].GRID[0][5][65]);
 	PLAYER_PROPERTIES Player;
 	Player.P = &_mP->C[5][16].GRID[12][15][61];
 	Player.X_POSITION = 124.5f;
 	Player.Y_POSITION = 60.5f;
 	Player.Z_POSITION = 15.5f;
 	Player.OBJECTS = APPLE | ORANGE;
 	Player.EQUIPPED = CLOTHES_MEAGER | LAMP;

 	printf("Size of map in bytes: %f\n", (double) sizeof(*_mP));

	system("PAUSE");
	return 0;
}