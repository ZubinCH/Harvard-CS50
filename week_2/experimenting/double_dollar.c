#include <stdio.h>

int main(void) {
    int dollars = 1;
    const int x = 1;

    while (x == 1) {
        char c = 0;
        
        while (c != 'y' && c != 'n') {
            printf("Here is $%i. Double it and give it to the next person?: ", dollars);
            scanf(" %c", &c);
        }

        printf("\n");

        if (c == 'y') {
            dollars *= 2;
        }
        else {
            break;
        }
    }

    printf("Your geometric sum is $%i. \n", dollars);

}