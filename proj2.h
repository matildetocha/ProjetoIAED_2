/*
 * File: defines.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of defines for Projeto 2 - IAED 2020/21.
*/

#ifndef PROJ2_H
#define PROJ2_H

#include "avl_tree.h"

/* Maximum number of characters for instructions that the system supports. */
#define MAX 65536

/* Commands */
#define HELP "help"
#define QUIT "quit"
#define SET "set"
#define PRINT "print"
#define FIND "find"
#define LIST "list"
#define SEARCH "search"
#define DELETE "delete"

/* Command errors */
#define NOT_FOUND "not found\n"
#define NO_DATA "no data\n"

/* Command descriptions*/
#define HELP_DES "help: Imprime os comandos disponíveis.\n"
#define QUIT_DES "quit: Termina o programa.\n"
#define SET_DES "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_DES "print: Imprime todos os caminhos e valores.\n"
#define FIND_DES "find: Imprime o valor armazenado.\n"
#define LIST_DES "list: Lista todos os componentes imediatos de um sub-caminho.\n"
#define SEARCH_DES "search: Procura o caminho dado um valor.\n"
#define DELETE_DES "delete: Apaga um caminho e todos os subcaminhos.\n"

#define ORG_PATH 'p'
#define ORG_VALUE 'v'

/* Delimiters */
#define NEWLINE "\n"
#define SPACE " "
#define SPACE_NEWLINE " \n"
#define SLASH "/"
#define SLASH_NEWLINE "/\n"

void help();
AVL_Node *set(AVL_Node *avl_head, char *p[], char form_path[], char org);
void find(AVL_Node *avl_head, char *p, char form_path[]);
void list(AVL_Node *avl_head, char *p[], char form_path[]);
void search(AVL_Node *avl_head, char *value);
AVL_Node *delete(AVL_Node *avl_head, char *p[], char form_path[]);

#endif