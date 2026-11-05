#include <stdio.h>

void print_array(unsigned long arr[], int size);

int main(void) {
    const int N = 90;
    unsigned long fib_arr[N];

    fib_arr[0] = 1; 
    fib_arr[1] = 1;

    for (int i = 2; i < N; i++) {
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i-2];
    }
    
    print_array(fib_arr, N);

}


void print_array(unsigned long arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("[n = %i :   %lu]\n", i + 1, arr[i]);

    }

}


/*
void print_array(unsigned long arr[], int size) {
    printf("[");

    for (int i = 0; i < size - 1; i++) {
        printf("%lu, ", arr[i]);

    }
    printf("%lu]\n", arr[size - 1]);


} */