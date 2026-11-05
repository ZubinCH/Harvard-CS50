#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_string(char *text);
int hash(char letter);




int main(void) {
    char* word1 = get_string("Player 1: ");
    int sum1 = 0;
    for (int i = 0, n = strlen(word1); i < n; i++) {
        word1[i] = (char)toupper((unsigned char)word1[i]);
        sum1 += hash(word1[i]);
    }


    char* word2 = get_string("Player 2: ");
    int sum2 = 0;
    for (int i = 0, n = strlen(word2); i < n; i++) {
        word2[i] = (char)toupper((unsigned char)word2[i]);
        sum2 += hash(word2[i]);
    }

    if (sum1 > sum2) printf("Player 1 wins!\n");
    if (sum1 < sum2) printf("Player 2 wins!\n");
    if (sum1 == sum2) printf("Tie!\n");

    



    free(word1);
    free(word2);
    return 0;
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

int hash(char letter) {
    if (letter == 'A' || letter == 'E' || letter == 'I' || letter == 'L' || letter == 'N' || letter == 'O' || letter == 'R' || letter == 'S' || letter == 'T' || letter == 'U') return 1;
    else if (letter == 'D' || letter == 'G') return 2;
    else if (letter == 'B' || letter == 'C' || letter == 'M' || letter == 'P') return 3;
    else if (letter == 'F' || letter == 'H' || letter == 'V' || letter == 'W' || letter == 'Y') return 4;
    else if (letter == 'K') return 5;
    else if (letter == 'J' || letter == 'X') return 8;
    else if (letter == 'Z' || letter == 'Q') return 10;
    else return 0;
}

