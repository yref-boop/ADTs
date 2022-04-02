/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alejandro Fernandez Vazquez LOGIN 1: a.fernandez9
 * AUTHOR 2: Yago Fernandez Rego LOGIN 2: yago.fernandez.rego
 * GROUP: *6.1*
 * DATE: 02 / 04 / 22
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include "types.h"

#define MaxStackSize 10
#define SNULL = NULL

#include <stdbool.h>
typedef int tPosS;

typedef struct {
    tUserId bidder;
    tProductPrice productPrice;
} tItemS;

typedef struct {
    int top;
    tItemS array[MaxStackSize];
} tStack;


void createEmptyStack(tStack *stack);
/*
 *  Goal:   creates an empty stack
 *  Input:  -stack (the stack)
 *  Output: the wanted stack
 *  Poscondition: the stack has no elements
 */

bool push(tItemS item, tStack *stack);
/*
 *  Goal:   inserts an element at the top
 *  Input:  -item (the item to be inserted)
 *          -stack (the stack)
 *  Output: a boolean literal
 */

tStack pop (tStack *stack);
/*
 *  Goal:   removes the element on top
 *  Input:  -stack (the stack)
 *  Output: a the stack 
 *  Precondition: the stack is not empty
 */

tItemS peek (tStack stack);
/*
 *  Goal:   recover content of element at top
 *  Input:  -stack (a stack)
 *  Output: the element on top
 *  Precondition: the stack is not empty
 */

bool isEmptyStack (tStack stack);
/*
 *  Goal:   check if list is empty
 *  Input:  -stack (a stack)
 *  Output: a boolean literal
 */

#endif
