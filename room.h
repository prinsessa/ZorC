#ifndef ROOM_H
#define ROOM_H

// door with keycode "vector"
struct door{
	int id;
	int code;
	char name[21];
	int isLocked;
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

struct room* initRoom(const char [21],const char [21]);
void connectRoom(struct room *,int, struct door *, struct room *);
void connectRooms(struct room *,int, struct door *, struct room *, struct door *);

#endif
