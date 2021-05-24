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
#include "handle_str.h"

/* Prints a list of available commands*/
void help() {
    printf("%s%s%s%s%s%s%s%s", HELP_DES, QUIT_DES, SET_DES, PRINT_DES,
           FIND_DES, LIST_DES, SEARCH_DES, DELETE_DES);
}

/* Adds or modifies the value to store. */
AVL_Node *set(AVL_Node *avl_head, char *p[], char form_path[], char org) {
    char *p_aux[MAX];
    
    memset(form_path, 0, MAX - 1);
    breakStrInput(p[1], p_aux, 1);
    path(p_aux[0], form_path);

    switch (org) {
        case ORG_PATH:
            avl_head = insertAVLPath(avl_head, form_path, p_aux[1]);
            break;
        
        case ORG_VALUE:
            avl_head = insertAVLValue(avl_head, form_path, p_aux[1]);
            break;
    }
    return avl_head;
}

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

/* Searches for the path, given a value. */
void search(AVL_Node *avl_head, char *value) {
    char *form_path;
    form_path = searchValue(avl_head, value);
    if (!form_path) return;
    printf("%s\n", form_path);
} 

/* Deletes all paths from a sub-path. */
AVL_Node *delete(AVL_Node *avl_head, char *p[], char form_path[]) {
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

/* Makes the program run as commands are entered. */
int main() {
    char str[MAX], form_path[MAX], *p[MAX];
    AVL_Node *avlpath_head = NULL;

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
            exit(EXIT_SUCCESS); 
        }

        else if (strcmp(p[0], SET) == 0) {
            avlpath_head = set(avlpath_head, p, form_path, ORG_PATH);
            /* avlvalue_head = set(avlvalue_head, p, form_path, ORG_PATH) */;
        }
        else if (strcmp(p[0], PRINT) == 0)
            exit(EXIT_SUCCESS);
        else if (strcmp(p[0], FIND) == 0)
            find(avlpath_head, p[1], form_path);

        else if (strcmp(p[0], LIST) == 0)
            list(avlpath_head, p, form_path);
        
        else if (strcmp(p[0], SEARCH) == 0)
            exit(EXIT_SUCCESS);
        else if (strcmp(p[0], DELETE) == 0)
            avlpath_head = delete(avlpath_head, p, form_path);
    }
}
