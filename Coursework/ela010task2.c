#define _CRT_SECURE_NO_WARNINGS //Allows for the use of functions that are deemed "unsafe" such as scanf()
//Sine Wave generator: Created by James Marsh B618112 at Loughborough University for 16ELA010
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define width 256 //Defines the width of the canvas
#define height 256 //Defines the height of the canvas
#define colour 255 //Defines the colour depth that the program will be using
#define PI 3.14159265 //This will be used in the equations that will work out the 

int main()
{
	int i, j, cycles, amplitude, array[width][height][3], y, x, r, g, b, menu, help, impfile; //Initialising the variables that will be used to store integers
	char options[] = "\n\t1) Help and About\n\t2) Set the parameters\n\t3) Import parameters\n\t4) Exports your parameters to a .PPM file then opens it\n\t5) Exits the program\n\n"; //Because this menu will be used throughout the program, I found it easier to set it as a variable for incase I decided to change anything I would only have to do it once
	char impath; //This will be used during importing files but was set up here just incase
	for (x = 0; x < width; x++) //This for loop is recycled from the part where the sine wave was generated since I stumbled upon setting cycles and amplitude to zero created a straight line, this does the horizontal axis...
	{
		y = ((int)round(((0 - 1) / 2 * sin(0*((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
		for (i = 0; i < 3; i++); {
			array[y][x][0] = 255, array[y][x][1] = 255, array[y][x][2] = 255;
		}
	}
	for (x = 0; x < width; x++) //...and this does the vertical axis
	{
		y = ((int)round(((0 - 1) / 2 * sin(0 * ((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2)));
		for (i = 0; i < 3; i++); {
			array[x][y][0] = 255, array[x][y][1] = 255, array[x][y][2] = 255;
		}
	}
	printf("Hello and welcome to the sine wave generator: for all your sine wave needs.\n\nTo get started you now have the following options: %sPlease enter the corresponding number\n\n", options);
	scanf("%d", &menu); //Input for the menu which using while loops will go to the relavant part of the program
	while (menu == 1)
	{
		printf("\n\-----> Help\n\nHello and welcome to the sine wave generator. This program has been written to generate and save a sine wave to an image file.\n\nThere are two ways to read the help documentation:\n\t1) Online (always up to date)\n\t2) In client (correct at time of writing\n\nPlease select an option\n\n");
		scanf("%d", &help);
		if (help == 1)
		{
			printf("Ok, we are now attempting to open the website in your default browser\nThe program will wait for you to close the website before continuing");
			system("explorer https://jrmswell.github.io/16ELA010-Coursework/");
		}
		else
		{
			printf("\n\nThis program is designed to generate a sine wave using the parameters you set and then save them to a .ppm compatible file\n\nLet's review each menu option:\n\n\t2) Set the parameters\n");
			system("pause"); //Holds the program to let the user read the text above without being disturbed (Note: only works on windows however for some reason getchar() was being ignored)
			printf("\n\nThis brings you to the create screen, here you can specify the amplitude, frequency and colour of your sine wave.\nThis program walks you through the process so there's no need to learn anything.\nYou can repeat this step as many times as you would like\n");
			system("pause");
			printf("\n\n\t3) Import parameters\n\nThis brings you to a screen that allows you to import a Plain-Text document (we recommend a .txt file due to them being commonplace)\n");
			system("pause");
			printf("\n\n\t4) Exports your parameters to a .PPM file then opens it\n\nThis program asks you where you would like to save. Please remember to include the file type however\nWe recommend saving as a .ppm file since the contents will be saved in the .ppm format\nWe have not restricted you to the .ppm extension however in case you plan to do something else with the file\n\nAfter saving the program will end\n");
			system("pause");
			printf("\n\n\t5) Exits the program\n\nStops the program");
		}
		printf("\n\nWhat whould you like to do now?\nYour choices are:%s", options);
		scanf("%d", &menu);
	}

	while (menu == 2) //This section of the program asks the user step-by-step how they'd like their sine wave to look
	{
		printf("\n-----> Create\n\nHow many cycles would you like? (We don't recommend more than 7)\n"); //Flavour text asking the user to prepare to enter the frequency
		scanf("%d", &cycles);
		printf("\n\nAmplitude (in pixels, current canvas size is %d by %d)?\n", width, height); //Flavour text asking the user to prepare to enter the amplitude
		scanf("%d", &amplitude);
		printf("\n\nPlease enter an RGB value for the colour of the sine wave itself\n\nPlease format as: 0 0 0\nOR\n\n0\n0\n0\n\nMax value is %d\n\n", colour); //Flavour text asking the user to prepare to enter the colour values for the 3D array
		scanf("%d %d %d", &r, &g, &b); //The only requirement is that there is a gap between each number
		if (r > 255 || g > 255 || b > 255) //An if statement with a few variables to make sure that the RGB values do not exceed 255
		{
			printf("Sorry, the maximum colour value is %d, please enter a compatible value\nWe'll bring you to the top of the create program just so that you can review your settings to make sure they're to your liking\n\n", colour);
			system("pause"); //Holds the program to let the user read the text above without being disturbed
		}
		else
		{
			for (x = 0; x < width; x++)
			{
				y = ((int)round(((amplitude - 1) / 2 * sin(cycles*((x - (width - 1) / 2) * 2 * PI / (width - 1))) + (height) / 2))); //Sine Wave equation. A round is used at the beginning there to make sure that there will only be integers since the sine wave equation cannot work with float values
				for (i = 0; i < 3; i++); {
					array[y][x][0] = r, array[y][x][1] = g, array[y][x][2] = b; //This is how the colours are arranged, a 3D array is used to store each of the colour values defined above which when it comes to printing the wave to a file
				}
			}
			printf("Ok, we have finished generating your wave. Is there anything else you'd like to do whilst you are here?\nYour options are:%sPlease enter the corresponding number\n\n", options); //A bespoke menu selection to make it friendlier for the user, just a personal preference 
			scanf("%d", &menu);
		}
	}

	while (menu == 3) //This is the section of the program that allows the user to import a plain-text file (such as a .txt) to help speed up the process of creating the sine waves if a large amount of them have to be added in quick succession
	{
		char impath[500]; //Defines the import file variable with a size of 500 characters which hopefully should be enough for most applications. If programs are stored in the same folder as the text-files then the path should not have to be defined
		FILE *impfile = NULL; //FILE contains the necessary information to control the data stream
		printf("\n-----> Import\n\nAlright then, let's get onto importing your parameters, please refer to the help documentation for more information\n\nPlease provide a filepath to your .txt file\n\n");
		scanf("%s", &impath); //Allows the user to define the path
		printf("\nNow searching for a file at: %s", impath); //Flavour text to let the user know the program has recieved their inputs and call it back to them

		if ((impfile = fopen(impath, "r")) == NULL) //Checking to see if there is anything at the users specified location, if there isn't then the program lets them know. 'r' is used so that the program only reads from that location rather than prepares to make any changes
		{
			printf("\n\nSorry, we couldn't find anything at %s, please try again\n\n", impath); //Shows the user the location they specified so that they can review for spelling mistakes
		}
		else
		{
			int impcycles = 0; //Establishes the variable that will contain the imported cycles data
			int impamplitude = 0; //Establishes the variable that will contain the imported amplitude data
			int impr = 0; //Establishes the variable that will contain the imported colour data for Red then Green then Blue
			int impg = 0;
			int impb = 0;

			char impcyclesstr[100]; //Establishes the variable that will contain the imported cycles data established as a string
			char impamplitudestr[100]; //Establishes the variable that will contain the imported amplitude data established as a string
			char imprstr[10]; //Establishes the variable that will contain the imported colour data for Red then Green then Blue established as a string
			char impgstr[10];
			char impbstr[10];
			if (fscanf(impfile, "%s\n%s\n%s\n%s\n%s", &impcyclesstr, &impamplitudestr, &imprstr, &impgstr, &impgstr) < 5) //Imports the data from the file as a string (just incase there are any erranious characters such as a letter) then checks to see if there are more than five variables in the imported file, if there are then the user is notified
			{
				printf("\n\nOops, sorry about this but the file you provided is not in the correct format, please refer to the help documentation for more information\n\n");
			}
			else //If the above statement is false the program continues
			{
				char *endptr; //endptr is a standard function to pdictate the end of a pointer
				impcycles = (int)strtol(impcyclesstr, &endptr, 10); //Sets the integer import cycles variable to equal the strings value that has been converted into an integer, strtol converts a string to a long integer
				impamplitude = (int)strtol(impamplitudestr, &endptr, 10);
				impr = (int)strtol(imprstr, &endptr, 10);
				impg = (int)strtol(impgstr, &endptr, 10);
				impb = (int)strtol(impgstr, &endptr, 10);
				for (x = 0; x < width; x++) //This is the same equation for generating the sine wave as above in the manually entered parameter section
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

	while (menu == 4) //Start of the code that takes the values from the arrays and prints them to a .ppm file
	{
		char savepoint[500]; //Defines the save file variable with a size of 500 characters which hopefully should be enough for most applications. If files are to be stored in the same folder as the text-files then the path should not have to be defined
		printf("-----> Export\n\nWelcome to the exporter where we generate your finished .PPM file\nYou may choose a path to save the image\nRemember to specify the file extension: '.ppm'!\nPlease refer to the help documentation for more information\n\n");
		scanf("%s", &savepoint); //Asks the user where they would like the file to be saved, the user is asked to include the file extension incase they do not want to save as a .ppm just incase they decide they'd like to save it as another compatible file
		printf("\n\nThank you, we are now attempting to save in your specified location: %s", savepoint); //Flavour text to let the user know the program has recieved their inputs and call it back to them
		FILE *f = fopen(savepoint, "w"); //Tells the program to create a file in the place specified by the user
		if (f == NULL) //Checks to see if the place specified can be written to if it cannot then an error is displayed
		{
			printf("Oops, we're sorry but we cannot save in that location.\n\nPlease try another location\n\n");
		}
		else
		{
			fprintf(f, "P3\n%d %d\n%d\n", width, height, colour); //Prints the values into the variables
			for (i = 0; i < width; i++) //Uses two loops to constrain the values within the height and width of the canvas
				for (j = 0; j < height; j++)
				{
					fprintf(f, "%d %d %d ", array[i][j][0], array[i][j][1], array[i][j][2]); //Uses a 3D array to print the 3 character colour code for each of the RGB
				}
			fclose(f);
			printf("\n\nOk, your file is ready, we are now attempting to open it in your viewer of choice.\nThe program will not continue until you close the viewer\n\n"); //Flavour text to let the user know that the program has worked
			system(savepoint); //Attempts to open the file in the default program associated with the file type
		}
		printf("\n\nOk, we have finished generating your wave\n\nThank you for using the sine wave generator, come back anytime you need our services again\n\n");
		exit(1);
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