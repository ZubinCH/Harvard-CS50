#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

int main(void) {
    int *scores = malloc(SIZE * sizeof(int));

    for (int i = 0; i < SIZE; i++) {
        printf("[%i: %i]\n", i, scores[i]);

    }
    
    free(scores);
    return 0;
}