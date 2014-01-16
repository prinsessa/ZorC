#ifndef COMMAND_H
#define COMMAND_H

// command struct with fp callback
struct command{
	char name[21];
	// 0 shown, 1 hidden.
	int hidden;
	void (*fp)(void *);
};

void initCommands(struct game *);
struct command getCommand(const char[21], int, void *);

void promptCommand(struct game *);
struct command* parseCommand(struct game *, const char[16]);

void printCommands(const struct game *);
void printCommandDummy(void *);
#endif
