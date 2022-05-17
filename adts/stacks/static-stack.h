#include <stdbool.h>

#define SNULL -1
#define MAX 10

// definition of item and position
typedef int tItemS;
typedef int tPosS;

// definition of stack
typedef struct Stack {
    tItemS data[MAX];
    tPosS top;
} tStack;

void createEmptyStack(tStack *stack);
bool push(tItemS item, tStack *stack);
void pop(tStack *stak);
tItemS peek(tStack stack);
bool isEmptyStack(tStack stack);
