/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Alejandro Fernandez Vazquez LOGIN 1: a.fernandez9
 * AUTHOR 2: Yago Fernandez Rego LOGIN 2: yago.fernandez.rego
 * GROUP: 6.1
 * DATE: 12 / 04 / 22
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#include "bid_stack.h"
#include "product_list.h"

void new (char *product, char *seller, char *category, char *price, tList *list);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {

    switch (command) {
        case 'N': {
            printf("********************\n");
            printf("%s %c: product %s seller %s category %s price %s\n", commandNumber, command, param1, param2, param3, param4);
            new (param1, param2, param3, param4, list);
            break;
        }
        case 'S':
            break;
        case 'B':
            break;
        case 'D':
            break;
        case 'A':
            break;
        case 'W':
            break;
        case 'R':
            break;
        default:
            break;
    }
}

char* extractCategory(tItemL prod) {

    // Translate the category to text.
    if (prod.productCategory == book)
        return "book";
    else
        return "painting";
}

tItemL addProduct (char *product, char *seller, char *category, char *price){
	// create the product
	tItemL aux_product;

	// get and store its properties:

	// get the product id and seller
    strcpy(aux_product.productId, product);
    strcpy(aux_product.seller, seller);
	// categorize the category
    if (strcmp(category, "book") == 0)
        aux_product.productCategory = book;
    else
        aux_product.productCategory = painting;
	// set the price
    float num_price = atof(price);
    aux_product.productPrice = num_price;
	// set bid counter to 0
    aux_product.bidCounter = 0;
	// create an empty bid stack
	createEmptyStack(&aux_product.bidStack);
    return aux_product;
}

void new (char *product, char *seller, char *category, char *price, tList *list){
	// create a product with all the wanted properties
	tItemL aux_product = addProduct(product, seller,category,price);

	// check if an item with the same id already exists
	if(findItem(aux_product.productId, *list) == LNULL) {
		// if it doesn't, try to insert it on the list
		if (insertItem(aux_product, list))
			printf("* New: product %s seller %s category %s price %s\n", aux_product.productId, aux_product.seller, extractCategory(aux_product), price);
		else printf("+ Error: New not possible\n");
	}
	else printf("+ Error: New not possible \n");
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






