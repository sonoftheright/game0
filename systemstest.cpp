/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-02-21 11:38:37
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include "systemstest.h"
#include "perlin.cpp"

//$IO
void
printMapAtPos(MAP_BUFFER *m, POS *p)
{
	float 	sMB,
			numElements,
			zSize,
			cSize,
			hSize,
			wSize,
			xSize,
			ySize;
	int 	sPos,
			chunkX,
			chunkY,
			sizeChunkX,
			sizeChunkY,
			posX,
			posY,
			posZ;
	sPos = sizeof(POS);									//size of a position struct
	sMB  = sizeof(MAP_BUFFER) / sPos;					// size of a full map buffer
	numElements = (float) ((long)p - (long)m) / sPos;	// number of elements before the current position
	zSize = WORLD_HEIGHT;								// size of a z-column of positions
	cSize = zSize * CHUNK_SIDE_SIZE * CHUNK_SIDE_SIZE;	// size of a chunk
	hSize = cSize * MAP_BUFFER_HEIGHT;					// size of a two dimensional array of chunks
	wSize = hSize * MAP_BUFFER_WIDTH;					// size of a cube of chunks
	//calculate which chunk we're in
	chunkX = numElements / hSize;
	chunkY = (numElements - (hSize * chunkX)) / cSize;
	//calculate the referred position within that chunk
	numElements -= (chunkX * hSize) + (chunkY * cSize); // subtract the chunks of positions before us
	zSize = 1.0f;
	ySize = zSize * WORLD_HEIGHT;
	xSize = ySize * CHUNK_SIDE_SIZE;

	posX  		=  numElements / xSize;
	numElements -= posX * xSize;
	posY  		=  numElements / ySize;
	numElements -= posY * ySize;
	posZ 		=  numElements / zSize;
	POS pos = m->C[chunkX][chunkY].GRID[posX][posY][posZ];
	#if 0
		printf("sPos: %d\n", 			sPos);
		printf("sMB: %.2f\n", 			sMB);
		printf("numElements: %.2f\n", 	numElements);
		printf("zSize: %.2f\n", 		zSize);
		printf("cSize: %.2f\n", 		cSize);
		printf("hSize: %.2f\n", 		hSize);
		printf("wSize: %.2f\n", 		wSize);
		printf("sizeChunkX: %d\n", 		sizeChunkX);
		printf("sizeChunkY: %d\n", 		sizeChunkY);
		printf("chunkX: %d\n", 			chunkX);
		printf("chunkY: %d\n", 			chunkY);
	#endif
	printf("This will only print point data... x: %d y: %d z: %d\n n: %.4f\n",
			posX, posY, posZ, pos.N);
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
 	float xPerlin, yPerlin, zPerlin;
 	for(int wit = 0; wit < w; wit++)
 	{
 		for(int hit = 0; hit < h; hit++)
 		{
 			for(int chunkX = 0; chunkX < CHUNK_SIDE_SIZE; chunkX++)
 			{
 				for(int chunkY = 0; chunkY < CHUNK_SIDE_SIZE; chunkY++)
 				{
 					for(int chunkZ = 0; chunkZ < d; chunkZ++)
 					{
 						xPerlin = (wit * CHUNK_SIDE_SIZE) + (chunkX * 0.01f);
 						yPerlin = (hit * CHUNK_SIDE_SIZE) + (chunkY * 0.01f);
 						zPerlin = chunkZ;
						_mP->C[wit][hit].GRID[chunkX][chunkY][chunkZ].N =
							Perlin(xPerlin, yPerlin, zPerlin);
						if(chunkX == 1 && chunkY == 1 && chunkZ == 1 && wit == 2){
							printMapAtPos(_mP, &_mP->C[wit][hit].GRID[chunkX][chunkY][chunkZ]);
							printf("x: %0.2f y: %0.2f z: %0.2f\n", xPerlin, yPerlin, zPerlin);
						}
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
	printMapAtPos(_mP, &_mP->C[x][y].GRID[x][y][z]);
	printMapAtPos(_mP, &_mP->C[5][15].GRID[5][5][65]);
 	printMapAtPos(_mP, &_mP->C[0][1].GRID[0][5][65]);
 	PLAYER_PROPERTIES Player;
 	Player.P = &_mP->C[5][15].GRID[12][15][61];
 	Player.X_POSITION = 124.5f;
 	Player.Y_POSITION = 60.5f;
 	Player.Z_POSITION = 15.5f;
 	Player.OBJECTS = APPLE | ORANGE;
 	Player.EQUIPPED = CLOTHES_MEAGER | LAMP;

 	printf("Size of map in bytes: %f\n", (double) sizeof(*_mP));

	//system("PAUSE");
	return 0;
}