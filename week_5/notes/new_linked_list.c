#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct node {
    int number;
    struct node *next;
} node;


void print_list (node *ptr);
void free_list(node *a);
int list_size(node *ptr);

node *reverse_list (node *x);
node *prepend_list(node *ptr, int number);
node *append_list(node *ptr, int number);

void bubble_sort(node *ptr);

int main(void) {
    node *list = NULL;

    for (int i = 0; i < SIZE; i++) {
        node *n = malloc(sizeof(node));
        if (n == NULL) return 1;

        printf("Number: ");
        scanf(" %i", &n->number);
        n->next = NULL;

        n->next = list;
        list = n;
    }

    list = reverse_list(list);
    print_list (list);


    bubble_sort(list);

    list = prepend_list(list, 0);
    list = append_list(list, 11);
    print_list(list);
    int x = list_size(list);

    printf("List size: %i\n", x);


    free_list(list);
    return 0;
}











node *reverse_list (node *head) {
   node *prev = NULL;
   node *curr = head;

   while (curr != NULL) {
    node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
   }

   return prev;
}

node *prepend_list(node *ptr, int number) {
    node *new = malloc(sizeof(node));
    if (new == NULL) return ptr;
    new->number = number;
    new->next = ptr;
    ptr = new;
    return ptr;
}


node *append_list(node *ptr, int number) {
    node *new = malloc(sizeof(node));
    if (new == NULL) return ptr;

    new->number = number;
    new->next = NULL;

    if (ptr == NULL) return new;

    node *end = ptr;
    while (end->next != NULL) end = end->next;
    
    end->next = new;
    return ptr;
}

void print_list (node *ptr) {
    printf("[");
    while (ptr != NULL) {
        printf("%i", ptr->number);
        if (ptr->next !=  NULL) printf(", ");
        ptr = ptr->next;
    }
    printf("]\n");

}

void free_list(node *a) {
    while (a != NULL) {
        node *tmp = a;
        a = a->next;
        free(tmp);
    }
}

int list_size(node *ptr) {
    int i = 0;
    while (ptr != NULL) {
        i++;
        ptr=ptr->next;
    }
    return i;
}


void bubble_sort (node *ptr) {
    if (ptr == NULL) return;

    int swaps;
    node *end = NULL;

    do {
        swaps = 0;
        node *tmp = ptr;

        while (tmp->next != end) {
            if (tmp->number > tmp->next->number) {
                int temp = tmp->number;
                tmp-> number = tmp->next->number;
                tmp->next->number = temp;
                swaps = 1;
            }
            tmp = tmp->next;

        }

        end = tmp;
    } while (swaps != 0);

}

