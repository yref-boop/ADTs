#include "dynamic-tree.h"
#include <stdio.h>

// preorder
void preorder (tBintTree tree) {
    
    if (tree == NULL) return;
    
    printf("%d", tree -> data);
    preorder(tree -> left);
    preorder(tree -> right);
}

// inorder
void inorder (tBinTree tree) {

    if (tree == NULL) return;

    inorder(tree -> left);
    printf("%d", tree -> data);
    inorder(tree -> right);
}

// postorder
void postorder (tBinTree tree) {

    if (tree == NULL) return;

    postorder (tree -> left);
    postorder (tree -> right);
    printf("%d", tree -> data);
}
