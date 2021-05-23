/*
 * File: handle_str.c
 * Author:  Matilde Tocha 99108
 * Description: Functions to handle string inputs.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"

/* Breaks the given input into tokens by spaces with newline. */
int breakStrInput(char str[MAX], char *v[MAX], int p)
{
    char *token;
    int i = 0, n = 0;

    token = strtok(str, SPACE_NEWLINE);

    while (n < p)
    {
        v[i++] = token;
        if (n < p - 1)
            token = strtok(NULL, SPACE);
        else
            token = strtok(NULL, NEWLINE);
        n++;
    }

    while (token != NULL)
    {
        v[i++] = token;
        token = strtok(NULL, SPACE_NEWLINE);
    }
    v[i] = NULL;
    return i;
}

/* Breaks the given path into tokens by slashes with newline. */
void breakPath(char str[MAX], char *p[MAX])
{
    char *token;
    int i = 0;

    token = strtok(str, SLASH_NEWLINE);

    while (token != NULL)
    {
        p[i++] = token;
        token = strtok(NULL, SLASH_NEWLINE);
    }
    p[i] = NULL;
}

/* Formats a path. */
void pathFormat(char *p[MAX], char path[MAX])
{
    int i;
    for (i = 0; p[i] != NULL; i++)
    {
        strcat(path, p[i]);
        strcat(path, SLASH);
    }
}

void path(char *p, char form_path[MAX])
{
    char *p_aux[MAX];
    breakPath(p, p_aux);
    pathFormat(p_aux, form_path);
}