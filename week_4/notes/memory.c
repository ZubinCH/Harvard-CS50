#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

int main(void) {
    int *x = malloc(SIZE * sizeof(int));
    if (x == NULL) {
        return 1;
    }
    for (int i = 0; i < SIZE; i++) {
        printf("Choose number %i: ", i + 1);
        scanf(" %i", x[i]);

    }

    printf("%i", x);


    free(x);
}