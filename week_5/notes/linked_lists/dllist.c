#include <stdio.h>
#include <stdlib.h>


#define SIZE 5

typedef struct node {
    int number;
    struct node *prev;
    struct node *next;
} node;



int main(void) {



}


node *select(int value, node *ptr) {
    while (ptr != NULL) {
        if (ptr->number == value) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return NULL;
}