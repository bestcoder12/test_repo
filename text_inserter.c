# include <stdio.h>
# include <stdlib.h>
# include <string.h>


FILE *file_open(void)
{
	char filename[80]; 
	printf ("Enter the path of the file:	");
	scanf ("%[^\n]%*c",filename);
	// The file is opened in read and append mode
	// Thus an existing file is not overwritten
	FILE *fp1 = fopen(filename,"a+");
	return fp1;
}

long int line_count(FILE *fp2)
{
	rewind(fp2);
	long int cnt1=0;
	char c;
	for (c=getc(fp2);c != EOF;c=getc(fp2))
	{
		if (c == '\n')
			cnt1+=1;
	}	
	rewind(fp2);
	return cnt1;
}

void read_text(FILE *fp3)
{
	// Function for finding the number of lines in the file
	long int cnt2 = line_count(fp3);
	int brk=0;
	char str_read[200];
	printf("\n");
	printf("The text in the file currently:\n");
	for (brk=0;brk<20;brk++)
	{
			printf("-");
	}	
	printf("\n");		
	while (cnt2 != 0)
	{
		fscanf(fp3,"%[^\n]%*c",str_read);
		printf("%s\n",str_read);
		cnt2--;
	}
	for (brk=0;brk<20;brk++)
	{
		printf("-");	
	}
	printf("\n");
}

void enter_text(FILE *fp4)
{
	int i;
	char str_write[200];
	printf("Enter the text to be written in the file:	\n(to stop writing press: #q)\n(to print text in file press: #p)\n\n");
	for (i=0;;i++)
	{
		scanf ("%[^\n]%*c",str_write);
		if (strcmp(str_write,"#q") == 0)
			exit(EXIT_SUCCESS);
		if (strcmp(str_write,"#p") == 0){
			read_text(fp4);
			enter_text(fp4);
		}
		fprintf(fp4,"%s\n",str_write);
	}
}

int main(void)
{
	FILE *fp;
	printf("\t\t\t\tPROGRAM FOR INSERTING TEXT IN A FILE\n\n\n");
	// Function for opening the file
	fp = file_open();
	if (fp == NULL)
	{
		printf("\nFile not found!\n....Exiting program\n");
		return EXIT_FAILURE;
	}
	// Reading the text of the file
	read_text(fp);
	// Function for entering the text in the file
	enter_text(fp);
	fclose(fp);
	return EXIT_SUCCESS;
}
