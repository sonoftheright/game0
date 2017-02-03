//perlin.cpp

int permutationArray[255] = {0};

void initializePermutationArray(int seed)
{
	if(permutationArray[0] == 0 && permutationArray[1] == 0)
	{
		for(int x = 0; x <= 255; x++) {	permutationArray[x]	= x; }
	}
	srand(seed);
	for(int r = 255; r >= 0; r--)
	{
		int temp = permutationArray[rand() % (r)];
		permutationArray[temp] = permutationArray[r];
		permutationArray[r] = temp;
	}
}

// float[] perlin(float x, float y, float z)
// {
	
// }