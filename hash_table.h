/*
 * File: hash_table.h
 * Author:  Matilde Tocha 99108
 * Description: Declaration of the functions and struct Hash_Node.
*/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

/* Size of Hash Table. */
#define SIZE_HASH 3001

typedef struct hashnode {
    char *path, *value;
    struct hashnode *prev, *next;
} Hash_Node;


Hash_Node **hashInit(Hash_Node **hash_heads, int m);
Hash_Node *newHash(char *path, char *value) ;
int hash(char *path, int M);
Hash_Node *insertBeginLL(Hash_Node *head, char *path, char *value);
Hash_Node **insertHash(Hash_Node **hash_heads, char *path, char *value) ;
void freeNode(Hash_Node *t) ;
Hash_Node *deletePath(Hash_Node *head, char *path);
Hash_Node **deleteHashPath(Hash_Node **hash_heads, char *path);
Hash_Node **freeHash(Hash_Node **hash_heads);
Hash_Node *freeInsertion(Hash_Node *insertion);
int searchHash(Hash_Node **hash_heads, char *path);
void printPaths(Hash_Node *head);

#endif