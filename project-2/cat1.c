/*
Name: John Archer
Class: CS3060
Sec: 601

I declare that the following source code was written solely by me.  I understand that copying an source code, in whole or part, constitutes cheating, and  that I will receive a zero on this project if I am found in violation of this policy. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//max length of line
#define linelen 1024 

// Declearing functions
int readfile( FILE *fp, int numbering, int lines );

int main ( int argc, char* argv[] )
{
	// Variable initialization.
	int linenum = 1;
	int count = 1;
	FILE *fp;
	char *cuse = "usage: cat [-n] [file ...]";
	char line[linelen];
	char *option = "-n";
	
	// No other options specified with the command.
	if ( argc == 1 )
	{
		while( fgets( line, linelen, stdin ))
			printf( "%s", line );
	}
	// Gives error if any other option is specified with the '-'
	if ( (strcmp ( argv[1], option ) != 0) && ( argv[1][0] == '-' ))
	{
		printf( "%s: illegal option -%s\n%s\n", argv[0], argv[1], cuse );
		exit(1);
	}
	// Goes through the loop until there is no more arguments to be processed.
	while( count <= argc )
	{ 
		// Checks to see if -n has been used to print put line numbers		
		if ( strcmp( argv[1], option ) == 0 )
		{
			// Prints input from stdin or file out to screen with line numbers
			if ( argc == 2 )
			{
				while( fgets( line, linelen, stdin ))
					printf( "%6i %s", linenum++, line );
			}
			// Adjust counter to jump over the "-n" option
			if ( count == 1 )
				count++;
			// To make sure that the string stored in argv[count] is not equal to NULL to prevent the attempt to open as a file.
			if ( argv[count] != NULL)
			{
				// Checks to make sure the file is valid
				if ((  fp = fopen( argv[count], "r" )) == NULL )
					printf( "%s: %s: No such file or directory\n", argv[0], argv[count] );
				else 
				{
					linenum = readfile( fp, 1, linenum );
					fclose(fp);
				}
			}
		}
		// Check to see if the second option or more provided are files.
		else
		{
			// Checks to make sure the file is valid
			if ((  fp = fopen( argv[count], "r" )) == NULL )
				printf( "%s: %s: No such file or directory\n", argv[0], argv[count] );
			else 
			{
				linenum = readfile( fp, 0, linenum );
				fclose(fp);
			}				
		}
		count++;
	}
	return(0);
}


// Reads the file and outputs to stdout, returns error if file is corrupted
int readfile( FILE *fp, int numbering, int lines )
{
	char lineR[linelen];
	// Clears the file stream error flags
	clearerr(fp);
	// Send file to stdout while reading the file, as well as checking to see if errors have occured. 
	while ( fgets( lineR, linelen, fp ) != NULL )
	{
		// Checks to see if there was an error reading the file, if so, send error message to output.
		if ( ferror(fp) != 0 )	
		{
			perror( "File is not valid.");
			break;
		}
		if ( numbering == 1 )
		{
			printf( "%6i ", lines );
			lines++;
		}
		// Checkes for the EOF flag.
		if ( feof(fp) == EOF )  
			exit(1);
		fputs( lineR, stdout);
	}
return(lines);
}
