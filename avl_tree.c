/*
 * File: avl_tree.c
 * Author:  Matilde Tocha 99108
 * Description: Functions to create, insert, search and delete a node
 * in an AVL tree as well as print all nodes in alphabetical order.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "avl_tree.h"
#include "handle_str.h"

/* Allocates a new node with the given path, value and NULL left and 
right pointers. */
AVL_Node *newAVL(char *path, char *value) {
    AVL_Node *h = (AVL_Node*) malloc(sizeof(AVL_Node)); 
    if (!h) puts(NO_MEMORY);
    h->path = (char*) malloc(sizeof(char) * (strlen(path) + 1)); 
    if (!h->path) puts(NO_MEMORY);
    h->value = (char*) malloc(sizeof(char) * (strlen(value) + 1)); 
    if (!h->value) puts(NO_MEMORY);
    
    strcpy(h->path, path);
    strcpy(h->value, value);
    h->l = NULL;
    h->r = NULL;
    h->height = 1;

    return h;
}

/* Gets the height of the tree. */
int height(AVL_Node *h) {
    if (!h)
        return 0;
    return h->height;
}

/* Updates the height of the given head. */
void updateHeight(AVL_Node *h) {
    int height_left = height(h->l);
    int height_right = height(h->r);
    h->height = height_left > height_right ? height_left + 1 : height_right + 1;
}

/* Left rotates the subtree rooted with h. */
AVL_Node *rotL(AVL_Node *h) {
    AVL_Node *x = h->r;
    h->r = x->l;
    x->l = h;
    updateHeight(h);
    updateHeight(x);
    return x;
}

/* Right rotates the subtree rooted with h. */
AVL_Node *rotR(AVL_Node *h) {
    AVL_Node *x = h->l;
    h->l = x->r;
    x->r = h;
    updateHeight(h);
    updateHeight(x);
    return x;
}

/* Left and right rotates the subtree rooted with h. */
AVL_Node *rotLR(AVL_Node *h) {
    if (!h)
        return h;
    h->l = rotL(h->l);
    return rotR(h);
}

/* Right and left rotates the subtree rooted with h. */
AVL_Node *rotRL(AVL_Node *h) {
    if (!h)
        return h;
    h->r = rotR(h->r);
    return rotL(h);
}

/* Gets the balance factor of the given head. */
int balance(AVL_Node *h) {
    if (!h)
        return 0;
    return height(h->l) - height(h->r);
}

/* Balances the AVL Tee if it is unbalanced. */
AVL_Node *balanceAVL(AVL_Node *h) {
    int balanceFactor;
    if (!h)
        return h;

    balanceFactor = balance(h);

    if (balanceFactor > 1) {
        if (balance(h->l) >= 0)
            h = rotR(h);
        else
            h = rotLR(h);
    }
    else if (balanceFactor < -1) {
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
AVL_Node *insertAVLPath(AVL_Node *h, char *path, char *value) {
    if (!h)
        return newAVL(path, value);

    else if (strcmp(path, h->path) == 0) {
        strcpy(h->value, value);
        return h;
    }

    if (strcmp(path, h->path) < 0)
        h->l = insertAVLPath(h->l, path, value);

    else if (strcmp(path, h->path) > 0)
        h->r = insertAVLPath(h->r, path, value);

    h = balanceAVL(h);

    return h;
}

/* Returns the maximum node in the avl tree, considering that it is organized by paths. */
AVL_Node *max(AVL_Node *h) {
    if (!h || !h->r) return h;
    else return max(h->r);
}

/* Removes the node where the given path is stored from the AVL Tree. */
AVL_Node *deleteAVLPath(AVL_Node *h, char *path) {
    if (!h) {
        printf(NOT_FOUND);
        return h;
    }
    else if (strcmp(path, h->path) < 0) h->l = deleteAVLPath(h->l, path);
    else if (strcmp(path, h->path) > 0) h->r = deleteAVLPath(h->r, path) ;
    else {
        if (h->l && h->r){
            AVL_Node *aux = max(h->l);
            {char *x, *y; x = h->path; h->path = aux->path; aux->path = x;
                        y = h->value; h->value = aux->value; aux->value = y;}
            h->l = deleteAVLPath(h->l, aux->path);
        }
        else {
            AVL_Node *aux = h;
            if (!h->l && !h->r) h = NULL;
            else if (!h->l) h = h->r;
            else h = h->l;
            free(aux->path); 
            free(aux->value); 
            free(aux); 
        }
    }
    h = balanceAVL(h);
    return h;
}

/* Removes all of the AVL Tree Nodes. */
AVL_Node *freeAVL(AVL_Node *h) {
    if (!h) return h;
    h->l = freeAVL(h->l);
    h->r = freeAVL(h->r);
    return deleteAVLPath(h, h->path);
}

/* Searches for the stored value in the AVL Tree, given the path. */
char *searchPath(AVL_Node *h, char *path) {
    if (!h) {
        printf(NOT_FOUND);
        return NULL;
    }

    if (strncmp(path, h->path, strlen(path)) == 0) {
        if (h->value && strcmp(path, h->path) == 0)
            return h->value;
        else{
            printf(NO_DATA);
            return NULL;
        }
    }

    if (strcmp(path, h->path) < 0) 
        return searchPath(h->l, path);
    else 
        return searchPath(h->r, path);
}

/* Prints in alphabetical order all AVL Tree components of the root. */
void listsInOrder(AVL_Node *h, char *aux[]) {
    static char prev[MAX]; 
    if (h) {
        listsInOrder(h->l, aux);
    
        breakPath(h->path, aux);
        if (strcmp(prev, aux[0]) != 0) {
            printf("%s\n", aux[0]);
            strcpy(prev, aux[0]);
        }

        listsInOrder(h->r, aux);
    }
}

/* Prints in alphabetical order all of the immediate components of the given path. */
int listsPathInOrder(AVL_Node *h, char *path, char *aux[]) {
    static int i, found = 0;
    static char prev[MAX]; 

    if (h) {
        listsPathInOrder(h->l, path, aux);

        if (strncmp(path, h->path, strlen(path)) == 0) {
            if (strcmp(path, h->path) == 0) {}
            else {
                breakPath(path, aux);
                i = countsSubPaths(aux);

                breakPath(h->path, aux);
                if (strcmp(prev, aux[i]) != 0) {
                    printf("%s\n", aux[i]);
                    strcpy(prev, aux[i]);
                    found++;
                }
            }
        }

        listsPathInOrder(h->r, path, aux);
    }
    return found;
}
