#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "command.h"


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

struct command* parseCommand(struct game *game, const char com[16])
{
	char *cmd = malloc(sizeof com);
	strcpy(cmd, com);
	struct command *ret = NULL;
	cmd = toLowerCase(cmd, sizeof com);
	for(int i = 0; i < game->cmdsize; i++)
	{
		if(strcmp(cmd, game->cmds[i].name) == 0)
		{
			ret = &game->cmds[i];
		}
	}
	free(cmd);
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

void printCommandDummy(void *p)
{
	printf("Command Dummy!\n");
}
