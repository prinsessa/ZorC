#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "object.h"
#include "command.h"

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
