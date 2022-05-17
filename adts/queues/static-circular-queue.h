#include <stdbool.h>

#define MAX 10

// definition of the items
typedef int tItemQ;

// definition of the queue type
typedef struct queue {
    tItemQ data[MAX];
    int front, rear;
} tQueue;

void createEmptyQueue(tQueue *queue);
bool enqueue(tItemQ item, tQueue *queue);
void dequeue(tQueue *queue);
tItemQ front(tQueue queue);
bool isEmptyQueue(tQueue queue);
