#include <stdio.h>

void draw(int n);
int factorial(int n);

int main(void) {
    int height;
    printf("Height: ");
    scanf(" %i", &height);

    draw(height);

    printf("%i\n", factorial(5));

}


void draw(int n) {

    // Base case
    if (n <= 0) {
        return;
    }

    // Print a pyramid of height n - 1
    draw (n - 1);

    // Print one more row
    for (int i = 0; i < n; i++) {
        printf("#");

    }
    printf("\n");
}

int factorial(int n) {
    if (n == 1) {
        return n;
    }

    return n * factorial(n-1);
}