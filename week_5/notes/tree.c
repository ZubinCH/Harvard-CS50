#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

bool search(node *tree, int number);

typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;

int main(void) {
    node *tr = NULL;


}


bool search(node *tree, int number) {

    if (tree == NULL) return false;

    else if (number < tree->number) return search(tree->left, number);

    else if (number > tree->number) return search(tree->right, number);

    else {
        return true;
    }
}

void unload(node *ptr) {
    while (ptr->left != NULL) {
        
    }


}
    