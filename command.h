#ifndef COMMAND_H
#define COMMAND_H

// command struct with fp callback
struct command{
	char name[21];
	// 0 shown, 1 hidden.
	int hidden;
	void (*fp)(void *, char **, int);
};

void initCommands(struct game *);
struct command getCommand(const char[21], int, void *);

void promptCommand(struct game *);
struct command* parseCommand(struct game *, char *, int);

void printCommands(const struct game *);
void printCommandDummy(void *, char **, int);
void printCommandDummyArg(void *);

//oh no, fail, explosion, fire...lots and lots of fire
void exitMe(struct game *);
void errAbort(char *);

void commandTurnMe(void *, char **, int);
void commandOpenDoor(void *, char **, int);
void commandUnlockDoor(void *, char **, int);
void commandGoDirection(void *, char **, int);
#endif
