/*
 * File: defines.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of defines for Projeto 2 - IAED 2020/21.
*/

#ifndef PROJ2_H
#define PROJ2_H

#include "linked_list.h"
#include "avl_tree.h"

/* Maximum number of characters for instructions that the system supports. */
#define MAX 65536

/* Commands */
#define QUIT "quit"
#define HELP "help"
#define SET "set"
#define PRINT "print"
#define FIND "find"
#define SEARCH "search"

/* Command errors */
#define FIND_ERROR1 "not found\n"
#define FIND_ERROR2 "no data\n"

/* Command descriptions*/
#define HELP_DES "help: Imprime os comandos disponíveis.\n"
#define QUIT_DES "quit: Termina o programa.\n"
#define SET_DES "set: Adiciona ou modifica o valor a armazenar.\n"
#define PRINT_DES "print: Imprime todos os caminhos e valores.\n"
#define FIND_DES "find: Imprime o valor armazenado.\n"
#define LIST_DES "list: Lista todos os componentes imediatos de um sub-caminho.\n"
#define SEARCH_DES "search: Procura o caminho dado um valor.\n"
#define DELETE_DES "delete: Apaga um caminho e todos os subcaminhos.\n"

/* Delimiters */
#define NEWLINE "\n"
#define SPACE " "
#define SPACE_NEWLINE " \n"
#define SLASH "/"
#define SLASH_NEWLINE "/\n"

void help();
AVL_Node *set(AVL_Node *avl_head, char *p[MAX], char form_path[MAX]);
void find(AVL_Node *avl_head, char *p, char form_path[MAX]);
void search(AVL_Node *avl_head, char *value);

#endif