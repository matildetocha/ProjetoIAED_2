/*
 * File: linked_list.h
 * Author:  Matilde Tocha 99108
 * Description: Header file of Linked List Node structure.
*/

#ifndef LL_H
#define LL_H

typedef struct node
{
    char *name;
    struct node *next;
} LL_Node;

LL_Node* newLL(char *name);
LL_Node* insertEndLL(LL_Node *head, char *name);
void printList(LL_Node *head);
LL_Node *createPath(char *p[]);
void FREEnode(LL_Node *head) ;

#endif