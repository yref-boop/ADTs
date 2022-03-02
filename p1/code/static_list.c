/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "static_list.h"
#include <string.h>

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
        return ++pos;
}

tPosL previous (tPosL pos, tList list) {
    return --pos;
}

bool insertItem (tItemL item, tPosL pos, tList *list) {
    tPosL i;

    if (list -> lastPos == MAX - 1)
        return false;
    else{

        if (pos == LNULL) {
            list -> lastPos++;
            list -> data[list->lastPos] = item;
        }
        else {
            list -> lastPos++;
            //move all elements one position to the right
            i = list -> lastPos;
            while(i > pos) {
                list -> data [i] = list -> data [i-1];
                i--;
            }
    
            //add given item
            list -> data [pos] = item;
        }
        return true;
    }
}

void deleteAtPosition (tPosL pos, tList *list) {
    tPosL i = pos;

    //move everything from deleted position 1 position to the left
    while (i < list->lastPos){
        list->data[i] = list-> data[i + 1];
        i++;
    }
    //remove last space
    list -> lastPos--;
}

tItemL getItem (tPosL pos, tList list) {
    return list.data[pos];
}

void updateItem (tItemL item, tPosL pos, tList *list) {
    list->data[pos] = item;
}

tPosL findItem (tProductId id, tList list) {
    tPosL i = 0;

    //check list not empty
    if(list.lastPos == LNULL)
        return LNULL;
    else {
        //check if any element satisfies id
        while (i <= list.lastPos){
            if (!(strcmp(list.data[i].productId,id)))
                return i;
            else i++;
        }
    }
    //if none does, return null
    return LNULL;
}
