/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

void new (char product, char seller, char category, char seller, tList *list);


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {

    switch (command) {
        case 'N': {
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            new (param1, param2, param3, param4, list);
            break;
        }
        case 'S': {break;}
            
        case 'B': {break;}
        case 'D': {break;}
        default: {
            printf("+ Error: Process command not possible");
            break;
        }
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}

tItemL addProduct (char *product, char *user, char *category, char *price) {
    
    tItemL product;

    strcpy(product.productId, product);

    strcpy(product.seller, user);

    if (strcmp(category, "book") == 0)
        product.productCategory = book;
    else
        product.productCategory = painting;

    float num_price = atof(price);
    product.productPrice = num_price;

    product.bidCounter = 0;

    return user;
}

void new (char *product, char *seller, char *category, char *price, tList *list) {
    //auxiliary item to add to the list
    tItemL auxProduct = addProduct (product, seller, category, price);

    if(LNULL == findItem(auxProduct.productID , *list)) {

        if (insertItem(auxProduct, LNULL, list) == true)
            printf("* New: product %s seller %s category %s price %s\n" );
        else printf("+ Error: New not possible\n");
    }
    else printf("+ Error: New not possible\n");
}



