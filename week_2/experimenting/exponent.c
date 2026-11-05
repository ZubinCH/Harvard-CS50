#include <stdio.h>
#include <string.h>

int exponent(int x, int n) {
    int x_ini = x;
    for (int t = 0; t < n - 1; t++)
    {
        x_ini = x_ini*x;
    }
    return x_ini;
}

int main(void) {
    int y;

    printf("%i\n", exponent(2,3));


}