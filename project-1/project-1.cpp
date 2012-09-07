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
	printf ("John Archer\n");
	printf ("CNS 3060 Section 601\n\n");
	int n = 0;
	while ( n < argc )
	{
		// Goes through the loop until all elements in argv array have been processed.
		printf( "%s\n", argv[n] );
		n++;
	}
	return 0;
}