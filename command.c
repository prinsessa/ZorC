#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "command.h"

void initCommands(struct game *game)
{
	int size = 12;
	int x = 0;
	game->cmds = malloc(sizeof(struct command)*size);
	game->cmdsize = size;
	game->cmds[x++] = getCommand("help", visible, &printCommands);
	game->cmds[x++] = getCommand("look", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("open", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("show", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("exit", visible, &exitMe);
	game->cmds[x++] = getCommand("unlock", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("hit", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("equip", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("unequip", visible, &printCommandDummy);
	game->cmds[x++] = getCommand("whoprogrammedme", hidden, &printMe);
	game->cmds[x++] = getCommand("whowroteme", hidden, &printMe);
	game->cmds[x++] = getCommand("attack", visible, &printCommandDummy);
}

struct command getCommand(const char name[21], int hidden, void *fp)
{
	struct command *command;
	command = malloc(sizeof(struct command));
	strcpy(command->name, name);
	command->hidden = hidden;
	command->fp = fp;
	return *command;
}

void promptCommand(struct game *game)
{
	char command[16];
	scanf("%s", command);
	struct command *c = parseCommand(game, command);
	if(c != NULL)
	{
		c->fp(game);
	}
	else
	{
		printf("I don't know what %s is!\n", command);
	}
}

struct command* parseCommand(struct game *game, char *com)
{
	struct command *ret = NULL;
	com = toLowerCase(com, sizeof com);
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
