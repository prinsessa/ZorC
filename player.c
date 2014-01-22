#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "main.h"
#include "zorc.h"
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

void setPlayerDirection(struct game *game, char **args, int arg)
{
	if(strcmp(args[0], "north") == 0)
	{
		printf("OK, im looking to the north.\n");
		game->zorc->direction = north;
	}
	else if(strcmp(args[0], "east") == 0)
	{
		printf("OK, im looking to the east.\n");
		game->zorc->direction = east;
	}
	else if(strcmp(args[0], "south") == 0)
	{
		printf("OK, im looking to the south.\n");
		game->zorc->direction = south;
	}
	else if(strcmp(args[0], "west") == 0)
	{
		printf("OK, im looking to the west.\n");
		game->zorc->direction = west;
	}
	else
	{
		printf("Since when is %s considered to be a direction?\n", args[0]);
	}
}
