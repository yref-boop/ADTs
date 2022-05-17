#include <stdbool.h>

#define TNULL NULL

// define item
typedef int tItemT;

// position is a pointer to a node
typedef struct tNodeT *tPosT;

// definition of node
struct tNodeT {
    tItemT data;
    tPosT right;
    tPosT left;
};
typedef tPosT tBinTree;

void CreateEmptyTree(tBinTree *tree);
bool BuildTree(tBinTree left_tree, tItemT item, tBinTree right_tree, tBinTree *tree);
tBinTree LeftChild(tBinTree tree);
tBinTree RightChild(tBinTree tree);
tItemT Root(tBinTree tree);
bool IsEmptyTree(tBinTree tree);
void deleteTree(tBinTree *tree);
