#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "command.h"
#include "room.h"

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
