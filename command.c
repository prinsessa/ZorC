#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "command.h"

void initCommands(struct game *game)
{
	int size = 12;
	game->cmds = malloc(sizeof(struct command)*size);
	game->cmdsize = size;
	game->cmds[0] = getCommand("help", visible, &printCommands);
	game->cmds[1] = getCommand("look", visible, &printCommandDummy);
	game->cmds[2] = getCommand("open", visible, &printCommandDummy);
	game->cmds[3] = getCommand("show", visible, &printCommandDummy);
	game->cmds[4] = getCommand("exit", visible, &exitMe);
	game->cmds[5] = getCommand("unlock", visible, &printCommandDummy);
	game->cmds[6] = getCommand("hit", visible, &printCommandDummy);
	game->cmds[7] = getCommand("equip", visible, &printCommandDummy);
	game->cmds[8] = getCommand("unequip", visible, &printCommandDummy);
	game->cmds[9] = getCommand("whoprogrammedme", hidden, &printMe);
	game->cmds[10] = getCommand("whowroteme", hidden, &printMe);
	game->cmds[11] = getCommand("attack", visible, &printCommandDummy);
}

struct command getCommand(const char name[21], int hidden, void *fp)
{
	struct command command;
	strcpy(command.name, name);
	command.hidden = hidden;
	command.fp = fp;
	return command;
}

void promptCommand(struct game *game)
{
	char command[16];
	scanf("%15s", command);
	char cc;
	while((cc=getchar()) != '\n');
	struct command *c = parseCommand(game, command, sizeof command/sizeof *command);
	if(c != NULL)
	{
		c->fp(game);
	}
	else
	{
		printf("I don't know what %s is!\n", command);
	}
}


// TODO: consider strtok
struct command* parseCommand(struct game *game, char *com, int size)
{
	struct command *ret = NULL;
	com = toLowerCase(com, size);
	for(int i = 0; i < game->cmdsize; i++)
	{
		if(strcmp(com, game->cmds[i].name) == 0)
		{
			ret = &game->cmds[i];
		}
	}
	return ret;
}

void printCommands(const struct game *game)
{
	printf("\n** The following commands are available to me **\n\n");
	for(int i = 0; i < game->cmdsize; i++)
	{
		if(!game->cmds[i].hidden)
		{
			printf("> %s\n",game->cmds[i].name);
		}
	}
	printf("\n\n");
}

void exitMe(struct game *game)
{
	destroyGame(game);
	isRunning = 0;
	exit(0);
}

void printCommandDummy(void *p)
{
	printf("Command Dummy!\n");
}
