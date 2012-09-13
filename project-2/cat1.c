/*
Name: John Archer
Class: CS3060
Sec: 601

I declare that the following source code was written solely by me.  I understand that copying an source code, in whole or part, constitutes cheating, and  that I will receive a zero on this project if I am found in violation of this policy. 
*/

#include <stdio.h>
#include <stdlib.h>
#define linelen 1024 //max length of line

int readfile( FILE *fp, int numbering )
{

	int linenumbere1;
	char *error;
	char lineR[linelen];

	while (error = fgets( lineR, linelen, fp ))
	{
		if ( error == NULL )
			return(1);
		if ( numbering == 1 )
		{
			printf( "\t%i ", linenumR );
			linenumR++;
		}
		if ( fputs( lineR, stdout ) == EOF )
			exit(1);
	}
return(0);
}

int main ( int argc, char* argv[] )
{
	// Variable initialization.
	int lnum = 2;
	int linenum = 1;
	int count = 1;
	FILE *fp;
	char *cuse = "usage: cat [-n] [file ...]";
	int readF = 0;
	char line[linelen];
	char *option = "-n";

	// No other options specified with the command.
	if ( argc == 1 )
	{
		while( fgets( line, linelen, stdin ))
			printf( "%s", line );
	}
	else
	{
		while( count < argc )
		{ 
		// Checks to see if -n or an illegal option has been entered but not a file name		
			if ( argv[1][0] == '-' )
			{
				if ( argv[1][1] == 'n' )
				{ 
				// Prints input from stdin or file out to screen with line numbers
					if ( argc == 2 )
					{
						while( fgets( line, linelen, stdin ))
							printf( "\t%i %s", linenum++, line );
					}
					else
					{
						// Checks to make sure the file is valid
						if ((  fp = fopen( argv[lnum], "r" )) != NULL )
						{
							readF = readfile( fp, 1 );
							if ( readF == 1 )
								printf( "Error reading file.\n" );
							break;
						}
						else 
							printf( "%s: %s: No such file\n", argv[0], argv[lnum] );
					}
				}
				// Gives error if any other option is specified with the '-'
				else if ( argv[1][1] != 'n' )
					printf( "%s: illegal option -%s\n%s\n", argv[0], argv[1], cuse );
			linenum = 1;
			}
			// Check to see if the second option or more provided is a file name.
			else
			{
				// Checks to make file name is valid
				if ( ( fp = fopen( argv[count], "r" )) != NULL )
				{	
				// Prints out contents of file
					readF = readfile( fp, 0 );
					if ( readF == 1 )
						printf( "Error reading file.\n" );
					break;
				}
				else
					printf( "%s: %s: No such file\n", argv[0], argv[count] );				
			}
		count++;
		lnum++;
		fclose(fp);
		}
	}
	return(0);
}

