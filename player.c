#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "room.h"
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

void addToInventory(void *p, char **args, int arg)
{
	struct game *game = (struct game *)p;
	if(arg == 0)
	{
		printf("Ehh..What object should I add to my inventory?\n");
		return;
	}

	for(int i = 0; i < game->zorc->rm->objsize; i++)
	{
		if(&game->zorc->rm->objs[i] != NULL)
		{
			if(strcmp(args[0], game->zorc->rm->objs[i]->name) == 0)
			{
				if(game->zorc->rm->objs[i]->isStatic != 1)
				{
					printf("I'm unable to add  %s to my inventory!\n",game->zorc->rm->objs[i]->name);
					return;
				}
				// realloc and add
				printf("** TODO: Implementations ** %s has been added to my inventory.\n", game->zorc->rm->objs[i]->name);
				return;
			}
		}
	}
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
