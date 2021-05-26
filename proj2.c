/*
 * File: proj2.c
 * Author:  Matilde Tocha 99108
 * Description: Projecto 2 - IAED 2020/21.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "avl_tree.h"
#include "hash_table.h"
#include "handle_str.h"


/* Prints a list of available commands*/
void help() {
    printf("%s%s%s%s%s%s%s%s", HELP_DES, QUIT_DES, SET_DES, PRINT_DES,
           FIND_DES, LIST_DES, SEARCH_DES, DELETE_DES);
}

/* Adds or modifies the value to store in AVL Tree. */
AVL_Node *setAVL(AVL_Node *avl_head, char form_path[], char *value) {
    avl_head = insertAVLPath(avl_head, form_path, value);
    return avl_head;
}

/* Adds or modifies the value to store in Hash Table. */
Hash_Node **setHash(Hash_Node **hash_heads, char form_path[], char *value) {
    hash_heads = insertHash(hash_heads, form_path, value);
    return hash_heads;
}

/* Adds the father path to the Linked List, to maintain the insertion order. */
Hash_Node *setInsertion(Hash_Node **hash_heads, Hash_Node *insertion, char form_path[]) {
    char *aux[MAX];

    breakPath(form_path, aux);
    if (searchHash(hash_heads, aux[0]) == 0) insertion = insertBeginLL(insertion, aux[0], "nada");
    return insertion;
}

/* Prints all of the paths and values stored. */
void print(Hash_Node **hash_heads, Hash_Node *insertion) {
    Hash_Node *last;
    int i;

    if (!hash_heads) {puts("nulo"); return;}
    while (insertion) {
            last = insertion;
            insertion = insertion->next;
    }
    while (last) {
        i = hash(last->path, SIZE_HASH);
        printPaths(hash_heads[i]);
        last = last->prev;
    }
    return;
}

/* Prints the stored value of the given path. */
void find(AVL_Node *avl_head, char *p, char form_path[])
{
    char *value;
    path(p, form_path);
    value = searchPath(avl_head, form_path);
    if (!value) return;
    printf("%s\n", value);
}

/* Lists all of the immediate components of a sub-path. */
void list(AVL_Node *avl_head, char *p[], char form_path[]) {
    char *aux[MAX];
    int found;

    if (!p[1]) {
        listsInOrder(avl_head, aux);
        return;
    }
    else {
        path(p[1], form_path);
        found = listsPathInOrder(avl_head, form_path, aux);
        if (found == 0) printf(NOT_FOUND);
        return;
    }
}

/* Deletes all paths from a sub-path in AVL Tree. */
AVL_Node *deleteAVL(AVL_Node *avl_head, char *p[], char form_path[]) {
    if (!p[1]) {
        avl_head = freeAVL(avl_head);
        return avl_head;
    }
    else {
        path(p[1], form_path);
        avl_head = deleteAVLPath(avl_head, form_path);
        return avl_head;
    }
}

/* Deletes all paths from a sub-path in Hash Table. */
Hash_Node **deleteHash(Hash_Node **hash_heads, char *p[], char form_path[]) {
    if (!p[1]) {
        hash_heads = freeHash(hash_heads);
        return hash_heads;
    }
    else {
        path(p[1], form_path);
        hash_heads = deleteHashPath(hash_heads, form_path);
        return hash_heads;
    }
}

/* Makes the program run as commands are entered. */
int main() {
    char str[MAX], form_path[MAX], *p[MAX], *aux[MAX];
    AVL_Node *avlpath_head = NULL;
    Hash_Node **hash_heads = NULL, *insertion = NULL;

    hash_heads = hashInit(hash_heads, SIZE_HASH);

    for (;;) {
        memset(str, 0, MAX - 1);
        fgets(str, MAX, stdin);

        memset(p, 0, MAX - 1);
        memset(form_path, 0, MAX - 1);

        breakStrInput(str, p, 1);

        if (strcmp(p[0], HELP) == 0)
            help();

        else if (strcmp(p[0], QUIT) == 0) {
            freeAVL(avlpath_head);
            freeHash(hash_heads);
            freeInsertion(insertion);
            exit(EXIT_SUCCESS); 
        }

        else if (strcmp(p[0], SET) == 0) {
            breakStrInput(p[1], aux, 1);
            path(aux[0], form_path);

            avlpath_head = setAVL(avlpath_head, form_path, aux[1]);
            hash_heads = setHash(hash_heads, form_path, aux[1]);
            insertion = setInsertion(hash_heads, insertion, form_path);
        }

        else if (strcmp(p[0], PRINT) == 0) 
            print(hash_heads, insertion);
            
        else if (strcmp(p[0], FIND) == 0)
            find(avlpath_head, p[1], form_path);

        else if (strcmp(p[0], LIST) == 0)
            list(avlpath_head, p, form_path);
        
        else if (strcmp(p[0], SEARCH) == 0) {}

        else if (strcmp(p[0], DELETE) == 0) {
            avlpath_head = deleteAVL(avlpath_head, p, form_path);
            hash_heads = deleteHash(hash_heads, p, form_path);
        }
    }
}
