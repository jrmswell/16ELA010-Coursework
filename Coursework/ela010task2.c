#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#define width 256
#define height 256
#define colour 256
#define PI 3.14159265

int main()
{
	int i, j, k, array[width][height][3];
	FILE *f = fopen("file.ppm", "w");
	if (f == NULL)
	{
		printf("Oops, we cannot open the specified file\n");
		exit(1);
	}
	fprintf(f, "P3\n%d %d\n%d\n", width, height, colour);
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			array[i][j][0] = i;
			array[i][j][1] = j;
			array[i][j][2] = j;
			fprintf(f, "%d %d %d ", array[i][j][0], array[i][j][1], array[i][j][2]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
