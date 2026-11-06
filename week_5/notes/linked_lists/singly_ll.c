#include "singly_ll.h"
#include <stdlib.h>
#include <stdio.h>


void insert(char *word, node *head) {
    if (head == NULL) {
        printf("Cannot insert into NULL linked list.\n");
        return;
    }
    node *copy_head = malloc(sizeof(node));
    if (!copy_head) {
        printf("Memory allocation failed.\n");
        return;
    }

    copy_head->word = head->word;
    copy_head->next = head->next;

    head->word = word;
    head->next = copy_head;
}


node *delete(node *point) {
    if (!point) {
        printf("NULL linked list.\n");
        return NULL;
    }

    node *tmp = point;
    point = point->next;
    free(tmp);
    return point;
}

// Handles the head of the linked_list
node *llreverse(node *head) {
    if (!head) {
        printf("NULL linked list.\n");
        return NULL;
    }

    node *tmp = malloc(sizeof(node));
    if (!tmp) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    tmp->word = head->word;
    tmp->next = NULL;
    node *new_head = llreverse_loop(head->next, tmp);
    free(head);
    return new_head;
}

// Recursive approach to reversing a linked list
node *llreverse_loop(node *curr, node *prev) {
    if (!curr || !prev) {
        printf("NULL linked list");
        return NULL;
    }

    if (curr->next == NULL) {
        curr->next = prev;
        return curr;
    }
    

    node *next = curr->next;
    curr->next = prev;
    return llreverse_loop(next, curr);
}


/*
int search(char *word, node *point) {


}


char *select(char* word, node *point) {


}
*/

void llprint(node *point) {
    printf("[");

    while (point != NULL) {
        printf("%s", point->word);
        if (point->next != NULL) printf(", ");
        point = point->next;
    }
    
    printf("]\n");

}

void llfree(node *point) {
    while (point != NULL) {;
        node *tmp = point;
        point = point->next;
        free(tmp);
    }
}