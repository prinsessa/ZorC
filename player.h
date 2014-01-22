#ifndef PLAYER_H
#define PLAYER_H
struct player{
	struct room *rm;
	char name[21];
	int direction;
	struct key *keys;
	int keysize;
	struct object *inv;
	int invsize;
};

struct player* initPlayer(const char [21]);
void addToInventory(void *, char **, int);
void setPlayerDirection(struct game *, char **, int);
#endif
