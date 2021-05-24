/*
 * File: handle_str.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of functions to handle string input.
*/

#ifndef HANDLE_STR_H
#define HANDLE_STR_H

int breakStrInput(char str[], char *v[], int p);
void breakPath(char str[], char *p[]);
void pathFormat(char *p[], char path[]);
void path(char *p, char form_path[]);
int countsSubPaths(char *p[]);

#endif