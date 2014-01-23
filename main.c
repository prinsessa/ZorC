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
	connectRooms(g->zorc->rm, north, initDoor("door",0,0,0), initRoom("hall", "bloodied"), initDoor("door", 0,0,0));
	struct object makke = initObject("Makk3", "Makk3 seems to be a very bad Makk3!", 0);
	addObjectToRoom(&makke, g->zorc->rm);
	printVersion();
	promptYesNoQuestion("Will it be night by day?", "yes", "Hah! A spark of intelligence!", "Hah! You're only good for wielding a sword!");
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

struct object initObject(char name[32], char use [128], int isStatic)
{
	struct object object;
	strcpy(object.name, name);
	strcpy(object.use, use);
	object.isStatic = isStatic;
	return object;
}

void connectObjects(struct object *obja, struct object *objb)
{
	if(objb->isStatic == 1)
	{
		obja->obj = objb;
		return;
	}
	errAbort("Unable to add a non static object to a static object.\n");
}

void addKeyToObject(struct object *object, struct key *key, int isAct)
{
	object->key = key;
	object->isAct = isAct;
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
