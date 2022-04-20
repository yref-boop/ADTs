/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alejandro Fernandez Vazquez LOGIN 1: a.fernandez9
 * AUTHOR 2: Yago Fernandez Rego LOGIN 2: yago.fernandez.rego        
 * GROUP: *6.1*
 * DATE: 08 / 03 / 22
 */

#include "bid_stack.h"


void createEmptyStack(tStack *stack){
/*
 *  Goal:   creates an empty stack
 *  Input:  -stack (the stack)
 *  Output: the wanted stack
 *  Poscondition: the stack has no elements
 */
    stack -> top = -1;
}


bool push(tItemS item, tStack *stack){
/*
 *  Goal:   inserts an element at the top
 *  Input:  -item (the item to be inserted)
 *          -stack (the stack)
 *  Output: a boolean literal
 */
    if (++stack -> top != MaxStackSize) {
        stack->array[stack->top] = item;
		return true;
	}
	return false;
}

tStack pop (tStack *stack){
/*
 *  Goal:   removes the element on top
 *  Input:  -stack (the stack)
 *  Output: a the stack 
 *  Precondition: the stack is not empty
 */
    stack -> top --;
	return *stack;
}

tItemS peek (tStack stack){
/*
 *  Goal:   recover content of element at top
 *  Input:  -stack (a stack)
 *  Output: the element on top
 *  Precondition: the stack is not empty
 */
    return stack.array[stack.top];
}

bool isEmptyStack (tStack stack){
/*
 *  Goal:   check if list is empty
 *  Input:  -stack (a stack)
 *  Output: a boolean literal
 */
    return (stack.top == -1);
}
