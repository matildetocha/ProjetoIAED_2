/*
 * File: avl_tree.c
 * Author:  Matilde Tocha 99108
 * Description: Functions to insert a node in AVL tree.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "avl_tree.h"

/* Allocates a new node with the given path, value and NULL left and 
right pointers. */
AVL_Node *newAVL(char *path, char *value)
{
    AVL_Node *h = (AVL_Node*) malloc(sizeof(AVL_Node));
    h->path = (char*) malloc(sizeof(char) * (strlen(path) + 1));
    h->value = (char*) malloc(sizeof(char) * (strlen(value) + 1));

    strcpy(h->path, path);
    strcpy(h->value, value);
    h->l = NULL;
    h->r = NULL;
    h->height = 1;
    return h;
}

/* Gets the height of the tree. */
int height(AVL_Node *h)
{
    if (h == NULL)
        return 0;
    return h->height;
}

/* Updates the height of the given head. */
void updateHeight(AVL_Node *h)
{
    int height_left = height(h->l);
    int height_right = height(h->r);
    h->height = height_left > height_right ? height_left + 1 : height_right + 1;
}

/* Left rotates the subtree rooted with h. */
AVL_Node *rotL(AVL_Node *h)
{
    AVL_Node *x = h->r;
    h->r = x->l;
    x->l = h;
    updateHeight(h);
    updateHeight(x);
    return x;
}

/* Right rotates the subtree rooted with h. */
AVL_Node *rotR(AVL_Node *h)
{
    AVL_Node *x = h->l;
    h->l = x->r;
    x->r = h;
    updateHeight(h);
    updateHeight(x);
    return x;
}

/* Left and right rotates the subtree rooted with h. */
AVL_Node *rotLR(AVL_Node *h)
{
    if (h == NULL)
        return h;
    h->l = rotL(h->l);
    return rotR(h);
}

/* Right and left rotates the subtree rooted with h. */
AVL_Node *rotRL(AVL_Node *h)
{
    if (h == NULL)
        return h;
    h->r = rotR(h->r);
    return rotL(h);
}

/* Gets the balance factor of the given head. */
int balance(AVL_Node *h)
{
    if (h == NULL)
        return 0;
    return height(h->l) - height(h->r);
}

AVL_Node *balanceAVL(AVL_Node *h)
{
    int balanceFactor;
    if (h == NULL)
        return h;

    balanceFactor = balance(h);

    if (balanceFactor > 1)
    {
        if (balance(h->l) >= 0)
            h = rotR(h);
        else
            h = rotLR(h);
    }
    else if (balanceFactor < -1)
    {
        if (balance(h->r) <= 0)
            h = rotL(h);
        else
            h = rotRL(h);
    }
    else
        updateHeight(h);
    return h;
}

/* Recursive function to insert a path and a value in the subtree rooted with
head and returns the new head of the subtree. */
AVL_Node *insertAVL(AVL_Node *h, char *path, char *value)
{
    if (h == NULL)
        return newAVL(path, value);

    if (strcmp(path, h->path) < 0)
        h->l = insertAVL(h->l, path, value);

    else if (strcmp(path, h->path) > 0)
        h->r = insertAVL(h->r, path, value);

    h = balanceAVL(h);

    return h;
}

char *searchPath(AVL_Node *h, char *path)
{
    if (!h)
    {
        printf(FIND_ERROR1);
        return NULL;
    }
    if (strcmp(path, h->path) == 0)
    {
        if (h->value)
            return h->value;
        else
            printf(FIND_ERROR2);
    }
    if (strcmp(path, h->path) < 0) {
        return searchPath(h->l, path);
    }
    else {
        return searchPath(h->r, path);
    }
}

char *searchValue(AVL_Node *h, char *value)
{
    if (!h)
    {
        printf(FIND_ERROR1);
        return NULL;
    }
    if (strcmp(value, h->value) == 0)
    {
        if (h->path)
            return h->path;
    }
    if (strcmp(value, h->value) < 0) {
        return searchPath(h->l, value);
    }
    else {
        return searchPath(h->r, value);
    }
}

void traversePreOrder(AVL_Node *h)
{
    if (h)
    {
        printf("%s %s\n", h->path, h->value);
        traversePreOrder(h->l);
        traversePreOrder(h->r);
    }
}