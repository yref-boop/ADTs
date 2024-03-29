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
/*
goal  : add a new product added by a
input :
	- product: a string representing the products id
	- seller: a string representing the seller's name
	- price: a string representing the price of the product
	- list: the list where we wish to operate
output: the list with the corresponding changes if successful, with one more product
preCD : the list must have been initialized and the string of the category must be one of the two existing options
postCD: the positions of the elements in the list following that of the inserted product may have varied
*/

void stat (tList *list);
/*
goal  : print the list of products, its data and a table containing info of the products and their category
input :
	- list: the list where we wish to operate
output: printed on screen info about the current state of the list
preCD : the list must have been initialized
postCD: the list must not be altered
*/

void bid (char *product, char *bid, char *price, tList *list);
/*
goal  : add a new bid to the stack of a product
input :
	- product: a string representing the products id
	- seller: a string representing the bidders's name
	- price: a string representing the bid price of the product
	- list: the list where we wish to operate
output: the list with the corresponding changes
preCD : the list must have been initialized
postCD: the list must not vary, but the given product has a new entry on top of its stack
*/

void delete (char *product, tList *list);
/*
goal  : delete a product
input :
	- product: a string representing the products id
	- list: the list where we wish to operate
output: the list with the corresponding changes if successful, with one less product
preCD : the list must have been initialized
postCD: the positions of the elements in the list following that of the deleted product may have varied
*/

void award (char *product, tList *list);
/*
goal  : declare the winning bidder 
input :
	- product: a string representing the products id
	- list: the list where we wish to operate
output: the list with the corresponding changes if conditions met, with one less 
preCD : the list must have been initialized
postCD: the element on the list may have been deleted (if a winner was found successfully)
*/

void withdraw (char *product, char *bid, tList *list);
/*
goal  : deletes the highest bid of a product
input :
	- product: a string representing the products id
	- bid: a string representing the price of the product
	- list: the list where we wish to operate
output: the list without changes, only a products stack has been reduced by 1
preCD : the list must have been initialized
*/

void remove_product (tList *list);
/*
goal  : remove a product
input :
	- product: a string representing the products id
	- list: the list where we wish to operate
output: the list with the corresponding changes if successful, with one less product
preCD : the list must have been initialized
postCD: the positions of the elements in the list following that of the deleted product may have varied
*/


void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *list) {
	/*
goal  : process each command available and print its respective information.
input :
	commandNumber: the assigned command number
	command: the command of the operation to use
	param1: first of the multipurpose parameters which will be used in the selected operation
	param2: second of the multipurpose parameters
	param3: third multipurpose parameter
	param4: fourth multipurpose parameter 
	list: the list where we wish to operate
output: the list with the corresponding changes (if any)
preCD : the list must have been initialized
*/

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
        case 'R':{
			printf("********************\n");
			printf("%s %c\n", commandNumber, command);
			remove_product (list);
            break;
		}
        default:
            break;
    }
}

char* extractCategory(tItemL prod) {
/*
	goal  : convert the item's category variable into a string.
	input :
		item: the element from which we want to extract the category.
	output: a string with one of the two categories.
	preCD : the category must be one of the existing options.
*/
    // translate the category to text.
    if (prod.productCategory == book)
        return "book";
    else
        return "painting";
}

tItemS addBid (char *bidder, char *price){
/*
	goal: create a bid
	input:
		bidder: the string that represents the name of the bidder
		price: the string representing the value of the new bid 
	output: the item corresponfing to the bid
*/

	tItemS aux_bid;

	strcpy(aux_bid.bidder, bidder);
	float num_price = atof(price);
	aux_bid.productPrice = num_price;

	return aux_bid;
}

