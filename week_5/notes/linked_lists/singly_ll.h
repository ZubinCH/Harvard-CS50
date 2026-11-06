#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <stddef.h>

// data structures
typedef struct node {
    char *word;
    struct node *next;
} node;

// function prototypes
void insert(char *word, node *point);
node *delete(node *point);
node *llreverse(node *head);
node *llreverse_loop(node *curr, node *prev);
void llprint(node *point);
void llfree(node *point);







#endif