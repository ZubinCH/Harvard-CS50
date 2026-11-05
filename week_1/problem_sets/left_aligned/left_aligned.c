#include <stdio.h>


void print_rows(int bricks) {

    for(int i = 1; i <= bricks; i++) {
        for(int j = bricks - i; j >= 0; j--) {
            printf("#");
        }
        printf("\n");
    }
}


int main(void) {
    int prompt;

    printf("Select a height: ");
    scanf(" %i", &prompt);

    
    for(int i = 1; i <= prompt; i++) {
        for(int j = 1; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }

    print_rows(prompt);


    return 0;
}