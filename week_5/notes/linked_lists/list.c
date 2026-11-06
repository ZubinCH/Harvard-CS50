#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

typedef struct node {
    int number;
    struct node *next;
} node;


void unload(node *ptr);
void llprint(node *ptr);

node *llreverse(node *ptr);

int main(void) {
    node *list = NULL;

    for (int i = 0; i < SIZE; i++) {
        node *n = malloc(sizeof(node));
        if (n == NULL) {
            unload(n);
            return 1;
        }

        printf("Number: ");
        scanf(" %i", &n->number);
        n->next = NULL;

        n->next = list;
        list = n;
        
    }

    list = llreverse(list);
    llprint(list);

    unload(list);
    return 0;
}


void unload(node *ptr) {
    while (ptr != NULL) {
        node *tmp = ptr;
        ptr = ptr->next;
        free(tmp);
    }
}

void llprint(node *ptr) {
    printf("[");
    while (ptr != NULL) {
        printf("%i", ptr->number);
        if (ptr->next != NULL) printf(", ");
        ptr = ptr->next;
    }
    printf("]\n");
}

node *llreverse(node *ptr) {
    node *prev = NULL;
    node *curr = ptr;

    while (curr != NULL) {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
