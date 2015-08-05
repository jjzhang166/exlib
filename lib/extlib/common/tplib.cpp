#include "tplib.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int toInt(string _string)
{
	return atoi(_string.c_str());
}

int random( int i )
{
	return rand()%i;
}
