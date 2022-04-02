/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Alejandro Fernandez Vazquez LOGIN 1: a.fernandez9
 * AUTHOR 2: Yago Fernandez Rego LOGIN 2: yago.fernandez.rego        
 * GROUP: *6.1*
 * DATE: 02 / 04 / 22
 */

#ifndef PRO2_2022_P2_TYPES_H
#define PRO2_2022_P2_TYPES_H


#define NAME_LENGTH_LIMIT 10

typedef char tUserId[NAME_LENGTH_LIMIT];
typedef char tProductId[NAME_LENGTH_LIMIT];
typedef enum {book, painting} tProductCategory;
typedef float tProductPrice;
typedef int tBidCounter;

#endif //PRO2_2022_P2_TYPES_H
