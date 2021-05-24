/*
 * File: avl_tree.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of AVL Tree Node structure.
*/

#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct avlnode
{
    char *path, *value;
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
AVL_Node *insertAVLPath(AVL_Node *h, char *path, char *value);
AVL_Node *insertAVLValue(AVL_Node *h, char *path, char *value);
char *searchPath(AVL_Node *h, char *path);
char *searchValue(AVL_Node *h, char *value);
AVL_Node *deleteAVLPath(AVL_Node *h, char *path);
AVL_Node *freeAVL(AVL_Node *h);
void listsInOrder(AVL_Node *h, char *aux[]);
int listsPathInOrder(AVL_Node *h, char *path, char *aux[]);

#endif