#include <stdbool.h>

#define SNULL NULL

// definition of the ints
typedef int tItemS;

// position is a pointer to node
typedef struct tNodeS* tPosS;

// definition of the node
struct tNodeS {
    tItemS data;
    tPosS down;
};

// definition of stack 
typedef tPosS tStack;

void createEmptyStack(tStack *stack);
bool createNode(tPosS *stack);
bool push(tItemS item, tStack *stack);
void pop(tStack *stack);
tItemS peek(tStack stack);
bool isEmptyStack(tStack stack);
