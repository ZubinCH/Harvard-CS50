#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(char *str1, char *str2);


int main(void) {
    char *st1 = "Hello, ";
    char *st2 = "Zubin";

    char *st3 = concatenate(st1, st2);

    printf("%s\n", st3);
    free(st3);
}


char *concatenate(char *str1, char *str2) {
    const int N = strlen(str1) + strlen(str2) + 1;
    const int len1 = strlen(str1);
    char *str3 = malloc(N);

    for (int i = 0; i < len1; i++) {
        str3[i] = str1[i];
    }

    for (int j = strlen(str1); j < N; j++) {
        str3[j] = str2[j - len1];
    }

    str3[N-1] = '\0';



    return str3;
}