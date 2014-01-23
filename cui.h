#ifndef CUI_H
#define CUI_H

int promptYesNoQuestion(const char [128], const char [64], const char [128], const char [128]);

//prints
void printZorc(const struct game *);
void printRoom(const struct game *);
void printDoors(const struct room *);
void printObject(const struct object *);
void printObjectUse(const struct object *);
void printMe(void *);
#endif
