#include "../cs50/src/cs50.h"
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

char *candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, char *name, int *ranks);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool creates_cycle(int winner, int loser);
void print_winner(void);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs and set all preferences to zero
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
            preferences[i][j] = 0;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char *name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, char *name, int *ranks)
{
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(name, candidates[i]) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        for (int j = i + 1; j < candidate_count; j++) {
            if (i < j) {
                preferences[ranks[i]][ranks[j]]++;
            }
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) {
        for (int j = i + 1; j < candidate_count; j++) {
            if (preferences[i][j] > preferences[j][i]) {
                pairs[pair_count] = (pair) {i, j};
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i]) {
                pairs[pair_count] = (pair) {j, i};
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++) {
        int swapped = 0;

        for (int k = 0; k < pair_count - 1 - i; k++) {
            if (
                preferences[pairs[k].winner][pairs[k].loser] - preferences[pairs[k].loser][pairs[k].winner] 
                < 
                preferences[pairs[k + 1].winner][pairs[k + 1].loser] - preferences[pairs[k + 1].loser][pairs[k + 1].winner]
            ) 
                {
                pair tmp = pairs[k + 1];
                pairs[k + 1] = pairs[k];
                pairs[k] = tmp;
                swapped = 1;
            }
        }
        
        if (!swapped) break;
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++) {
        locked[pairs[i].winner][pairs[i].loser] = true;

        if (creates_cycle(pairs[i].winner, pairs[i].loser)) {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }

    return;
}

// Print the winner of the election
void print_winner(void)
{

    /*

    Pseudocode:

        Loop through the columns of the adjacency matrix
            Loop through the rows of the adjacency matrix
                IF the sum of the column is equal to zero,
                    Store the column number of the matrix

        Convert candidate number into winner

    */

    int condorcet_winner;


    for (int i = 0; i < candidate_count; i++) {
        int sum = 0;

        for (int j = 0; j < candidate_count; j++) {
            if (locked[j][i]) sum++;
        }

        if (!sum) condorcet_winner = i;
    }

    printf("%s\n", candidates[condorcet_winner]);

    return;
}


bool creates_cycle(int winner, int loser) {

    if (winner == loser) return true;

    for (int i = 0; i < candidate_count; i++) {
        if (locked[loser][i]) 
            if (creates_cycle(winner, i)) 
                return true;
    }

    return false;
}
