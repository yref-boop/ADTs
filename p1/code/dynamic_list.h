/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"

void createEmptyList (tList *l);
/*
 *  Goal:   creates an empty list
 *  Input:  -l (pointer to a list)
 *  Output: an empty list
 *  PostCD: the list is initialised and has no elements
 */

bool isEmptyList (tList l);
/*
 *  Goal:   check if list is empty
 *  Input:  -l ( a list)
 *  Output: a boolean literal
 */

tPosL first (tList l);
/*
 *  Goal:   creates an empty list
 *  Input:  -l (a list)
 *  Output: the position of the element
 *  PreCD:  the list is not empty
 *  PostCD: the list is initialised and has no elements
 */

tPosL last (tList l);
/*
 *  Goal:   returns position of last element on the list
 *  Input:  -l:     the list
 *  Output: a position
 *  PreCD: the indicated position is valid
 */

tPosL next (tPosL pos, tList l);
/*
 *  Goal:   returns position next to the one indicated
 *  Input:  -pos:   position
 *          -l:     the list
 *  Output: a position
 *  PreCD: the indicated position is valid
 */

tPosL previous (tPosL pos, tList l);
/*
 *  Goal:   returns position preceding the one indicated
 *  Input:  -pos:   position
 *          -l:     the list
 *  Output: a position
 *  PreCD: the indicated position is valid
 */

bool insertItem (tItemL item, tList *l);
/*
 *  Goal:   insert an element on the List on given position
 *  Input:  -item:  data of the item to be inserted
 *          -l:     pointer to the list
 *  Output: boolean 'true' if insertion is successful
 *  PreCD:  the specified condition is valid
 *  PostCD: the positions of the elements may change
 */

void deleteAtPosition (tPosL pos, tList *l);
/*
 *  Goal:   delete the element at given pos from the list
 *  Input:  -pos:   position of the item
 *          -l:     wanted list
 *  Output: an updated list without the given element
 *  PreCD:  the indicated position is valid on the list
 *  PostCD: the positions of the elements may change
 */

tItemL getItem (tPosL pos, tList l);
/*  Goal:   retrieves content of element at given pos
 *  Input:  -pos:   position of the item
 *          -l:     list
 *  Output: the item wanted
 *  PreCD:  the indicated position is valid
 */

void updateItem (tItemL item, tPosL pos, tList l);
/*
 *  Goal:   modifies the data of the item at given pos
 *  Input:  -item : the item
 *          -pos :  the position of the item
 *          -l :    a pointer to the list
 *  PreCD: the indicated position is valid on the list
 *  PostCD: the order of the elements is not modified
 */

tPosL findItem (tProductId id, tList l);
/*
 *  Goal:   return pos of first element on list with id (or LNULL)
 *  Input:  -id : the id of the item
 *          -l  : the list
 *  Output: the position of the item
 */

#endif
