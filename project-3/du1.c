/*
Name: John Archer
Class: CS3060
Section: 601

I declare that the following source code was written soleley by me.  I understand that copying any source code, in whole or part, constitutes cheating, and that I will receive a zero on this project if I am found in violation of this policy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define max 256

int dusage( char dname[], int a );

int main( int argc, char *argv[] )
{

	if ( argc == 1 )
		dusage( ".", 0 );
	else
	{
		if ( argc == 2 )
			dusage( ".", 1 );
		else
		{
			printf( "%s: Invalid option -- '%s'\n", argv[0], argv[1] );
			printf( "usage: %s Opt [ File name or Directory ]\n", argv[0] );
		}
	} 
	return(0);
}

// provides output for the du command.
int dusage( char dname[], int a )
{
	DIR *dirp;
	struct dirent* direntp;
	struct stat fileInfo;

	if (( dirp = opendir( dname )) == NULL )
		printf( "No such file or directory.\n" );
	//else
	{
	
	}	
	closedir( dirp );
	return(1);
}

