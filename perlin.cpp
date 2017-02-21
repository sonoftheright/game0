//perlin.cpp
#define PERMUTATION_LENGTH 512

int p[PERMUTATION_LENGTH] = {0};

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

void initPermArray(int seedArgument)
{
	for(int x = 1; x <= PERMUTATION_LENGTH; x++) {	p[x-1] = x; }
	srand(seedArgument);
	shuffleIntArray(PERMUTATION_LENGTH - 1, p);
	int p[PERMUTATION_LENGTH * 2];
	for(int x = 0; x < PERMUTATION_LENGTH * 2; x++) {	p[x] = p[x%PERMUTATION_LENGTH]; }
}

double grad(int hash, double x, double y, double z)
{
	int h = hash & 15;
	double u = h < 8 ? x : y;
	double v;

	if(h < 4)
		v = y;
	else if(h == 12 || h == 14)
		v = x;
	else
		v = z;

	return (double) ((h&1) == 0 ? u : -u)+((h&2) == 0 ? v : -v);
}

double lerp(double a, double b, double x) {
    return a + x * (b - a);
}

double Perlin(double x, double y, double z)
{
	// for repeats on the permutation table - i.e., mutations repeating every 256 squares -
	// you need to see where in the repeat area the point is being placed, and then make
	// calculations from there.
	int xunit = (int)x & (PERMUTATION_LENGTH - 1);
	int yunit = (int)y & (PERMUTATION_LENGTH - 1);
	int zunit = (int)z & (PERMUTATION_LENGTH - 1);

	// capture the decimal portion of the point value ...
	double xdecimal = x-(int)x;
	double ydecimal = y-(int)y;
	double zdecimal = z-(int)z;

	// .. and use it to determine the fade.
	double u = fade(xdecimal);
	double v = fade(ydecimal);
	double w = fade(zdecimal);

	// Hashing...
	// These incremented values should be foreshortened if there's a repeat value expressed
	// that is smaller than the 256 permutation table. I.e., xunit+1 should check to see if
	// 'repeat' is being exceeded.

	int aaa, aba, aab, abb, baa, bba, bab, bbb;

	aaa = p[p[p[xunit  ]+yunit  ]+zunit  ];
    aba = p[p[p[xunit  ]+yunit+1]+zunit  ];
    aab = p[p[p[xunit  ]+yunit  ]+zunit+1];
    abb = p[p[p[xunit  ]+yunit+1]+zunit+1];
    baa = p[p[p[xunit+1]+yunit  ]+zunit  ];
    bba = p[p[p[xunit+1]+yunit+1]+zunit  ];
    bab = p[p[p[xunit+1]+yunit  ]+zunit+1];
    bbb = p[p[p[xunit+1]+yunit+1]+zunit+1];

    double x1, x2, y1, y2;
    x1 = lerp ( grad(aaa, xdecimal,   ydecimal,   zdecimal),
    			grad(baa, xdecimal-1, ydecimal,   zdecimal),
    			u);
    x2 = lerp ( grad(aba, xdecimal,   ydecimal-1, zdecimal),
    			grad(bba, xdecimal-1, ydecimal-1, zdecimal),
    			u);
    y1 = lerp(x1, x2, v);

    x1 = lerp(  grad(aab, xdecimal,   ydecimal,   zdecimal-1),
    			grad(bab, xdecimal-1, ydecimal,   zdecimal-1),
    			u);
    x2 = lerp(  grad(abb, xdecimal,   ydecimal-1, zdecimal-1),
    			grad(bbb, xdecimal-1, ydecimal-1, zdecimal-1),
    			u);
    y2 = lerp (x1, x2, v);

    return (lerp(y1, y2, w)+1)/2;
}