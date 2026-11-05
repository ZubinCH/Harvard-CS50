#include <stdio.h>
#include <stdbool.h>

int main(void) {

    int x;

    printf("What is x?: ");
    scanf(" %i", &x);

    switch(x) {
        case 5:
            printf("Five, ");
        case 4:
            printf("Four, ");
        case 3:
            printf("Three, ");
        case 2:
            printf("Two, ");
        case 1:
            printf("One, ");
        default:
            printf("Blast off! \n");
            break;

    }

char y[20];

snprintf(y, sizeof y, "%s", false ? "true" : "false");


printf("%s\n", y);




}