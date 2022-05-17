#include <stdbool.h>

#define LNULL (-1)
#define MAX 25

// definition of each item
typedef int tItemL;

// position defined as an int
typedef int tPosL;

// definition of nodes & list
typedef struct {
    tItemL data[MAX];
    tPosL lastPos;
} tList;

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
