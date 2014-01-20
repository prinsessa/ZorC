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
#include "util.h"
#include "cui.h"
int isRunning = 1;

int main(int argc, char *argv[])
{
	struct game *g = initGame();
	g->zorc = initPlayer("Tessa");
	g->zorc->rm = initRoom("spawnroom", "dark");
	connectRooms(g->zorc->rm, north, initDoor("door",0,0,0), initRoom("hall", "bloody"), initDoor("door", 0,0,0));
	printVersion();
	promptYesNoQuestion("When will it be night by day?", "yes", "Hah! A spark of intelligence!", "Hah! You're only good for wielding a sword!");
	initCommands(g);
	printCommands(g);
	printRoom(g);
	while(isRunning)
	{
		promptCommand(g);
	}
	destroyGame(g);
    return 0;
}

char * getDirection(int direction)
{
	switch(direction)
	{
		case (north):
			return NORTH;
		case (south):
			return SOUTH;
		case (east):
			return EAST;
		case (west):
			return WEST;
	}
	return NORTH;
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

void printMe(void *p)
{
	printf("Winter's cry comes as a song. Woken by a blade in the dark.\n");
}
