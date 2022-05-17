#include <stdbool.h>

#define QNULL NULL

// definition of the items
typedef int tItemQ;

// position is a pointer to a node
typedef struct tNodeQ* tPosQ;

// definition of the node
struct tNodeQ {
    tItemQ item;
    tPosQ next;
};

// definition of the queue 
typedef struct Queue{
    tPosQ front;
    tPosQ rear;
} tQueue;

void createEmptyQueue(tQueue *queue);
bool enqueue(tItemQ item, tQueue *queue);
void dequeue(tQueue *queue);
tItemQ front(tQueue queue);
bool isEmptyQueue(tQueue queue);
