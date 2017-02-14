/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-02-14 10:44:35
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
	printf("This will only print point data... x: %.1f y: %.1f z: %.1f\n",
			p->X, p->Y, p->Z);
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
 	memset(_mP, 0, sizeof(*_mP));
 	int w = MAP_BUFFER_WIDTH * CHUNK_SIDE_SIZE,
 		h = MAP_BUFFER_HEIGHT * CHUNK_SIDE_SIZE,
 		d = MAP_BUFFER_DEPTH * CHUNK_SIDE_SIZE;
	printf("Populating map.\n");
 	clock_t t;
 	t = clock();
 	for(int wit = 0; wit < w; wit++)
 	{
 		for(int hit = 0; hit < h; hit++)
 		{
 			for(int dit = 0; dit < d; dit++)
 			{
 				srand(SEED);
				_mP->GRID[wit][hit][dit].X = (float) wit; //width iterator
 				_mP->GRID[wit][hit][dit].Y = (float) hit; //height iterator
				_mP->GRID[wit][hit][dit].Z = (float) dit; //depth iterator
 			}
 		}
 	}
 	printf("Initializing permutation array.\n");
 	initializePermutationArray(SEED);
 	t = clock() - t;
 	double time_taken = ((double) t)/CLOCKS_PER_SEC;
 	printf("Map population took: %.5f seconds.\n", time_taken);
	int x = rand() % w, y = rand() % h, z = rand() % d;
	printMapAtPos(&_mP->GRID[x][y][z]);
 	printMapAtPos(&_mP->GRID[0][23][56]);
 	PLAYER_PROPERTIES Player;
 	Player.P = &_mP->GRID[120][60][15];
 	Player.X_POSITION = 124.5f;
 	Player.Y_POSITION = 60.5f;
 	Player.Z_POSITION = 15.5f;
 	Player.OBJECTS = APPLE | ORANGE;
 	Player.EQUIPPED = CLOTHES_MEAGER | LAMP;

 	printf("Size of map in bytes: %f\n", (double) sizeof(*_mP));

	system("PAUSE");
	return 0;
}