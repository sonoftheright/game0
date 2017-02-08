//perlin.cpp

int permutationArray[255] = {0};

void initializePermutationArray(int seedArgument)
{
	if(permutationArray[0] == 0 && permutationArray[1] == 0)
	{
		for(int x = 0; x <= 255; x++) {	permutationArray[x]	= x; }
	}
	srand(seedArgument);
	int random, temp, r = 255, i = 0;
	for(; r > 0; r--)
	{
		random = rand() % (r);
		temp = permutationArray[random];
		permutationArray[random] = permutationArray[r];
		permutationArray[r] = temp;
	}
	r = 0;
	for(; r <= 255; r++)
	{
		for(; i < 256; i++)
		{
			if(permutationArray[i] == permutationArray[r] && i != r)
			{
				printf("There's a repeat.\n");
				break;
			}
		}
	}
	printf("First element: %d, Second element: %d\n", permutationArray[0], permutationArray[1]);
}

// float[] perlin(float x, float y, float z)
// {
// }