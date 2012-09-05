/*
Name: John Archer
Class: CS3060
Section: 601
Date: 9/05/2012

I declare that the following source code was written solely by me.
I understand that copying any source code, in whole or part, constitutes cheating,and that I will receive a zero on this project if I am found in violation of this policy.
*/

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char* argv[ ] )
{
	printf ("John Archer/n");
	printf ("CS3060 Section 601/n");
	int n = 0;
	while ( n < argc )
	{
		// Checks to see if this is the first time through the loop
		if ( n == 0)
		{
			printf( "%s\n", argv[n] );
		}

		// Compares first element in the next char array to see if it a '-'
		else if ( argv[n][0] ==  '-' )
		{ 
			// Compares the second element to see if it is upper case or a digit.
			if (( isupper( argv[n][1] ) == 1) || ( isdigit( argv[n][1] ) == 1 ))
			{
				printf( "%s\ ", argv[n] );
				printf( "(invalid option)\n" );
			}
			// Compares the second element is a valid lower case letter
			if  ( islower( argv[n][1] ) == 1 )
			{
				printf( "%s\n", argv[n] );
			}
		}
		
		n++;
	}
	return 0;

}