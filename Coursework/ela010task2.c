#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define width 256
#define height 256
#define colour 255
#define PI 3.14159265

int main()
{
	int i, j, cycles, amplitude, array[width][height][3], y, x, r, g, b, menu, impfile;
	char options[] = "\n\t1) Help and About\n\t2) Sets the parameters\n\t3) Import parameters\n\t4) Exports your parameters to a .PPM file then opens it\n\t5) Exits the program\n\n";
	char impath;
	for (x = 0; x < width; x++)
	{
		y = ((int)round(((0 - 1) / 2 * sin(0*((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
		for (i = 0; i < 3; i++); {
			array[y][x][0] = 255, array[y][x][1] = 255, array[y][x][2] = 255;
		}
	}
	for (x = 0; x < width; x++)
	{
		y = ((int)round(((0 - 1) / 2 * sin(0 * ((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
		for (i = 0; i < 3; i++); {
			array[x][y][0] = 255, array[x][y][1] = 255, array[x][y][2] = 255;
		}
	}
	printf("Hello and welcome to the sine wave generator: for all your sine wave needs.\n\nTo get started you now have the following options: %sPlease enter the corresponding number\n\n", options);
	scanf("%d", &menu);
	while (menu == 1)
	{
		printf("\n\-----> Help\n\nHello and welcome to the sine wave generator. ");
		printf("What whould you like to do now?\nYour choices are:%s", options);
		scanf("%d", &menu);
	}

	while (menu == 2)
	{
		printf("\n-----> Create\n\nHow many cycles would you like?\n");
		scanf("%d", &cycles);
		printf("\n\nAmplitude (in pixels, current canvas size is %d by %d)?\n", width, height);
		scanf("%d", &amplitude);
		printf("\n\nPlease enter an RGB value for the colour of the sine wave itself\n\nPlease format as: 0 0 0\nOR\n\n0\n0\n0\n\nMax value is %d\n\n", colour);
		scanf("%d %d %d", &r, &g, &b);
		for (x = 0; x < width; x++)
		{
			y = ((int)round(((amplitude - 1) / 2 * sin(cycles*((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
			for (i = 0; i < 3; i++); {
				array[y][x][0] = r, array[y][x][1] = g, array[y][x][2] = b;
			}
		}
		printf("Ok, we have finished generating your wave. Is there anything else you'd like to do whilst you are here?\nYour options are:%sPlease enter the corresponding number\n\n", options);
		scanf("%d", &menu);
	}

	while (menu == 3)
	{
		char impath[100];
		FILE *impfile = NULL;
		printf("\n-----> Import\n\nAlright then, let's get onto importing your parameters, please refer to the help documentation for more information\n\nPlease provide a filepath to your .txt file\n\n");
		scanf("%s", &impath);
		printf("\nNow searching for a file at: %s", impath);

		if ((impfile = fopen(impath, "r")) == NULL)
		{
			printf("\n\nSorry, we couldn't find anything at %s, please try again\n\n", impath);
		}
		else
		{
			int impcycles = 0;
			int impamplitude = 0;
			int impr = 0;
			int impg = 0;
			int impb = 0;

			char impcyclesstr[100];
			char impamplitudestr[100];
			char imprstr[10];
			char impgstr[10];
			char impbstr[10];
			if (fscanf(impfile, "%s\n%s\n%s\n%s\n%s", &impcyclesstr, &impamplitudestr, &imprstr, &impgstr, &impgstr) < 5)
			{
				printf("Oops, sorry about this but the file you provided is not in the correct format, please refer to the help documentation for more information");
				return(0);
			}
			else
			{
				char *endptr;
				impcycles = (int)strtol(impcyclesstr, &endptr, 10);
				impamplitude = (int)strtol(impamplitudestr, &endptr, 10);
				impr = (int)strtol(imprstr, &endptr, 10);
				impg = (int)strtol(impgstr, &endptr, 10);
				impb = (int)strtol(impgstr, &endptr, 10);
				for (x = 0; x < width; x++)
				{
					y = ((int)round(((impamplitude - 1) / 2 * sin(impcycles*((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
					for (i = 0; i < 3; i++); {
						array[y][x][0] = impr, array[y][x][1] = impg, array[y][x][2] = impb;
					}
				}
				printf("Ok, we have finished generating your wave. Is there anything else you'd like to do whilst you are here?\nYour options are:%sPlease enter the corresponding number\n\n", options);
				scanf("%d", &menu);
			}
		}
	}

	while (menu == 4)
	{
		char savepoint[100];
		printf("-----> Export\n\nThank you, we are now generating your PPM file\n\n");
		scanf("%s", &savepoint);
		FILE *f = fopen("%s", "w", savepoint);
		if (f == NULL)
		{
			printf("Oops, we cannot open the specified file\n");
			exit(1);
		}
		else
		{
			fprintf(f, "P3\n%d %d\n%d\n", width, height, colour);
			for (i = 0; i < width; i++)
				for (j = 0; j < height; j++)
				{
					fprintf(f, "%d %d %d ", array[i][j][0], array[i][j][1], array[i][j][2]);
				}
			fclose(f);
			printf("Ok, your file is ready, we are now attempting to open it in your viewer of choice.\nThe program will not continue until you close the viewer\n\n");
			system("%s", f);
			printf("Ok, we have finished generating your wave. Is there anything else you'd like to do whilst you are here?\n\nYour options are:%sPlease enter the corresponding number\n\n", options);
			scanf("%d", &menu);
		}
	}

	while (menu == 5)
	{
		printf("\n\nThank you for using the sine wave generator, come back anytime you need our services again\n\n");
		return(0);
	}

	while (menu > 5)
	{
		printf("\n\nSorry, that option is not recognised, please try again\n\n");
		scanf("%d", &menu);
	}

	while (menu < 1)
	{
		printf("\n\nSorry, that option is not recognised, please try again\n\n");
		scanf("%d", &menu);
	}
}