#include "stdio.h"

#include "version.h"

void printVersion(void)
{
	printf("ZorC version: %d.%d.%d\n\n",maj, min, bld);
}
