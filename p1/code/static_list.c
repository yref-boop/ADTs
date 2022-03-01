/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"

void createEmptyList (tList *list) {
    list -> lastPos = LNULL;
}

bool isEmptyList (tList list) {
    return (list.lastPos == LNULL);
}

tPosL first (tList l) {
    return 0;
}

tPosL last (tList list) {
    return list.lastPos;
}

tPosL next (tPosL pos, tList list) {
    if (pos == list.lastPos)
        return LNULL;
    else
        return pos++;
}

tPosL previous (tPosL pos, tList list) {
    return pos--;
}

bool insertItem (tItemL item, tPosL pos, tList *list) {
    tPosL i = pos;

    //add extra space
    list -> lastPos++;

    //move all elements one position to the right
    while(i <= list -> lastPos)
        list -> data[i + 1] = list -> data[i];
    
    //add given item
    list -> data[pos] = item;
    return true;
}

void deleteAtPosition (tPosL pos, tList *list) {
    tPosL i = pos;

    //move everything from deleted position 1 position to the left
    while (i < list->lastPos)
        list->data[i] = list-> data[i + 1];

    //remove last space
    list -> lastPos--;
}

tItemL getItem (tPosL pos, tList list) {
    return list.data[pos];
}

void updateItem (tItemL item, tPosL pos, tList list) {
    list.data[pos] = item;
}

tPosL findItem (tProductId id, tList list) {
    tPosL i = 0;

    //check list not empty
    if(isEmptyList(list))
        return LNULL;
    else
        //check if any element satisfies id
        while (i <= list.lastPos){
            if (list.data[i].productId == id)
                return i;
            else
                i++;
        }
    //if none does, return null
    return LNULL;
}
