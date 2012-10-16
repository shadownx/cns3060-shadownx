/*
Name: John Archer
Class: CS3060
Section: 601
Date: 2/21/2011

I declare that the following source code was written solely by me.  I understand that copying any source code , in whole or part, constitutes cheating, and that I will receive a zero on this projectif I am found in violation of this policy.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>

#define PAGELEN 23
#define LINELEN 512

// Global variables
char *fileName;
long int total;
char *per;

// Functions
int sMore( FILE*, FILE*, int, int );
void run ( FILE*, int );

int main ( int argc, char* argv[] )
{
	FILE *fptr;
	tty_mode(0);
	struct stat info;
	
	if ( argc == 1 )
	{ 
		fileName = "bytes";
		per = "";
		run( stdin, 1 );
	}
	else
 	{ 
		fileName = argv[1];
		per = "%";
		while ( --argc )
		{
			if ( stat( argv[1], &info ) != -1 )
			{
				if (( fptr = fopen( *++argv, "r" )) != NULL )
				{	
					total = ( long int )(info.st_size);
					run( fptr, 0 );
					fclose(fptr);
				}
			}
			else 
				exit(1);
		}
	}
	tty_mode(1);
	reset_mode();
	return(0);
}

// Run function
void run( FILE *fptr, int stdi )
{
	char line[LINELEN];
	int numLines = 0;
	int numChars = 0;
	int sMore( FILE*, FILE*, int, int ), reply;
	FILE *fptr_tty;
	int file_des_tty;

	file_des_tty = open( "/dev/tty", O_RDONLY );
	fptr_tty = fopen( file_des_tty, "r" );
	if ( fptr_tty == NULL )
		exit(1);
	while ( fgets( line, LINELEN, fptr ))
	{
 		set_mode(file_des_tty);
		numChars = numChars + strlen(line);
		if ( numLines == PAGELEN )
		{
			reply = sMore( fptr_tty, fptr, stdi, numChars );
			if (!stdi)
				fileName = "";
			if ( reply == 0 )
				break;
			numLines -= reply;
		}
		if ( fputs( line, stdout ) == EOF )
			exit(1);
		numLines++;
	}
}

// See More function
int sMore ( FILE *fptr_tty, FILE *fptr, int stdi, int numChar )
{
	int c, percent;
	
	if (stdi)
		percent = numChar;
	else 
	{ 
		long int cpos = ftell(fptr);
		percent = (int)((( double ) cpos/( double ) total ) * 100 );
	}
	printf( "\033[7m %s %d%s \033[m", fileName, percent, per );
	while(( c = getc( fptr_tty )) != EOF )
	{
		if ( c == 'q' )
		{
			erase(LINELEN);
			return(0);
		}
		if ( c == ' ' )
		{
			erase(LINELEN);
			return(PAGELEN);
		}
		if ( c == '\n' ) 
		{ 
			erase(LINELEN);
			return(1);
		}
	}
	return(0);
}

// TTy mode
tty_mode( int how )
{
	static struct termios original_mode;
	static int original_flags;
	static int stored = 0;

	if ( how == 0 )
	{
		tcgetattr( 0, &original_mode );
		original_flags = fcntl( 0, F_GETFL );
		stored = 1;
	}
	else if ( stored )
	{
		tcsetattr( 0, TCSANOW, &original_mode );
		fcntl( 0, F_SETFL, original_flags );
	}
}

// set mode function
set_mode( int file_des )
{
	struct termios ttystate;
	tcgetattr( file_des, &ttystate );
	ttystate.c_lflag &= ~ICANON;
	ttystate.c_lflag &= ~ECHO;
	ttystate.c_cc[VMIN] = 1;
	tcsetattr( 1, TCSANOW, &ttystate );
}

// reset mode function
reset_mode()
{
	struct termios ttystate;
	tcgetattr( 1, &ttystate );
	ttystate.c_lflag |= ICANON;
	ttystate.c_lflag |= ECHO;
	tcsetattr( 1, TCSANOW, &ttystate );
}

// Erase function
erase( int howMuch )
{ 
	int i;
	
	for( i = 0; i < howMuch; i++ )
		printf( "\b \b" );
}

