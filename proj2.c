/*
 * File:  proj2.c
 * Author:  Matilde Tocha 99108
 * Description: Projecto 2 - IAED 2020/21.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"


/* Breaks the given string into tokens, considering that it does not receive any 
additional instructions */
void BreakStr_Opt(char str[MAX], const char delim[], char *p[MAX])
{
    char *token;
    int i = 0;

    token = strtok(str, SPACE_NEWLINE);

    while (token != NULL)
    {
        p[i++] = token;
        token = strtok(NULL, delim);
    }
    p[i] = NULL;
}

void Help()
{
    printf(HELP_DES); printf(QUIT_DES); printf(SET_DES); printf(PRINT_DES);
    printf(FIND_DES); printf(LIST_DES); printf(SEARCH_DES); printf(DELETE_DES);
}

/* Makes the program run as commands are entered. */
int main()
{
    char str[MAX], *p[MAX];
    int i = 0;

    for (;;)
    {
        fgets(str, MAX, stdin);
        BreakStr_Opt(str, NEWLINE, p);

        if (strcmp(p[i], QUIT) == 0)
            exit(EXIT_SUCCESS);
        
        else if(strcmp(p[i], HELP) == 0)
            Help();
            
    }
} 
