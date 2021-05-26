/*
 * File: handle_str.h
 * Author:  Matilde Tocha 99108
 * Description: Declaration of the functions used in handel_str.c.
*/

#ifndef HANDLE_STR_H
#define HANDLE_STR_H

int breakStrInput(char str[], char *v[], int p);
void breakPath(char str[], char *p[]);
void pathFormat(char *p[], char path[]);
void path(char *p, char form_path[]);
int countsSubPaths(char *p[]);

#endif