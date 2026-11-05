#include <stdio.h>
#include <math.h>

// Newton's Method

float squareroot(float x, float tolerance);

int main(void) {
   
int input;

printf("Select a number x: ");
scanf(" %i", &input);

printf("\nsqrt(%i)\n", input);

printf("%f\n", squareroot(input, 0.0005));

}


float squareroot(float x, float tolerance) {
    float y_n = x / 8;
    int i = 1;


    while (fabsf((y_n * y_n) - x) > tolerance) {
        y_n = 0.5*(y_n + x/y_n);
        i++;

    }

    printf("For x = %f, y_n = %f for i = %i\n", x, y_n, i);

    return y_n;
}