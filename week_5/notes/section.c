#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 5


typedef struct node {
    char *phrase;
    struct node *next;
} node;

char *get_string(char * n);

node *llinput(node *ptr, char *input);
node *llreverse(node *ptr);

void llprint(node *ptr);
void llunload(node *ptr);


int main(void) {
    node *list = NULL;

    for (int i = 0; i < SIZE; i++) {
        list = llinput(list, get_string("Enter a phrase: "));
    }

    list = llreverse(list);


    llprint(list);




    llunload(list);
    return 0;
}










node *llinput(node *ptr, char *input) {
    node *n = malloc(sizeof(node));
    if (n == NULL) return ptr;
    
    n->phrase = malloc(strlen(input) + 1);
    strcpy(n->phrase, input);
    n->next = NULL;

    n->next = ptr;
    ptr = n;
    return ptr;
}

node *llreverse(node *ptr) {
    node *curr = ptr;
    node *prev = NULL;

    while (curr != NULL) {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


void llunload(node *ptr) {
    while (ptr != 0) {
        node *tmp = ptr;
        ptr = ptr->next;
        free(tmp->phrase);
        free(tmp);
    }
}

void llprint(node *ptr) {
    printf("[");
    while (ptr != NULL) {
        printf("'%s'", ptr->phrase);
        if (ptr->next != NULL) printf(", ");
        ptr = ptr->next;
    }
    printf("]\n");
}


char *get_string(char * n) {
    #define MAX_SIZE 100
    char input[MAX_SIZE];

    printf("%s", n);
    fgets(input, MAX_SIZE, stdin);
    
    size_t length = strlen(input);
    if (length > 0 && input[length - 1] == '\n') {
        input[length - 1] = '\0';
    }

    char *x = malloc(strlen(input) + 1);
    if (x == NULL) return NULL;

    strcpy(x, input);
    return x;
}

