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

void new (char *product, char *seller, char *category, char *price, tList *list);

void stat (tList *list);

void bid (char *product, char *bid, char *price, tList *list);

void delete (char *product, tList *list);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {

    switch (command) {
        case 'N': {
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            new (param1, param2, param3, param4, list);
            break;
        }
        case 'S': {
            printf("********************\n");
            printf("%s %c\n", commandNumber, command);
            stat (list);
            break;
        }
            
        case 'B': {
            printf("********************\n");
            printf("%s %c: product %s bidder %s price %s\n", commandNumber, command, param1, param2, param3);
            bid (param1, param2, param3, list);
            break;}

        case 'D': {
            printf("********************\n");
            printf("%s %c: product %s\n", commandNumber, command, param1);
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

    tList list;
    createEmptyList(&list);

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, &list);
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

char* extractCategory(tItemL prod) {

    // Translate the category to text.
    if (prod.productCategory == book)
        return "book";
    else
        return "painting";
}

tItemL addProduct (char *product, char *user, char *category, char *price) {
    
    tItemL aux_product;

    strcpy(aux_product.productId, product);

    strcpy(aux_product.seller, user);

    if (strcmp(category, "book") == 0)
        aux_product.productCategory = book;
    else
        aux_product.productCategory = painting;

    float num_price = atof(price);
    aux_product.productPrice = num_price;

    aux_product.bidCounter = 0;

    return aux_product;
}

void new (char *product, char *seller, char *category, char *price, tList *list) {
    //auxiliary item to add to the list
    tItemL auxProduct = addProduct (product, seller, category, price);

    if(findItem(auxProduct.productId, *list) == LNULL) {
        if (insertItem(auxProduct, LNULL, list) == true)
            printf("* New: product %s seller %s category %s price %s\n", auxProduct.productId, auxProduct.seller, extractCategory(auxProduct), price);
        else printf("+ Error: New not possible\n");
    }
    else printf("+ Error: New not possible\n");
}

void stat(tList *list) {
    tPosL pos;
    tItemL auxProduct;

    int numBook = 0; 
    int numPaint = 0;
    float priceBook = 0; 
    float pricePaint = 0;
    float avgBook, avgPaint;

    if (isEmptyList (*list) == true)
        printf("+ Error: Stats not possible\n");
    else {
        pos = first(*list);
        while (1) {
            auxProduct = getItem(pos, *list);
            if(auxProduct.productCategory == 0) {
                numBook++;
                priceBook += auxProduct.productPrice;
            }
            else {
                numPaint++;
                pricePaint += auxProduct.productPrice;
            }
            printf("Product %s seller %s category %s price %.2f bids %d\n", auxProduct.productId, auxProduct.seller, extractCategory(auxProduct), auxProduct.productPrice, auxProduct.bidCounter);
            if (pos == last(*list))
                break;
            else pos = next(pos, *list);
        }
        if (numBook == 0)
            avgBook = 0;
        else
            avgBook = priceBook/numBook;

        if (numPaint == 0)
            avgPaint = 0;
        else 
            avgPaint = pricePaint/numPaint;

        printf("\nCategory  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", numBook, priceBook,avgBook);
        printf("Painting  %8d %8.2f %8.2f\n", numPaint, pricePaint,avgPaint);
    }
}

void bid (char *product, char *bid, char *price, tList *list) {
    tItemL auxProduct;
    tPosL pos;
    tProductId auxProdId;
    float num_price = strtof(price, NULL);

    if ((isEmptyList(*list) == true))
        printf("+ Error: Bid not possible\n");
    else {
        strcpy (auxProdId, product);
        pos = findItem(auxProdId, *list);

        if (pos != LNULL) {
            auxProduct = getItem (pos, *list);
            if (!(strcmp(auxProduct.seller, bid)))
                printf("+ Error: Bid not possible\n");
            else {
                if (auxProduct.productPrice == num_price)
                    printf("+ Error: Bid not possible\n");
                else {
                    auxProduct.bidCounter++;
                    auxProduct.productPrice = num_price;
                    updateItem(auxProduct, pos, list);

                printf("* Bid: product %s seller %s category %s price %.2f bids %d \n", auxProduct.productId, auxProduct.seller, extractCategory(auxProduct), auxProduct.productPrice, auxProduct.bidCounter);
                }
            }
        }
        
        else printf("+ Error: Bid not possible\n");
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
            printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", auxProduct.productId, auxProduct.seller, extractCategory(auxProduct), auxProduct.productPrice, auxProduct.bidCounter);
            deleteAtPosition(pos, list);
        }
        else printf("+ Error: Delete not possible \n");
    }
}
