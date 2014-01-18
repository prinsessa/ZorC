#ifndef NPC_H
#define NPC_H

struct npc{
	char name[16];
	int hp;
	int isActive;
	struct obj *holding;
	// struct speechtree *st;
};

struct npc initNpc(char [16], int);
struct obj getObjFromNpc(struct npc *, char [16]);

#endif
