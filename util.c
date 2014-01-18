#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

char * toLowerCase(char *lowerCase, int size)
{
	for(int i = 0; i < size; i++)
	{
		lowerCase[i] = tolower(lowerCase[i]);
	}
	return lowerCase;
}
