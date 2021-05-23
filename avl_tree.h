/*
 * File: avl_tree.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of AVL Tree Node structure.
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct avlnode
{
    char *path;
    char *value;
    struct avlnode *l, *r;
    int height;
} AVL_Node;


AVL_Node *newAVL(char *path, char *value);
int height(AVL_Node *h);
void updateHeight(AVL_Node *h);
AVL_Node* rotL(AVL_Node *h);
AVL_Node* rotR(AVL_Node *h);
AVL_Node* rotLR(AVL_Node *h);
AVL_Node* rotRL(AVL_Node *h);
int balance(AVL_Node *h);
AVL_Node* balanceAVL(AVL_Node *h);
AVL_Node *insertAVL(AVL_Node *h, char *path, char *value);
char *searchPath(AVL_Node *h, char *path);
char *searchValue(AVL_Node *h, char *value);
void traversePreOrder(AVL_Node *h);

#endif