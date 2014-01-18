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
	char name[21];
	// ex: show door > "Nothing happened!"
	char use[128];
	// should be able to hold a key/item, ex: table>skeleton key
};

// exercise is healthy... exit is isRunning = 0;
extern int isRunning;

// inits/destructs TODO: sort this mess into inits>destructs>gets
struct door* initDoor(const char [21], int, int, int);

// promptypromptypromptprompts
int promptYesNoQuestion(const char [128], const char [64], const char [128], const char [128]);

//prints
void printZorc(const struct game *);
void printRoom(const struct game *);
void printMe(void *);

// helpers
char * toLowerCase(char *, int);
#endif
