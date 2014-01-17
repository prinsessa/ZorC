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
	promptYesNoQuestion("Will it be day by night?", "winter", "Hah! A spark of intelligence!", "Hah! You're only good for wielding a sword!");
	initCommands(g);
	printCommands(g);
	while(isRunning)
	{
		promptCommand(g);
	}
	destroyGame(g);
    return 0;
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
	// TODO: doors are leaky at the moment, clear up doors on removal of rooms game->rms
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

void connectRooms(struct room *rma, int dira, struct door *dra, struct room *rmb, struct door *drb)
{
	int dirb = dira+2;
	if(dirb>4)
	{
		dirb-=4;
	} 
	if(dirb<0)
	{
		dirb+=4;
	}
	rma->trans[dira] = dra;
	dra->nxt = rmb;
	rmb->trans[dirb] = drb;
	drb->nxt = rma;
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

struct door* initDoor(const char name[21], int id, int isLocked, int code)
{
	struct door *door = malloc(sizeof(struct door));
	if(door == NULL)
	{
		errAbort("ERROR!");
	}
	strcpy(door->name, name);
	door->code = code;
	door->isLocked = isLocked;
	door->id = id;
	return door;
}

// Prompt question with yes or no return 
// TODO: add one for expected output: int prompt("When's a day the most dark?", "monday at night");
int promptYesNoQuestion(const char question[128], const char exp[64], const char succ[128], const char fail[128])
{
	char answer[12];
	printf("Q: %s\nA: ",question);
	// WARNING: fixed buffer for input.
	scanf("%11s",answer);
	char cc;
	while((cc=getchar()) != '\n');
	char *t = toLowerCase(answer, sizeof(answer)/sizeof(*answer));
	if(strcmp(t,exp) == 0)
	{
		printf("%s\n",succ);
		free(t);
		return 1;
	}
	printf("%s\n",fail);
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

char * toLowerCase(char *lowerCase, int size)
{
	for(int i = 0; i < size; i++)
	{
		lowerCase[i] = tolower(lowerCase[i]);
	}
	return lowerCase;
}
