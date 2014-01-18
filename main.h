#ifndef MAIN_H
#define MAIN_H

// Game Version
enum version{
	maj = 0,
	min = 2,
	bld = 9
};

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

struct game {
	struct player *zorc;
	// list of commands
	struct command *cmds;
	int cmdsize;
	// list of rooms
	struct room *rms;
};

// exercise is healthy... exit is isRunning = 0;
extern int isRunning;

// inits/destructs TODO: sort this mess into inits>destructs>gets
struct game* initGame(void);
void destroyGame(struct game *);
struct door* initDoor(const char [21], int, int, int);

// promptypromptypromptprompts
int promptYesNoQuestion(const char [128], const char [64], const char [128], const char [128]);

//prints
void printVersion(void);
void printZorc(const struct game *);
void printRoom(const struct game *);
void printMe(void *);

//oh no, fail, explosion, fire...lots and lots of fire
void exitMe(struct game *);

// helpers
char * toLowerCase(char *, int);
#endif
