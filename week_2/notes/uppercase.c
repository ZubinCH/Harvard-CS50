#include <stdio.h>
#include <string.h>


int main(void) {
    char c1[50];
    printf("Before: ");
    scanf(" %50c", c1);

    printf("%lu\n", strlen(c1));

   /* for (char i = 0, n = strlen(c1); i < n; i++) {
        printf("%c", i);
    }
    printf("\n"); */
}