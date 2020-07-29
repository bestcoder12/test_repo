# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Program for writing text in a file
// This program can write text to a file until stopped by writing #q
// This key comination will exit you from the program
// The functionality is currently being improved by first printing the text in file if any
// That may take another week or two due to other commitments
// Another warning right now this program opens the file in write mode which will delete
// the text written prior to the execution of the program
// So for the time being please donot run it in your computer especially already created files
// for the time being. Though that erroneous behaviour is being corrected.

FILE *file_open(void)
{
	char filename[80]; 
	printf ("Enter the path of the file:	");
	scanf ("%[^\n]%*c",filename);
	FILE *fp1 = fopen(filename,"w");
	return fp1;
}

void enter_text(FILE *fp2)
{
	int i;
	char str[200];
	printf("Enter the text to be written in the file:	(to stop writing press:	#q)\n\n");
	for (i=0;;i++)
	{
		scanf ("%[^\n]%*c",str);
		if (strcmp(str,"#q") == 0)
			break;
		fprintf(fp2,"%s\n",str);
	}
}

int main(void)
{
	FILE *fp;
	// Function for opening the file
	fp = file_open();
	if (fp == NULL)
	{
		printf("File not found!\n....Exiting program\n");
		return EXIT_FAILURE;
	}
	// Function for entering the text in the file
	enter_text(fp);
	fclose(fp);
	return EXIT_SUCCESS;
}
