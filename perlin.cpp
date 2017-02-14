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

void initializePermutationArray(int seedArgument)
{
	if(permutationArray[0] == 0 && permutationArray[1] == 0)
	{
		for(int x = 0; x <= 255; x++) {	permutationArray[x]	= x; }
	}
	srand(seedArgument);
	shuffleIntArray(255, permutationArray);
}

// float[] perlin(float x, float y, float z)
// {
// }