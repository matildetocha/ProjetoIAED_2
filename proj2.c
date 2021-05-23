/*
 * File: proj2.c
 * Author:  Matilde Tocha 99108
 * Description: Projecto 2 - IAED 2020/21.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "linked_list.h"
#include "avl_tree.h"
#include "handle_str.h"

/****** Command functions. ******/
/* Prints a list of available commands*/
void help()
{
    printf("%s%s%s%s%s%s%s%s", HELP_DES, QUIT_DES, SET_DES, PRINT_DES,
           FIND_DES, LIST_DES, SEARCH_DES, DELETE_DES);
}

AVL_Node *set(AVL_Node *avl_head, char *p[MAX], char form_path[MAX])
{
    char *p_aux[MAX];
    breakStrInput(p[1], p_aux, 1);
    path(p_aux[0], form_path);
    avl_head = insertAVL(avl_head, form_path, p_aux[1]);
    return avl_head;
}

void find(AVL_Node *avl_head, char *p, char form_path[MAX])
{
    char *value;
    path(p, form_path);
    value = searchPath(avl_head, form_path);
    if (!value) return;
    printf("%s\n", value);
}

void search(AVL_Node *avl_head, char *value)
{
    char *form_path;
    form_path = searchValue(avl_head, value);
    if (!form_path) return;
    printf("%s\n", form_path);
}

/* Makes the program run as commands are entered. */
int main()
{
    char str[MAX], form_path[MAX], *p[MAX];
    AVL_Node *avl_head = NULL;

    for (;;)
    {
        memset(str, 0, MAX - 1);
        fgets(str, MAX, stdin);

        memset(p, 0, MAX - 1);
        memset(form_path, 0, MAX - 1);

        breakStrInput(str, p, 1);

        if (strcmp(p[0], HELP) == 0)
            help();

        else if (strcmp(p[0], QUIT) == 0)
            exit(EXIT_SUCCESS); /* // ! nao esquecer de dar free de tudo no final */

        else if (strcmp(p[0], SET) == 0)
            avl_head = set(avl_head, p, form_path);

        else if (strcmp(p[0], PRINT) == 0)
            traversePreOrder(avl_head);

        else if (strcmp(p[0], FIND) == 0)
            find(avl_head, p[1], form_path);
        
        else if (strcmp(p[0], SEARCH) == 0)
            search(avl_head, p[1]);
    }
}
