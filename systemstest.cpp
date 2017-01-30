/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-30 08:20:20
*/

#include <stdlib.h>
#include <stdio.h>
#include "systemstest.h"


int main(){
 	MAP_BUFFER *_mP = (MAP_BUFFER *)malloc(sizeof(MAP_BUFFER));
 	int iterator = MAP_SIDE_SIZE * MAP_SIDE_SIZE * MAP_HEIGHT_SIZE;
 	struct POS *p = &_mP->GRID[0];

 	for(int x = 0; x < iterator; x++)
 	{
 		p->X = 1.0f;
 		p->Y = 1.0f;
 		p++;
 	}
 	printf("Size of map: %f\n", (double) sizeof(*_mP));
	system("PAUSE");
	return 0;
}