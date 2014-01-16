#ifndef COMMAND_H
#define COMMAND_H

void initCommands(struct game *);
struct command getCommand(const char[21], int, void *);

void promptCommand(struct game *);
struct command* parseCommand(struct game *, char *);

void printCommands(const struct game *);
void errAbort(char *);
void printCommandDummy(void *);
#endif
