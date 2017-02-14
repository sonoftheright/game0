//perlin.cpp

int permutationArray[255] = {0};

void shuffleIntArray(int length, int *array)
{
	int random, temp, i = 0;

	for(; length > 0; length--)
	{
		random = rand() % (length);
		temp = array[random];
		array[random] = array[length];
		array[length] = temp;
	}
	printf("First argument is %d, Second argument is %d\n", array[0], array[1]);
}

// Fade function - credit Ken Perlin and Flafla2 at 
// http://flafla2.github.io/2014/08/09/perlinnoise.html              
double fade(double t) 
{
    return t * t * t * (t * (t * 6 - 15) + 10);         
}

void initializePermutationArray(int seedArgument)
{
	for(int x = 1; x <= 256; x++) {	permutationArray[x-1] = x; }
	srand(seedArgument);
	shuffleIntArray(255, permutationArray);
	int p[512];
	for(int x = 0; x < 512; x++) {	p[x] = permutationArray[x%256]; }
}

// float[] perlin(float x, float y, float z)
// {
// }