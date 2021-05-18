#ifndef PROJ2_H
#define PROJ2_H

/* Maximum number of characters for instructions that the system supports. */
#define MAX 65535

/* Commands */
#define QUIT "quit"
#define HELP "help"

/* Commands descriptions*/
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
#define SPACE_NEWLINE " \n"

#endif