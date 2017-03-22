#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <Windows.h>
#include <wchar.h>
#define width 256
#define height 256
#define colour 255
#define PI 3.14159265

int main()
{
	int i, j, cycles, array[width][height][3], y, x;
	printf("How many cycles would you like?\t");
	scanf("%d", &cycles);
	while (cycles > 7)
	{
		printf("%d is too high. Please select a value of 7 or less\n", cycles);
		printf("How many cycles would you like?\t");
		scanf("%d", &cycles);

	}
	for (x = 0; x < width; x++)
	{
		y = (height / 2) + (height / 2) * sin(2 * PI * (x*cycles / (double)width));
		array[y][x][0] = 255, array[y][x][1] = 128, array[y][x][2] = 0;
	}
	FILE *f = fopen("file.ppm", "w");
	if (f == NULL)
	{
		printf("Oops, we cannot open the specified file\n");
		exit(1);
	}
	fprintf(f, "P3\n%d %d\n%d\n", width, height, colour);
	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
		{
			fprintf(f, "%d %d %d ", array[i][j][0], array[i][j][1], array[i][j][2]);
		}
	fclose(f);
	return 0;
}
