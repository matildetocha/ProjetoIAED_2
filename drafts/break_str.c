#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Breaks the given string into tokens, considering that it's required that it receives
instructions. Used for these commands: 't', 'n', 'm', 'd'. */
int BreakStr_Input(char str[1000], char *v[1000], int p)
{
    char *token;
    int i = 0, n = 0;

    token = strtok(str, " \n");

    while (n < p)
    {
        v[i++] = token;
        if (n < p - 1)
            token = strtok(NULL, " ");
        else
            token = strtok(NULL, "\n");
        n++;
    }

    while (token != NULL)
    {
        v[i++] = token;
        token = strtok(NULL, "\n");
    }
    v[i] = NULL;
    return i;
}

void BreakStr_InNodes(char str[1000], const char delim[], char *p[1000])
{
    char *token;
    int i = 0;

    token = strtok(str, delim);

    while (token != NULL)
    {
        p[i++] = token;
        token = strtok(NULL, delim);
    }
    p[i] = NULL;
}

int main()
{
    char str[1000] = "set usr/bin/local//pics/ bsdoia cnsdao\n", *v[1000], *p2[1000], *p, *z;
    int i, j = 0;

    BreakStr_Input(str, v, 2);

    printf("%s\n", v[1]);

    BreakStr_InNodes(v[1], "/\n", p2);
    printf("%s\n", p2[0]);
    printf("%s\n", p2[1]);
    printf("%s\n", p2[2]);
    printf("%s\n", p2[3]);

    return (0);
}

    static int found = 0;

    if (h) {
        pathInOrder(h->l, path, aux);
        if (strncmp(path, h->path, strlen(path)) == 0) {
            found++;
            breakPath(h->path, aux);
            puts(aux[1]);
        }
        pathInOrder(h->r, path, aux);
    }
    return found;