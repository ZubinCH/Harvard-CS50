#include "../singly_ll.h"
#include <stdlib.h>
#include <stdio.h>


int main (void) {
    node *list = malloc(sizeof(node));
    list->next = NULL;

    char *A = "Person A";
    list->word = A;

    char *B = "Person B";
    insert(B, list);
    
    char *C = "Person C";
    insert(C, list);

    char *D = "Person D";
    insert(D, list);

    char *E = "Person E";
    insert(E, list);

    char *F = "Person F";
    insert(F, list);

    char *G = "Person G";
    insert(G, list);

    char *H = "Person H";
    insert(H, list);

    llprint(list);
    printf("\n");

    node *reversed_list = llreverse(list);
    llprint(reversed_list);

    insert("Person Z", reversed_list);


    node *new_reversed_list = llreverse(reversed_list);
    llprint(new_reversed_list);


    new_reversed_list = delete(new_reversed_list);
    llprint(new_reversed_list);

    llfree(list);


    return 0;
}

