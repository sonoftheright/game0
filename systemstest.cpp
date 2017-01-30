/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-30 11:40:24
*/

#include <stdlib.h>
#include <stdio.h>
#include "systemstest.h"
#include "systemstestio.cpp"

void
MoveMapFocus(DIRECTION d)
{
	switch(d)
	{
		case(NORTH):
		{

		} break;
		case(NORTHWEST):
		{

		} break;
		case(WEST):
		{

		} break;
		case(SOUTHWEST):
		{

		} break;
		case(SOUTH):
		{

		} break;
		case(SOUTHEAST):
		{

		} break;
		case(EAST):
		{

		} break;
		case(NORTHEAST):
		{

		} break;
		case(UP):
		{

		} break;
		case(DOWN):
		{

		} break;
		default:
		{
			printf("Can't go in that direction, fam.\n");
		} break;
	}
}

int main(){
 	MAP_BUFFER *_mP = (MAP_BUFFER *)malloc(sizeof(MAP_BUFFER));
 	int w = MAP_WIDTH_SIZE, h = MAP_HEIGHT_SIZE, d = MAP_DEPTH_SIZE, c = CHUNK_SIZE;
 	struct POS *p = &_mP->GRID[0];

 	for(float wit = 0.0f; wit < w; wit++)
 	{
 		for(float hit = 0.0f; hit < h; hit++)
 		{
 			for(float dit = 0.0f; dit < d; dit++)
 			{
 				for(float chunk = 0.0f; chunk < c; chunk++)
 				{
 					p->X = (wit * c) + (c % chunk);
 					p->Y = hit;
 					p->Z = dit;
 					p++;
 				}
 			}
 		}
 	}
 	printMapAtPos(&_mP->GRID[0]);
 	printf("Size of map: %f\n", (double) sizeof(*_mP));
	system("PAUSE");
	return 0;
}