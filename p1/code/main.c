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

void new (char *product, char *seller, char *category, char *seller, tList *list);

void stat (tList *list);

void bid (char *product, char *bid, tList *list);

void delete (char *product, tList *list);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4) {

    switch (command) {
        case 'N': {
            printf("********************\n");
            printf("%s %c: product %s seller/bidder %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            new (param1, param2, param3, param4, list);
            break;
        }
        case 'S': {
            printf("********************\n");
            printf("%s %c: product %s seller/bidder %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            stat (list);
            break;
        }
            
        case 'B': {
            printf("********************\n");
            printf("%s %c: product %s seller/bidder %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            bid (param1, param2, list);
            break;}

        case 'D': {
            printf("********************\n");
            printf("%s %c: product %s seller/bidder %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            delete (param1, list);
            break;}

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

void stat(tList *list) {
    tPosL pos;
    tItemL auxProduct;

    int numBook = 0; numPaint = 0;
    float priceBook = 0; pricePaint = 0;
    float avgBook, avgPaint;

    if (isEmptyList (*list) == true)
        printf("+ Error: Stats not possible\n");
    else {
        pos = first(*list);
        while (pos != LNULL) {
            auxProduct = getItem(pos, *list);
            if(auxProduct.productCategory == 0) {
                numBook++;
                priceBook += auxProduct.productPrice
            }
            else {
                numPaint++;
                pricePaint += auxProduct.productPrice;
            }
            printf("Product %s seller %s category %s price %f bids %d", auxProduct.productId, auxProduct.seller, auxProduct.productCategory, auxProduct.productPrice, auxProduct.bidCounter);
            pos = next(pos, *list);
        }
        if (numBook == 0);
            avgBook = 0;
        else
            avgBook = priceBook/numBook;

        if (numPaint == 0)
            avgPaint = 0;
        else 
            avgPaint = pricePaint/numPaint;

        printf("%8s   %8s  %8.2s  %8.2s\n", "Category", "Products", "Price", "Average");
        printf("%8s   %8s  %8.2s  %8.2s\n", "Book", numBook, priceBook,avgBook);
        printf("%8s   %8s  %8.2s  %8.2s\n", "Painting", numPaint, pricePaint,avgPaint);
    }
}

void bid (char *product, char *bid, tList *list) {
    tItemL auxProduct;
    tPosL pos;
    tProductId auxProdId;

    if (isEmptyList(*list) == true)
        printf("+ Error: Bid not possible\n");
    else {
        strcpy (auxProdId, product);
        pos = findItem(auxProdId, *list);

        if (pos != LNULL) {
            auxProduct = getItem (pos, *list);
            auxProduct.bidCounter = bid;
            updateItem(auxProduct, pos, list);

            printf("* Bid: product %s seller %s category %s prize %f bids %d\n", auxProduct.productId, auxProduct.seller, auxProduct.productCategory, auxProduct.productPrice, auxProduct.bidCounter);
        }
        
        else printf("+ Error: Play not possible\n");
    }
}

void delete (char *product, tList *list) {
    tItemL auxProduct;
    tPosL pos;
    tProductId auxProdId;

    if (isEmptyList(*list) == true)
        printf("+ Error: Delete not possible\n");
    else {
        strcpy(auxProdId, product);
        pos = findItem(auxProdId, *list);
        if(pos != LNULL){
            auxProduct = getItem (pos, *list);
            printf("* Delete: product %s seller %s category %s prize %f bids %d\n", auxProduct.productId, auxProduct.seller, auxProduct.productCategory, auxProduct.productPrice, auxProduct.bidCounter);
            deleteAtPosition(pos, list);
        }
        else printf("+ Error: Delete not possible \n");
    }
}
