/*
 * File: linked_list.c
 * Author:  Matilde Tocha 99108
 * Description: Functions to insert a node in linked list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "linked_list.h"

/* Allocates a new node with the given name and NULL next pointer. */
LL_Node *newLL(char *name)
{
    LL_Node *x = (LL_Node*) malloc(sizeof(LL_Node));
    x->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(x->name, name);
    x->next = NULL;
    return x;
}

/* Inserts a new node at the end of the list, given a reference to the head
of the list and the name to be inserted. */
LL_Node *insertEndLL(LL_Node *head, char *name)
{
    LL_Node *x;
    if (head == NULL)
        return newLL(name);
    for (x = head; x->next != NULL; x = x->next) {}
    x->next = newLL(name);
    return head;
}

LL_Node *searchLL(LL_Node *head, char *text) {
    LL_Node *tmp_head;
    for(tmp_head = head; tmp_head != NULL; tmp_head = tmp_head->next)
    if(strcmp(t->text, text) == 0)
        return t;
    return NULL;
}

/* Prints contents of linked list starting from the given node */
void printList(LL_Node *head)
{
    LL_Node *temporary = head;

    while (temporary != NULL)
    {
        printf("%s%s", temporary->name, SLASH);
        temporary = temporary->next;
    }
    printf(NEWLINE);
}

LL_Node *createPath(char *p[MAX])
{
    int i = 0;
    LL_Node *tmp_head = NULL;

    while (p[i] != NULL)
    {
        tmp_head = insertEndLL(tmp_head, p[i]);
        i++;
    }
    return tmp_head;
}

void FREEnode(LL_Node *head) 
{
    free(head->name);
    free(head);
}


void searchPathLL(Hash_Node *head, char *value)
{
    Hash_Node *t;
    for(t = head; t != NULL; t = t->prev) {
        
        if(strcmp(t->value, value) == 0)
            printf("%s\n", t->path);
    }
    return ;
}

void searchHash(Hash_Node **hash_heads, char *value) {
    int i = hash(path, SIZE_HASH);
    searchValueLL(hash_heads[i], value);
    return;
}