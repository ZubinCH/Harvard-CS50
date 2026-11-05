#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5


typedef struct node {
    int number;
    struct node *next;
} node;


char *get_string(char * n);

int hash(char *string);



int main(void) {

    char *word = get_string("Word: ");
    printf("%s\n", word);

    printf("Hash value: %i\n", hash(word));



    free(word);
    return 0;
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

int hash(char *string) {
    if (string == NULL || strlen(string) == 0) return -2;

    
    char c = string[0];
    if (isalpha(c)) {
        int n = toupper(c) - 'A';
        return n;
    }
    return -1;
}