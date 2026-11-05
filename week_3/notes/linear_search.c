#include <stdio.h>



int main(void) {
    int array[] = {20, 500, 10, 5, 100, 1, 50};
    int number;

    printf("What number are you searching for?: ");
    scanf(" %i", &number);

    for (int i = 0; i < 7; i++) {
        if (array[i] == number) {
            printf("Found at %i.\n", i + 1);
            return 0;
        }

    }
    
    printf("Not found\n");
    return 1;

}