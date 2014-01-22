#ifndef PLAYER_H
#define PLAYER_H
struct player{
	struct room *rm;
	char name[21];
	int direction;
	struct key **keys;
	int keysize;
};

struct player* initPlayer(const char [21]);
#endif
