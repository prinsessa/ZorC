#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "player.h"

struct player* initPlayer(const char n[21])
{
	struct player *zorc = malloc(sizeof(struct player));
	if(zorc == NULL)
	{
		errAbort("ERROR!");
	}
	strcpy(zorc->name, n);
	return zorc;
}
