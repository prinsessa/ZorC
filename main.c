#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "zorc.h"
#include "room.h"
#include "main.h"
#include "command.h"
#include "player.h"
#include "version.h"

int isRunning = 1;

// My first "real" C app, hence God class..
int main(int argc, char *argv[])
{
	struct game *g = initGame();
	g->zorc = initPlayer("Tessa");
	g->zorc->rm = initRoom("spawnroom", "dark");
	printVersion();
	promptYesNoQuestion("When will it be night by day?", "winter", "Hah! A spark of intelligence!", "Hah! You're only good for wielding a sword!");
	initCommands(g);
	printCommands(g);
	while(isRunning)
	{
		promptCommand(g);
	}
	destroyGame(g);
    return 0;
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
	scanf("%11s",answer);
	// cc: free the buffer
	char cc;
	while((cc=getchar()) != '\n');
	char *t = toLowerCase(answer, sizeof answer/sizeof *answer);
	if(strcmp(t,exp) == 0)
	{
		printf("%s\n",succ);
		free(t);
		return 1;
	}
	printf("%s\n",fail);
	return 0;
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
