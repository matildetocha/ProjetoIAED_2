/*
 * File: hash_table.c
 * Author:  Matilde Tocha 99108
 * Description: Functions to create, insert, search and delete a node
 * in an Hash Table.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proj2.h"
#include "hash_table.h"
#include "handle_str.h"

/* Creates and returns an array of pointers to the struct Hash_Node with the
size given in the input.*/
Hash_Node **hashInit(Hash_Node **hash_heads, int m) {
    int i;
    hash_heads = (Hash_Node**) malloc(sizeof(Hash_Node) * m);
    if (!hash_heads) puts(NO_MEMORY);
    for (i = 0; i < m; i++)
        hash_heads[i] = NULL;
    return hash_heads;
}

/* Allocates a new node with the given name, value and NULL next pointer for
the Hash Table. */
Hash_Node *newHash(char *path, char *value) {
    Hash_Node *x = (Hash_Node*) malloc(sizeof(Hash_Node));
    if (!x) puts(NO_MEMORY);
    x->path = (char*) malloc(sizeof(char) * (strlen(path) + 1));
    if (!x->path) puts(NO_MEMORY);
    x->value = (char*) malloc(sizeof(char) * (strlen(value) + 1));
    if (!x->value) puts(NO_MEMORY);

    strcpy(x->path, path);
    strcpy(x->value, value);
    return x;
}

/* Calculates the position of the given path for the Hash Table */
int hash(char *path, int m) {
    int h, a = 31415, b = 27183;
    for (h = 0; *path != '\0'; path++, a = a * b % (m - 1))
    h = (a * h + *path) % m;
    return h;
}

/* Inserts a new node at the beginning of the Linked List, given a 
reference to the head of the list and the name to be inserted. */ 
Hash_Node *insertBeginLL(Hash_Node *head, char *path, char *value) {
    Hash_Node *x = newHash(path, value);
    x->next = head;
    x->prev = NULL;

    if (head) head->prev = x;
    head = x;

    return head;
}

/* Inserts a new node in the Hash Table, at the beginning of the Linked List,
at the index calculated by the function hash. */ 
Hash_Node **insertHash(Hash_Node **hash_heads, char *path, char *value) {
    char *aux[MAX];
    int i;
    breakPath(path, aux);

    i = hash(aux[0], SIZE_HASH);
    hash_heads[i] = insertBeginLL(hash_heads[i], path, value);
    return hash_heads;
}

/* Removes a node from a Linked List. */
Hash_Node *deletePath(Hash_Node *head, char *path) {
    Hash_Node *t = head, *prev = NULL;
    for ( ; t && strcmp(t->path, path) != 0; prev = t, t = t->next) {}
    if (t) {
        if (prev) prev->next = t->next;
        else head = t->next;
        free(t->path);
        free(t->value);
        free(t);
    }
    return head;
}

/* Return the pointer of hash heads, after removing a given path from the Hash Table. */
Hash_Node **deleteHashPath(Hash_Node **hash_heads, char *path) {
    char *aux[MAX];
    int i;
    breakPath(path, aux);

    i = hash(aux[0], SIZE_HASH);
    hash_heads[i] = deletePath(hash_heads[i], path);
    return hash_heads;
}

/* Removes all nodes from the Hash Table. */
Hash_Node **freeHash(Hash_Node **hash_heads) { 
    int i;
    for (i = 0; i < SIZE_HASH; i++) {
        while (hash_heads[i]) {
        Hash_Node* temp_head = hash_heads[i]->next;
        free(hash_heads[i]->path);
        free(hash_heads[i]->value);
        free(hash_heads[i]);
        hash_heads[i] = temp_head;
        }
    }
    free(hash_heads); 
    return hash_heads;
}

/* Removes all nodes from the Linked List. */
Hash_Node *freeInsertion(Hash_Node *insertion) {
    while (insertion) {
        insertion = deletePath(insertion, insertion->path);
    }
    return insertion;
}

/* Searches for a given father path in the Hash Table and return 1, if the Linked List 
at that index, already has more than one node. */
int searchHash(Hash_Node **hash_heads, char *path) {
    int i = hash(path, SIZE_HASH);
    if (hash_heads[i]->next) return 1;
    else return 0;
}

/* Prints all paths inr reverse order from the Linked List in an Hash Table. */
void printPaths(Hash_Node *head) {
    Hash_Node *last;

    while (head) {
        last = head;
        head = head->next;
    }
    while (last) {
        printf("%s %s\n", last->path, last->value);
        last = last->prev;
    }
}
