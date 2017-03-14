#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main()
{
	int i, j, k, array[10][40];
	FILE *f = fopen("file.ppm", "w");
	if (f == NULL)
	{
		printf("Oops, we cannot open the specified file\n");
		exit(1);
	}
	
	fprintf(f, "P3\n10 10\n48\n");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 40; j++)
		{
			array[i][j] = i+j;
			fprintf(f, "%d%d%d ", array[i][j], array[i][j], array[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
}