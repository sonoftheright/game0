/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-02-01 11:45:02
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <string>
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
int main(int argc, char *args[]){
	if(argc > 1)
	{
		double result = 0;
		int ascii, length = 0;
		char * argument = args[1];
		while(argument[length] != 0x00)
		{
			ascii = (int) argument[length];
			result += (double) ascii;
			length++;
		}
		printf("Custom seed: %.0f\n", result);

		srand(result); //take the first argument as seed
	}
	else
		srand(WORLD_SEED);

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
	int x = rand() % w, y = rand() % h, z = rand() % d;
	printMapAtPos(&_mP->GRID[x][y][z]);
 	printMapAtPos(&_mP->GRID[0][23][56]);
 	ENTITY_PROPERTIES Player;
 	Player.P = &_mP->GRID[120][60][15];
 	Player.X_POSITION = 124.5f;
 	Player.Y_POSITION = 60.5f;
 	Player.Z_POSITION = 15.5f;
 	Player.OBJECTS = APPLE | ORANGE;
 	Player.EQUIPPED = CLOTHES_MEAGER | LAMP;
 	printf("Player inventory from binary shifts: %d\n", Player.OBJECTS);
 	printf("Player equipped items from binary shifts: %d\n", Player.EQUIPPED);
 	printf("Does player have a lamp? %d\n", (int) (Player.EQUIPPED & LAMP));
 	printf("Size of map: %f\n", (double) sizeof(*_mP));
 	printf("Size of POS: %f\n", (double) sizeof(POS));
 	printf("Size of PLAYER_PROPERTIES: %f\n", (double) sizeof(PLAYER_PROPERTIES));
 	printf("Size of POS_PROPERTIES: %f\n", (double) sizeof(POS_PROPERTIES));

	system("PAUSE");
	return 0;
}