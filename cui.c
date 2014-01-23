#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "zorc.h"
#include "player.h"
#include "object.h"
#include "room.h"
#include "cui.h"
#include "main.h"
#include "util.h"

int promptYesNoQuestion(const char question[128], const char exp[64], const char succ[128], const char fail[128])
{
	char answer[16];
	printf("Q: %s (yes/no)\nA: ",question);
	scanf("%15s",answer);
	// cc: free the buffer
	while(getchar() != '\n');
	char *t = toLowerCase(answer, sizeof answer/sizeof *answer);
	if(strcmp(t,exp) == 0)
	{
		printf("%s\n",succ);
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
	for(int i = 0; i < g->zorc->rm->objsize; i++)
	{
		printObject(g->zorc->rm->objs[i]);
	}
	printDoors(rm);
}

void printDoors(const struct room *room)
{
	for(int i = 0; i < 4; i++)
	{
		if(room->trans[i] != NULL)
		{
			printf("There's a %s to the %s.\n", room->trans[i]->name, getDirection(i));
		}
	}
}

void printObject(const struct object *object)
{
	printf("There is a %s in the room.\n", object->name);
}

void printObjectUse(const struct object *object)
{
	printf("%s\n", object->use);
}

void printMe(void *p)
{
	printf("Winter's cry comes as a song. Woken by a blade in the dark.\n");
}
