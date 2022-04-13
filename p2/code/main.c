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
void stat (tList *list);
void bid (char *product, char *bid, char *price, tList *list);
void delete (char *product, tList *list);
void award (char *product, tList *list);
void withdraw (char *product, char *bid, tList *list);

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
            break;
		}
		case 'D': {
            printf("********************\n");
            printf("%s %c: product %s\n", commandNumber, command, param1);
            delete (param1, list);
            break;
		}
        case 'A': {
			printf("********************\n");
			printf("%s %c: product %s\n", commandNumber, command, param1);
			award (param1, list);
            break;
		}
        case 'W': {
			printf("********************\n");
			printf("%s %c: product %s bidder %s\n", commandNumber, command, param1, param2);
			withdraw (param1, param2, list);
            break;
		}
        case 'R':
            break;
        default:
            break;
    }
}

char* extractCategory(tItemL prod) {
    // translate the category to text.
    if (prod.productCategory == book)
        return "book";
    else
        return "painting";
}

tItemS addBid (char *bidder, char *price){
	tItemS aux_bid;

	strcpy(aux_bid.bidder, bidder);
	float num_price = atof(price);
	aux_bid.productPrice = num_price;

	return aux_bid;
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

void stat (tList *list){
	// start auxiliar
	tPosL pos;
    tItemL aux_product;
	tItemS aux_bid;
	char top_bidder[NAME_LENGTH_LIMIT];

	// table auxiliar data
    int numBook = 0; 
    int numPaint = 0;
    float priceBook = 0; 
    float pricePaint = 0;
    float avgBook, avgPaint;

	// top bid data
	tItemL tbid_product;
	tItemS tbid_bid;
	float tbid_val = 0.0;

    if (isEmptyList (*list) == true)
        printf("+ Error: Stats not possible\n");
    else {
        pos = first(*list);
        while (1) {
			// set the auxiliar product as the one corresponding to the iteration
            aux_product = getItem(pos, *list);
			// if there are bids, check if bid value is bigger than last
			if(!(isEmptyStack(aux_product.bidStack))){
				tbid_bid = peek(aux_product.bidStack);
				// if it is, store values 
				if(tbid_bid.productPrice > tbid_val){
					tbid_product = aux_product;
					tbid_val = tbid_bid.productPrice;
				}
			}

			// check if it is a book or a painint gand change corresponidng data
            if(aux_product.productCategory == 0) {
                numBook++;
                priceBook += aux_product.productPrice;
            }
            else {
                numPaint++;
                pricePaint += aux_product.productPrice;
            }
			// print all the contents of the product
			printf ("Product %s seller %s category %s price %.2f", aux_product.productId, aux_product.seller, extractCategory(aux_product), aux_product.productPrice);
			if(aux_product.bidCounter == 0)
				printf(". No bids\n");
			else {
				strcpy(top_bidder, peek(aux_product.bidStack).bidder);
				printf(" bids %d top bidder %s\n", aux_product.bidCounter, top_bidder);
			}

			// check condition to break the loop
			if (pos == last(*list))
                break;
            else pos = next(pos, *list);
        }
		// calculate average values 
        if (numBook == 0)
            avgBook = 0;
        else
            avgBook = priceBook/numBook;

        if (numPaint == 0)
            avgPaint = 0;
        else 
            avgPaint = pricePaint/numPaint;
		// print table 
        printf("\nCategory  Products    Price  Average\n");
        printf("Book      %8d %8.2f %8.2f\n", numBook, priceBook,avgBook);
        printf("Painting  %8d %8.2f %8.2f\n", numPaint, pricePaint,avgPaint);

		if (tbid_val == 0)
			printf("Top bid not possible\n");
		else{
			aux_bid = peek(tbid_product.bidStack);
			printf("Top bid: Product %s seller %s category %s price %.2f bidder %s top price %.2f increase %.2f%%\n", tbid_product.productId, tbid_product.seller, extractCategory(tbid_product), tbid_product.productPrice, aux_bid.bidder, aux_bid.productPrice, (aux_bid.productPrice/tbid_product.productPrice-1)*100);
		}
    }
}

void bid (char *product, char *bid, char *price, tList *list ){
	tItemL aux_product;
    tPosL pos;
    tProductId aux_id;
	tItemS aux_bid;

    float num_price = strtof(price, NULL);

    if ((isEmptyList(*list) == true))
        printf("+ Error: Bid not possible\n");
    else {
        strcpy (aux_id, product);
        pos = findItem(aux_id, *list);

        if (pos != LNULL) {
            aux_product = getItem (pos, *list);
            if (!(strcmp(aux_product.seller, bid)))
                printf("+ Error: Bid not possible\n");
            else {
                if (aux_product.productPrice >= num_price)
                    printf("+ Error: Bid not possible\n");
                else {
                    aux_product.bidCounter++;

					aux_bid = addBid(bid, price);
					if (push(aux_bid, &aux_product.bidStack)){
                    	updateItem(aux_product, pos, list);
                		printf("* Bid: product %s bidder %s category %s price %.2f bids %d \n", aux_product.productId, bid, extractCategory(aux_product), atof(price), aux_product.bidCounter);
					}
                }
            }
        }   
        else printf("+ Error: Bid not possible\n");
    }
}

void delete (char *product, tList *list) {
    tItemL aux_product;
    tPosL pos;
    tProductId aux_id;

    if (isEmptyList(*list) == true)
        printf("+ Error: Delete not possible\n");
    else {
        strcpy(aux_id, product);
        pos = findItem(aux_id, *list);
        if(pos != LNULL){
            aux_product = getItem (pos, *list);
            printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", aux_product.productId, aux_product.seller, extractCategory(aux_product), aux_product.productPrice, aux_product.bidCounter);
			while (!(isEmptyStack(aux_product.bidStack)))
				pop(&aux_product.bidStack);
            deleteAtPosition(pos, list);
        }
        else printf("+ Error: Delete not possible \n");
    }
}

void award (char *product, tList *list) {
	tItemL aux_product;
	tItemS aux_bid;
	tPosL pos;
	tProductId aux_id;

	if(!(isEmptyList(*list))){
		strcpy(aux_id, product);
		pos = findItem(aux_id, *list);
		if(pos != LNULL){
			aux_product = getItem(pos, *list);
			if (!(isEmptyStack(aux_product.bidStack))){
				aux_bid = peek(aux_product.bidStack);
				printf("* Award: product %s bidder %s category %s price %.2f\n", aux_product.productId, aux_bid.bidder, extractCategory(aux_product), aux_bid.productPrice);
			}
			while (!(isEmptyStack(aux_product.bidStack)))
				pop(&aux_product.bidStack);
			deleteAtPosition(pos, list);
		}
	}
	else printf ("+ Error: Award not possible");
}

void withdraw (char *product, char *bid, tList *list) {
	tItemL aux_product;
	tItemS aux_bid;
	tPosL pos;
	tProductId aux_id;

	if(!(isEmptyList(*list))){
		strcpy (aux_id, product);
		pos = findItem(aux_id, *list);
		if(pos != LNULL){
			aux_product = getItem(pos, *list);
			if(!(isEmptyStack(aux_product.bidStack))){
				aux_bid = peek(aux_product.bidStack);
				if(!(strcmp(aux_bid.bidder, bid))){
					pop(&aux_product.bidStack);
					printf("* Withdraw: product %s bidder %s category %s price %.2f bids %d\n", aux_product.productId, aux_bid.bidder, extractCategory(aux_product), aux_bid.productPrice, aux_product.bidCounter);
					aux_product.bidCounter--;
					updateItem(aux_product, pos, list);
				}
			}
		}
	}
	else printf ("+ Error: Withdraw not possible");
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
