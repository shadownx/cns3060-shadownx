/*/*
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
void shortest( int tracks[] );
void elevator( int tracks[]);
void eSort( int eTrack[] );

int main ( int argc,  char *argv[] )
{
	int tracks[] = { 18, 4, 40, 11, 35, 7, 14, 21, 32, 41 };
	int initTrack = 15;
	int prevTrack = 12;

	// Calls sort methods
	firstCome(tracks);  
	shortest(tracks);
	elevator(tracks);
	system("pause");
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
	int current, last, diff, change, temp;
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
	int count = 0;
	int eTrack[10];
	long total = 0;
	int last, diff;
	
	while ( count < 10 )
	{
		eTrack[count] = tracks[count];
		count++;
	}
	count = 0;
	
	eSort (eTrack);

	printf( "\nElevator Seek\n" );
	last = start;
	printf( "Head Movement\t\t\tTracks Traversed\n" );
	
	count = 0;
	diff = eTrack[0] - start;
	diff = abs(diff);

	printf( "Tracks 15-%i\t\t\t%i\n", eTrack[count], diff );
	while ( count < 9 )
	{
		if (( eTrack[count] > 15 ) && (eTrack[count+1] > 15 ))
		{
			diff = eTrack[count+1] - eTrack[count];
			diff = abs(diff);
			printf( "Tracks %i-%i\t\t\t%i\n",eTrack[count], eTrack[count+1], diff );
		}
		else if (( eTrack[count] > 15 ) && ( eTrack[count+1] < 15 ))
		{
			last = 44 - eTrack[count];
			diff = 44 - eTrack[count+1];
			diff = abs(diff);
			diff = diff +last;
			printf( "Tracks %i-%i\t\t\t%i\n",eTrack[count], eTrack[count+1], diff );
		}
		else if ( eTrack[count] < 15 )
		{
			diff = eTrack[count+1] - eTrack[count];
			diff = abs(diff);
			printf( "Tracks %i-%i\t\t\t%i\n",eTrack[count], eTrack[count+1], diff );
		}
		total = total + diff;
		count = count + 1;
	}

	printf( "Total Tracks Traversed\t\t%li\n\n", total );
}

// Sorts array into elevator seek pattern
void eSort ( int eTrack[] )
{
	int change, temp, j, i;

	for ( i = 0; i<10; i++ )
	{
		for ( j = 0; j<9; j++ )
		{
			if (( eTrack[j] > eTrack[j+1] ) && ( eTrack[j+1] > 15 ))
			{
				temp = eTrack[j+1];
				eTrack[j+1] = eTrack[j];
				eTrack[j] = temp;
			}
			else if (( eTrack[j] < 15 ) && (eTrack[j+1] > 15 ))
			{
				temp = eTrack[j+1];
				eTrack[j+1] = eTrack[j];
				eTrack[j] = temp;
			}
			else if (( eTrack[j] < eTrack[j+1] ) && ( eTrack[j] < 15 ))
			{
				temp = eTrack[j+1];
				eTrack[j+1] = eTrack[j];
				eTrack[j] = temp;
			}

		}
	}
}