tItemL addProduct (char *product, char *seller, char *category, char *price){
/*
	goal: create a bid
	input:
		product: the string that represents the id of the product
		seller: the string that represents the name of the bidder
		category: the string representing the category 
		price: the string representing the value of the new bid 
	output: the item corresponfing to the product
	preCD: the string of the category must be one of the existing options
*/

	// create the product
	tItemL aux_product;

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
	// start auxiliary
	tPosL pos;
    tItemL aux_product;
	tItemS aux_bid;
	char top_bidder[NAME_LENGTH_LIMIT];

	// table auxiliary data
    int numBook = 0; 
    int numPaint = 0;
    float priceBook = 0; 
    float pricePaint = 0;
    float avgBook, avgPaint;

	// top bid data
	tItemL tbid_product;
	tItemS tbid_bid;
	float tbid_val = 0;

    if (isEmptyList (*list) == true)
        printf("+ Error: Stats not possible\n");
    else {
        pos = first(*list);
        while (1) {
			// set the auxiliary product as the one corresponding to the iteration
            aux_product = getItem(pos, *list);
			// if there are bids, check if bid value is bigger than last
			if (!(isEmptyStack(aux_product.bidStack))){
				tbid_bid = peek(aux_product.bidStack);
				// if it is, store values
				if ((tbid_bid.productPrice/aux_product.productPrice)*100 > tbid_val){
					tbid_product = aux_product;
					tbid_val = (tbid_bid.productPrice/aux_product.productPrice)*100;
				}
			}

			// check if it is a book or a painting and change corresponding data
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
			if (pos == last(*list)) break;
			else pos = next(pos, *list);
        }
		// calculate average values 
        if (numBook == 0)
            avgBook = 0;
        else
            avgBook = priceBook/((float)numBook);

        if (numPaint == 0)
            avgPaint = 0;
        else 
            avgPaint = pricePaint/((float)numPaint);
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

tPosL exists(char *product, tList *list){
	tProductId aux_id;

	// check if list is empty
	if ((isEmptyList(*list)))
		return LNULL;

	// search for the product by id and return the result
	strcpy (aux_id, product);
	return findItem(aux_id, *list);
}

void bid (char *product, char *bid, char *price, tList *list ){
	// auxiliary data
	tItemL aux_product;
    tPosL pos;
	tItemS aux_bid;

    float num_price = strtof(price, NULL);

	// check if there exists a product on the list with the wanted id
	pos = exists(product,list);

	//check if position was found
    if (pos != LNULL) {
    	aux_product = getItem (pos, *list);
		// check that the bidder is not the same as the seller
        if (!(strcmp(aux_product.seller, bid)))
            printf("+ Error: Bid not possible\n");
        else {
			// check condition for the stack
			if (!(isEmptyStack(aux_product.bidStack))){
				if (peek(aux_product.bidStack).productPrice >= num_price){
					printf("+ Error: bid not possible\n");
					return;
				}
			}
			// check condition for the initial price
            if (aux_product.productPrice >= num_price)
                printf("+ Error: Bid not possible\n");
            else {
                aux_product.bidCounter++;
				aux_bid = addBid(bid, price);
				// check if bid can be inserted
				if (push(aux_bid, &aux_product.bidStack)){
                	updateItem(aux_product, pos, list);
            		printf("* Bid: product %s bidder %s category %s price %.2f bids %d \n", aux_product.productId, bid, extractCategory(aux_product), atof(price), aux_product.bidCounter);
				}
            }
        }        
	}   
    else printf("+ Error: Bid not possible\n");
}

void delete (char *product, tList *list) {
	// auxiliary data
    tItemL aux_product;
    tPosL pos;

	// check if there exists a product on the list with the wanted id
	pos = exists(product, list);

	//if it does
    if(pos != LNULL){
        aux_product = getItem (pos, *list);
		printf("* Delete: product %s seller %s category %s price %.2f bids %d\n", aux_product.productId, aux_product.seller, extractCategory(aux_product), aux_product.productPrice, aux_product.bidCounter);
		// first delete contents of the stack and then the product
		while (!(isEmptyStack(aux_product.bidStack)))
			pop(&aux_product.bidStack);
        deleteAtPosition(pos, list);
    }
    else printf("+ Error: Delete not possible \n");
}


void award (char *product, tList *list) {
	// auxiliary data
	tItemL aux_product;
	tItemS aux_bid;
	tPosL pos;

	// check if there exists a product on the list with the wanted id
	pos = exists(product, list);

	//if it does
	if(pos != LNULL){
		aux_product = getItem(pos, *list);
		// check if the stack is empty
		if (!(isEmptyStack(aux_product.bidStack))){
			aux_bid = peek(aux_product.bidStack);
			printf("* Award: product %s bidder %s category %s price %.2f\n", aux_product.productId, aux_bid.bidder, extractCategory(aux_product), aux_bid.productPrice);
		}
		// first delete all the contents of the stack and then erase the item
		while (!(isEmptyStack(aux_product.bidStack)))
			pop(&aux_product.bidStack);
		deleteAtPosition(pos, list);
	}
	else printf ("+ Error: Award not possible");
}

void withdraw (char *product, char *bid, tList *list) {
	// auxiliary data
	tItemL aux_product;
	tItemS aux_bid;
	tPosL pos;

	// check if there exists a product on the list with the wanted id
	pos = exists(product, list);

	//if it does
	if(pos != LNULL){
		aux_product = getItem(pos, *list);
		// check if the bid stack is empty
		if(!(isEmptyStack(aux_product.bidStack))){
			aux_bid = peek(aux_product.bidStack);
			// check if the biggest bid was made by given bidder
			if(!(strcmp(aux_bid.bidder, bid))){
				// pop that bid and update the item
				pop(&aux_product.bidStack);
				printf("* Withdraw: product %s bidder %s category %s price %.2f bids %d\n", aux_product.productId, aux_bid.bidder, extractCategory(aux_product), aux_bid.productPrice, aux_product.bidCounter);
				aux_product.bidCounter--;
				updateItem(aux_product, pos, list);
			}
		}
	}
	else printf ("+ Error: Withdraw not possible");
}

void remove_product (tList *list) {
	// auxiliary data
	tItemL aux_product;
	tPosL pos = first(*list);
	int count = 0;

	// check if list is empty
	if (!(isEmptyList(*list))){
		//check the condition on all elements of the list
		do{
			aux_product = getItem (pos, *list);
			// if its bid stack is empty, remove first, then change bid counter
			if (isEmptyStack(aux_product.bidStack)){
				printf("Removing product %s seller %s category %s price %.2f bids %d\n", aux_product.productId, aux_product.seller, extractCategory(aux_product), aux_product.productPrice, aux_product.bidCounter);
				deleteAtPosition(pos, list);
			}
			// only change position if the element is the last
			else pos = next(pos, *list); 
			count ++;
		} while (pos != LNULL);
		// if no element has been removed, print error
		if (count < 1) printf ("+ Error: Remove not possible");
	}
	else printf ("+ Error: Remove not possible");
}

void readTasks(char *filename) {
/*
	goal  : read the input files and start each process.
	input :
		-filename: the filed used as input from which the instructions are readed.
	output: the list with all the changes (if any).
	preCD : the input file must be an existing one.
*/


    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

	// create an empty list 
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
