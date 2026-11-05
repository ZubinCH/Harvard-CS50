#include <stdio.h>


int array_length(int array[]);

int main(void) {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8};


    printf("Array length: %i\n", array_length(array));



}


int array_length(int array[]) {
    int n;
    while (array[n] != '\0') {
        n++;
    }
    return n/2 - 1;
}