#ifndef MAIN_H
#define MAIN_H

// Game Version
enum version{
	maj = 0,
	min = 2,
	bld = 3
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

// door with keycode "vector"
struct door{
	int id;
	int code;
	char name[21];
	int isLocked;
	int direction;
	struct room *nxt;
};

struct key{
	// "Skeleton Key"
	char name[21];
	// key->code, door->code
	int code;
};

// room as "node"
struct room{
	int id;
	char name[21];
	char env[21];
	// door, ints enum direction
	struct door *trans[4];
	// dynamic array of objects
	// struct object *objs;
	// int objsize;
};

struct player{
	struct room *rm;
	char name[21];
	int direction;
};

struct game {
	struct player *zorc;
	// list of commands
	struct command *cmds;
	int cmdsize;
	// list of rooms
	struct room *rms;
};

// command struct with fp callback
struct command{
	char name[21];
	// 0 shown, 1 hidden.
	int hidden;
	void (*fp)(void *);
};

// exercise is healthy... exit is isRunning = 0;
extern int isRunning;

// inits/destructs TODO: sort this mess into inits>destructs>gets
struct game* initGame(void);
void destroyGame(struct game *);
struct room* initRoom(const char [21],const char [21]);
void connectRoom(struct room *,int, struct door *, struct room *);
struct player* initPlayer(const char [21]);

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
