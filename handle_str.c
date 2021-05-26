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
int breakStrInput(char str[], char *v[], int p)
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
void breakPath(char str[], char *p[])
{
    char *token, tmp_str[MAX];
    int i = 0;

    strcpy(tmp_str, str);
    token = strtok(tmp_str, SLASH_NEWLINE);

    while (token != NULL)
    {
        p[i++] = token;
        token = strtok(NULL, SLASH_NEWLINE);
    }
    p[i] = NULL;
}

/* Formats a path with a slash at the beggining of its components/subpaths. */
void pathFormat(char *p[], char path[])
{
    int i;
    for (i = 0; p[i] != NULL; i++)
    {
        strcat(path, SLASH);
        strcat(path, p[i]);
    }
}

/* Formats a given path, according to its components/subpaths. */
void path(char *p, char form_path[])
{
    char *p_aux[MAX];
    breakPath(p, p_aux);
    pathFormat(p_aux, form_path);
}

/* Counts the number of components/ subpaths of a path. */
int countsSubPaths(char *p[]) {
    unsigned i, count = 0;

    for (i = 0; p[i] != NULL; i++) {
        count++;
    }
    return count;
}