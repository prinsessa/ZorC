#ifndef MAIN_H
#define MAIN_H

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
	// should be able to hold a key/item, ex: table>skeleton key
};

// exercise is healthy... exit is isRunning = 0;
extern int isRunning;

//prints
void printZorc(const struct game *);
void printRoom(const struct game *);
void printDoors(const struct room *);
void printMe(void *);
#endif
