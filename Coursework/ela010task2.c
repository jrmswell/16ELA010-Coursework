#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

main()
{
	int array[12][4];
	FILE *f = fopen("file.ppm", "w");
	if (f == NULL)
	{
		printf("Oops, we cannot open the specified file\n");
		exit(1);
	}
	const char *text = "P3\n4 4\n15\n0 0 0 0 0 0 0 0 0 15 0 15\n0 0 0 0 15 7 0 0 0 0 0 0\n0 0 0 0 0 0 0 15 7 0 0 0\n15 0 15 0 0 0 0 0 0 0 0 0"; //
	fprintf(f, "%s\n", text);
	fclose(f);
}