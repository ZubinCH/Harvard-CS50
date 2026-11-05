#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 9

// Candidates have name and vote count
typedef struct
{
    char *name;
    int votes;
} candidate;

int get_int(char *phrase);
char *get_string(char *text);
void print_arr(candidate *arr, int len);

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(char *name);
void print_winner(void);


int main(int argc, char *argv[]) {
    // Check for valid arguments
    if (argc < 2) {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        char *name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
            i--;
        }
        free(name);
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
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
    int *winners;

    // Bubble sort
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < candidate_count - 1; i++) {
            if (candidates[i].votes > candidates[i + 1].votes) {
                candidate tmp = candidates[i + 1];
                candidates[i + 1] = candidates[i];
                candidates[i] = tmp;
                swapped = 1;
            }
        }
    } while (swapped);

    // Select winner
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[candidate_count - 1 - i].votes == candidates[candidate_count - 1].votes) {
            printf("%s\n", candidates[candidate_count - 1 - i].name);
        }
    }
}


int get_int(char *phrase) 
{
    int placeholder;

    printf("%s", phrase);
    scanf(" %i", &placeholder);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

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


void print_arr(candidate *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("[%s, votes: %i]\n", arr[i].name, arr[i].votes);
    }
}