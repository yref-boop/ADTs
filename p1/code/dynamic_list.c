/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdlib.h>
#include <string.h>
#include "dynamic_list.h"

void createEmptyList (tList *list) {
    *list = LNULL;
}

bool createNode (tPosL *pos) {

    //auxiliar function that creates a node
    *pos = malloc (sizeof(struct tNode));
    return *pos != LNULL;
}

bool isEmptyList (tList list) {
    return (list == LNULL);
}

tPosL first (tList list) {
    return list;
}

tPosL last (tList list) {
    tPosL pos;

    //check all items from first until its next is null
    while (pos -> next != LNULL) {
        pos = pos -> next;
    }
    return pos;
}

tPosL next (tPosL pos, tList list) {
    return pos -> next;
}

tPosL previous (tPosL pos, tList list) {
    
    //if list is empty, return null
    if (list == LNULL)
        return LNULL;
    else {
        tPosL aux = list;

        //from the beggining go to the left until the 
        //next element is the one given
        while (aux -> next != pos)
            aux = aux -> next;
        return aux;
    }
}

bool insertItem (tItemL item, tPosL pos, tList *list) {
    tPosL aux_prev = *list;
    tPosL aux_node;

    //if the node cannot be created, return false
    if (!createNode(&aux_node))
        return false;
    else{

        //insert data into the node
        aux_node -> data = item;

        //list is empty
        if (*list == LNULL) {
            *list = aux_node;
            aux_node -> next = LNULL;
        }

        //first position is given
        else if (pos == *list) {
            aux_node -> next = *list;
            *list = aux_node;
        }

        //position on the middle or end
        else {
            while (aux_prev -> next != pos) 
                aux_prev -> next;
            if (pos == LNULL)
                aux_node -> next = LNULL;
            else
                aux_node -> next = aux_prev -> next;
            aux_prev -> next = aux_node;
        }
    }
}

void deleteAtPosition (tPosL pos, tList *list) {
    tPosL aux = *list;

    //given position iis first
    if (*list == pos)
        *list = pos -> next;

    //given position is last
    else if (pos -> next == LNULL) {
        while (aux -> next != pos)
            aux = aux -> next;
        aux -> next = LNULL;
    }
    //general case
    else {
        aux = pos -> next;
        pos -> data = aux -> data;
        pos -> next = aux -> next;
        pos = aux;
    }

    free (pos);
}

tItemL getItem (tPosL pos, tList list) {
    return pos -> data;
}

void updateItem (tItemL item, tPosL pos, tList *list) {
    pos -> data = item;
}

tPosL findItem (tProductId id, tList list) {
    tPosL aux = list;

    //check list not empty
    if(list == LNULL)
        return LNULL;
    else
        //check if any element satisfies id
        while (aux -> next != LNULL) {
            if (aux -> data.productId == id)
                return aux;
            else
                aux = aux -> next;
        }
    //if none does
    return LNULL;
}

