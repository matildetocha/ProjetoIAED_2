/*
 * File: handle_str.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of functions to handle string input.
*/

#ifndef HANDLE_STR_H
#define HANDLE_STR_H

#include "proj2.h"

int breakStrInput(char str[MAX], char *v[MAX], int p);
void breakPath(char str[MAX], char *p[MAX]);
void pathFormat(char *p[MAX], char path[MAX]);
void path(char *p, char form_path[MAX]);

#endif