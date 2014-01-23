#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "zorc.h"
#include "object.h"
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
	struct object makke = initObject("makke", "Makke seems to be a very bad Makke!", 0);
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
