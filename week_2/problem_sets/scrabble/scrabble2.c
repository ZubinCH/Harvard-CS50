#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(char* word);
char *get_string(char *text);

int main(void)
{
    char* word1 = get_string("Player 1: ");
    char* word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(char* word)
{
    int score = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}

char *get_string(char *text) {
    #define MAX_SIZE 100
    char input[MAX_SIZE];

    printf("%s", text);
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    char *trunc = malloc(strlen(input) + 1);
    if (trunc == NULL) return NULL;

    return strcpy(trunc, input);
}