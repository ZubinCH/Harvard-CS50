#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *right;
    struct node *left;
} node;


int main(void) {
    node *list = NULL;

    for (int i = 0; i < 4; i++) {
        node *n = malloc(sizeof(node));
        if (n = NULL) return 1;

        printf("Number: ");
        scanf(" %i", &n->number);
        n->right = NULL;
        n->left = NULL;

        
    }


}