#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"
#include "command.h"

int isRunning = 1;

// My first "real" C app, hence God class..
int main(int argc, char *argv[])
{
	struct game *g = initGame();
	g->zorc = initPlayer("Tessa");
	g->zorc->rm = initRoom("spawnroom", "dark");
	printVersion();
	promptYesNoQuestion("Will it be day by night?", "yes", "Hah! A spark of intelligence!", "Hah! You're only good for wielding a sword!");
	initCommands(g);
	printCommands(g);
	while(isRunning)
	{
		promptCommand(g);
	}
	destroyGame(g);
    return 0;
}

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
	free(game->cmds);
	free(game->zorc->rm);
	free(game->zorc);
	free(game);
	printf("-> End\n");
}

// build the rooms and return spawn.
struct room* initRoom(const char name[21],const char env[21])
{
	// init our test setup only
	struct room *spawn = malloc(sizeof(struct room));
	if(spawn == NULL)
	{
		errAbort("ERROR!");
	}
	spawn->id = 0;
	strcpy(spawn->env, env);
	strcpy(spawn->name, name);
	return spawn;
}

void connectRoom(struct room *rma, int dira, struct door *dr, struct room *rmb)
{
	dr->nxt = rmb;
	rma->trans[dira] = dr;
}

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

// Prompt question with yes or no return 
// TODO: add one for expected output: int prompt("When's a day the most dark?", "monday at night");
int promptYesNoQuestion(const char question[128], const char exp[64], const char succ[128], const char fail[128])
{
	char answer[12];
	printf("Q: %s\nA: ",question);
	// WARNING: fixed buffer for input.
	scanf("%11s",answer);
	char *t = toLowerCase(answer, sizeof answer);
	if(strcmp(t,exp) == 0)
	{
		printf("%s\n",succ);
		free(t);
		return 1;
	}
	printf("%s\n",fail);
	free(t);
	return 0;
}

void printVersion(void)
{
	printf("ZorC version: %d.%d.%d\n\n",maj, min, bld);
}

void printZorc(const struct game *g)
{
	struct player *zorc = g->zorc;
	printf("My name is %s.\n", zorc->name);
}

void printRoom(const struct game *g)
{
	struct room *rm = g->zorc->rm;
	printf("I'm in a %s %s.\n", rm->env,rm->name);
}

void printMe(void *p)
{
	printf("Winter's cry comes as a song. Woken by a blade in the dark.\n");
}

void errAbort(char *err)
{
	printf(err);
	exit(0);
}

void exitMe(struct game *game)
{
	destroyGame(game);
	isRunning = 0;
	exit(0);
}

char * toLowerCase(char *upper, int size)
{
	char *lowerCase = malloc(size);
	strcpy(lowerCase, upper);
	for(int i = 0; i < size; i++)
	{
		lowerCase[i] = tolower(lowerCase[i]);
	}
	return lowerCase;
}
