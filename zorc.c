#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "zorc.h"
#include "command.h"
#include "player.h"

struct game* initGame(void)
{
	struct game *game = malloc(sizeof(struct game));
	if(game == NULL)
	{
		errAbort("ERROR!");
	}
	return game;
}

void destroyGame(struct game *game)
{
	printf("-> Free\n");
	// TODO: doors are leaky at the moment, clear up doors on removal of rooms game->rms
	free(game->cmds);
	free(game->zorc->rm);
	free(game->zorc);
	free(game);
	printf("-> End\n");
}
