#ifndef ZORC_H
#define ZORC_H

struct game {
	struct player *zorc;
	// list of commands
	struct command *cmds;
	int cmdsize;
	// list of rooms
	struct room *rms;
};

struct game* initGame(void);
void destroyGame(struct game *);
#endif
