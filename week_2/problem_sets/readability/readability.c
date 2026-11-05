#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_string(char *text);



int main(void) {
    char *rtext = get_string("Text: ");
    int words = 0;
    int sentences = 0;
    int otherchar = 0;
    int tletters = strlen(rtext);

    for (int i = 0; i < tletters; i++) {

        if (rtext[i] == ' ' || rtext[i] == '-') words++;
        // else if (rtext[i] == ',' || rtext[i] == '"' || rtext[i] == ':' || rtext[i] == ';') otherchar++;
        else if (rtext[i] == '.' || rtext[i] == '!' || rtext[i] == '?') sentences++;
    }

    words++;
    int letters = tletters - words - sentences - otherchar - 1;

    double L = ((double) letters / words) * 100;
    double S = ((double) sentences / words) * 100;
    double index = 0.0588 * L - 0.296 * S - 15.8;

    printf("Index: %0.f\n", index);



    free(rtext);
}






char *get_string(char *text) {
    #define MAX_SIZE 500
    char input[MAX_SIZE];

    printf("%s", text);
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    char *trunc = malloc(strlen(input) + 1);
    if (trunc == NULL) return NULL;

    return strcpy(trunc, input);
}