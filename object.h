#ifndef OBJECT_H
#define OBJECT_H

struct object{
	char name[32];
	// ex: show door > "Nothing happened!"
	char use[128];
	// static objects cannot be put into inventory
	int isStatic;
	struct object *obj;
	// should be able to hold a key/item, ex: table>skeleton key
	struct key *key;
	// need activation in order to show obj/key
	int isAct;
};

struct object initObject(char [32], char [128], int);
void connectObjects(struct object *, struct object *);
void addKeyToObject(struct object *, struct key *, int);

#endif
