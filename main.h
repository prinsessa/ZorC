#ifndef MAIN_H
#define MAIN_H

#define NORTH "north"
#define EAST "east"
#define SOUTH "south"
#define WEST "west"
// direction used for rooms, player and objects
enum direction{
	north,
	east,
	south,
	west
};

enum visible{
	visible = 0,
	hidden = 1
};

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

// exercise is healthy... exit is isRunning = 0;
extern int isRunning;

struct object initObject(char [32], char [128], int);
void connectObjects(struct object *, struct object *);
void addKeyToObject(struct object *, struct key *, int);

char * getDirection(int);

//prints
void printZorc(const struct game *);
void printRoom(const struct game *);
void printDoors(const struct room *);
void printMe(void *);
#endif
