#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

typedef struct candidate {
    char *name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

int get_int(char *phrase);
char *get_string(char *text);

bool vote(char *name);
void print_winner(void);











int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Invalid argument. Correct usage: ./file [candidate 1] [candidate 2] [...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Max number of candidates is %i.\n", MAX);
        return 1;
    }

    for (int i = 0; i < candidate_count; i++) {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");


    for (int i = 0; i < voter_count; i++) {
        char *name = get_string("Vote: ");

        if (!vote(name)) {
            printf("Invalid vote\n");
            i--;
        }
    }


    print_winner();
    return 0;
}













bool vote(char *name) {
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes++;
            return true;
        }
    }


    return false;
}


void print_winner(void) {
    int winner = 0;
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }
    printf("%s\n", candidates[winner].name);

}


int get_int(char *phrase) 
{
    int placeholder;

    printf("%s", phrase);
    scanf(" %i", &placeholder);

    return placeholder;
}


char *get_string(char *text) {
    #define MAX_SIZE 30
    char input[MAX_SIZE];

    printf("%s", text);
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    char *trunc = malloc(strlen(input) + 1);
    if (trunc == NULL) return NULL;

    return strcpy(trunc, input);
}
