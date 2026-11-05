#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 5

typedef struct node {
    char *name;
    struct node *next;
} node;




int main(void) {
    node *table[26];

    


}


unsigned int hash (const char *name) {
    return toupper(name[0]) - 'A';
}