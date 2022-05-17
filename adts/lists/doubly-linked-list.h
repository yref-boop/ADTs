#include <stdbool.h>

#define LNULL NULL

// definition of each item
typedef int tItemL;

// position is a pointer to a node
typedef struct tNode* tPosL;

// definition of nodes & list
struct tNode {
    tItemL data;
    tPosL next;
    tPosL prev;
};
typedef tPosL tList;

void createEmptyList (tList *l);
bool isEmptyList (tList l);
tPosL first (tList l);
tPosL last (tList l);
tPosL next (tPosL pos, tList l);
tPosL previous (tPosL pos, tList l);
bool insertItem (tItemL item, tPosL pos, tList *l);
void deleteAtPosition (tPosL pos, tList *l);
tItemL getItem (tPosL pos, tList l);
void updateItem (tItemL item, tPosL pos, tList *l);
tPosL findItem (tItemL item, tList l);
