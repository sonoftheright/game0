/*
* @Author: Benjamin Marquardt
* @Date:   2017-01-26 13:19:23
* @Last Modified by:   Benjamin Marquardt
* @Last Modified time: 2017-01-30
*/
#define CHUNK_SIDE_SIZE		16
#define MAP_BUFFER_WIDTH 	32
#define MAP_BUFFER_HEIGHT 	32
#define WORLD_HEIGHT		256
#define DEFAULT_SEED		3158582976

extern double SEED = DEFAULT_SEED;

typedef enum
{
	NORTH, NORTHWEST, WEST, SOUTHWEST,
	SOUTH, SOUTHEAST, EAST, NORTHEAST,
	UP, DOWN
} DIRECTION;

typedef enum
{
	SHALLOWSTAIRS, STEEPSTAIRS, LADDER,
	RAMP, ROPE, VERTICALCLIMB
} CLIMBABLE_OBJECTS;

typedef enum
{
	EMPTY, DIRT, SAND, PEBBLES, ROCK, GRASS,
	SNOW, SALTWATER, FRESHWATER, ASPHALT, GRAVEL,
	DIRTROAD, DIRTPATH, TARMAC, TURF, SMOOTHSTONE,
	HARDWOOD, BRICK, COBBLESTONE, MARBLE, CARPET,
	LINOLEUM

} GROUND_MATERIAL;

typedef enum
{
	APPLE		= 1 << 0,
	ORANGE		= 1 << 1
} OBJECT_FLAGS;

typedef enum
{
	SWORD 			= 1 << 0,
	LAMP  			= 1 << 1,
	CLOTHES_MEAGER	= 1 << 2,
	CLOTHES_FINE 	= 1 << 3,
	ARMOR_MEAGER	= 1 << 4,
	ARMOR_FINE		= 1 << 5
} EQUIPPABLE_OBJECTS;

/*
============
tile pattern
============
[0] tracks temperature
[1] tracks humidity
[2] tracks soil nutrient depletion
+++ - jungle
++- - swamp
+-- - desert
+-+ - prairie

--- - frozen desert
--+ - tundra
-++ - frozen bog
-+- - crystal forest
*/
typedef struct
{
	int x;
	int y;
	int z;
	float N;
} COORD;

typedef struct
{
	double N;
} POS;

typedef struct
{
	POS GRID[CHUNK_SIDE_SIZE]
			[CHUNK_SIDE_SIZE]
			[WORLD_HEIGHT];
} CHUNK;

typedef struct
{
	CHUNK C[MAP_BUFFER_WIDTH]
		   [MAP_BUFFER_HEIGHT];
} MAP_BUFFER;

typedef struct MAP_PROPERTIES
{
	POS *X_ORIGIN;
	POS *Y_ORIGIN;
	POS *Z_ORIGIN;
} MAP_PROPS;

typedef struct
{
	POS *P_EDGE[8]; // NW, N, NE, W, E, SW, S, SE
	POS *P;
	unsigned int OBJECTS;
	unsigned int EQUIPPED;
	int STATUS;
	float HEALTH;
	float X_POSITION;
	float Y_POSITION;
	float Z_POSITION;
} PLAYER_PROPERTIES;

void MoveMapFocus(DIRECTION);