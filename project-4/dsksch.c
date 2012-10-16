/*
Name: John Archer
Class: CS3060
Section: 601

I declare that the following source code was writen solely by me.  I understand that copying any source code, in whole and part, constitutes cheating, and that I will receive a zero on this project if I am found in violation of this policy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define start 15;

// Function declarations
void firstCome( int tracks[] );
void shortest( int sTracks[]  );
void elevator( int tracks[] );

int main ( int argc,  char *argv[] )
{
	int tracks[] = { 18, 4, 40, 11, 35, 7, 14, 21, 32, 41 };
	int *trackPtr;
	int sTracks[10];
	
	
	// Calls sort methods
	firstCome(tracks);  
	shortest(tracks);
	elevator(tracks);
	
	return(0);
}

// Searches tracks as the come in.
void firstCome ( int tracks[] )
{
	// varible declaration
	int current, last, diff;
	int count = 0;
	long total = 0;
	last = start; 
	
	printf( "\nFirst Come First Searched\n\n" );
	printf( "Head Movement\t\t\tTracks Traversed\n" );
	while( count < 10 )
	{
		current = tracks[ count ];
		// indicates track count change
		diff = current - last;
		// prints out nead movment and absolute track change
		printf( "Tracks %i-%i\t\t\t%i\n", last, current, abs(diff) );
		total = total + abs (diff);
		last = current;
 		count++;
	}
	 	
	printf( "Total Tracks Traversed\t\t%ld\n", total );
}

// searches tracks with the least amount of change from the last track searched 
void shortest ( int tracks[] )
{
	// Varible declaration
	int current, last, diff, change, temp;;
	int count = 0;
	int scount = 0;
	long total = 0;
	int sDiff = 0;
	int tDiff = 0;
	int cDiff = 0;
	int sTracks[10];
	
	while ( count < 10 )
	{
		sTracks[count] = tracks[count];
		count++;
	}
	count = 0;

	last = start;
	printf( "\nShortest Seek Time\n\n" );
	printf( "Head Movement\t\t\tTracks Travesed\n" );

	while ( count < 10 )
	{	
		// Set base comparison 
		cDiff = sTracks[count] - last;
		cDiff = abs(cDiff);
				
		while ( scount < 10 )
		{
			change = 0;
			// Check difference between next element and last track.
			sDiff = sTracks[scount]- last;
			sDiff = abs(sDiff);
			// Keeps track of the lowesst amount of change until the swap is made
			if ( sDiff < tDiff )
			{
				tDiff = sDiff;
			}
			else
			{
				tDiff = sTracks[count] - last;
				tDiff = abs(tDiff);
			}
			// Swaps track order to keep the amount of changes to a minimum.
			if (( sDiff <= cDiff ) && ( sDiff >= tDiff ))
			{
				if ( count != scount )
				{
					temp = sTracks[count];
					sTracks[count] = sTracks[scount];
					sTracks[scount] = temp;
					current =  sTracks[count];
					change = 1;
					break;
				}
			}
			scount++;
		}
		// No change has occurred
		if ( change == 0 )
		{
			current = sTracks[count];
			diff = current - last;
			printf( "Tracks %i-%i\t\t\t%i\n", last, current, abs(diff) );
			last = current;
			total = total + abs( diff );
			count++;
		}
		scount = count;
		tDiff = 0;
	}
	printf( "Total Tracks Traversed\t\t%li\n\n", total );
}

// searches tracks in order of head movement 
void elevator ( int tracks[] )
{
	// Variable declaration
	int current, last, diff, temp, change, i;
	int count = 0;
	int scount = 0;
	int lastT = 49;
	int eTrack[10];
	int top = 0;
	long total = 0;
	// upDown is 0 if tracks are incrementing and 1 if decremanting
	int upDown = 0;
	int countf = 0;
	int eDiff = 0;
	int tDiff = 0;
	int cDiff = 0;
	
	// Copies Array
	while ( count < 10 )
	{
		eTrack[count] = tracks[count];
		count++;
	}
	count = 0;

	printf( "\nElevator Seek\n" );
	last = start;
	printf( "Head Movement\t\t\tTracks Traversed\n" );
	
	while ( count < 10 )
	{
		cDiff = eTrack[count] - last;
		while ( scount < 10 )
		{ 	
			change = 0;
			// Check difference between next element and last track.
			eDiff = eTrack[scount]- last;
			
			// Keeps track of the lowesst amount of change until the swap is made
			if ( eDiff < tDiff )
			{
				tDiff = eDiff;
			}
			else
			{
				tDiff = eTrack[count] - last;
			}
			// Swaps track order to keep the amount of changes to a minimum.
			if (( eDiff <= cDiff ) && ( eDiff >= tDiff ) && ( eDiff > 0 ) && ( cDiff > 0 ))
			{
				if ( count != scount )
				{
					temp = eTrack[count];
					eTrack[count] = eTrack[scount];
					eTrack[scount] = temp;
					current =  eTrack[count];
					change = 1;
					break;
				}
			}
			scount++;
		}
		// No change has occurred
		if ( change == 0 )
		{
			current = eTrack[count];
			diff = current - last;
			printf( "Tracks %i-%i\t\t\t%i\n", last, current, abs(diff) );
			last = current;
			total = total + abs( diff );
			count++;
		}
		scount = count;
		if ( change == 1 )
			count = 0;
	}
	printf( "Total Tacks Traversed\t\t%ld\n\n", total );
	
	count = 0;
	while ( count < 10 )
	{
		printf( "eTrack[%i]\t%i\n", count, eTrack[count] );
		count++;
	}	
}

