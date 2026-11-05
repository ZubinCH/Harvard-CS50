#include <stdio.h>
#include <stdlib.h>

#define LENGTH 7

void print_arr(double *arr, int length);
void sort (double *arr, int length);

int main(void) {
    double *input = malloc(sizeof(double) * LENGTH);
    double unsorted[] = {5, 0, 1, 3, 2, 6, 4};
    for (int i = 0; i < LENGTH; i++) {
        input[i] = unsorted[i];
    }


    print_arr(input, LENGTH);

    sort(input, LENGTH);

    print_arr(input, LENGTH);
    free(input);
    return 0;
}


void sort (double *arr, int length) {
    // split
    double *left = malloc(sizeof(double) * (length / 2));
    double *right = malloc(sizeof(double) * (length - length / 2));
    if (!left || !right) {
        printf("Memory could not be allocated.\n");
        return;
    }

    for (int i = 0; i < length / 2; i++) {
        left[i] = arr[i];
        right[i] = arr[length - length / 2 + i - 1];
    }
    right[length - length / 2 - 1] = arr[length - 1];

    /*
    print_arr(left, length / 2);
    print_arr(right, length - length / 2);
    */

    // sort left
    int left_sorted = 1;
    for (int i = 0; i < length / 2 - 1; i++) {
        if (left[i] > left[i + 1]) left_sorted = 0;
    }
    if (!left_sorted) sort(left, length / 2);

    int right_sorted = 1;
    // sort right
    for (int i = 0; i < length - length / 2 - 1; i++) {
        if (right[i] > right[i + 1]) right_sorted = 0;
    }
    if (!right_sorted) sort(right, length - length / 2);

    // merge
    if (left_sorted && right_sorted) {
        for (int i = 0; i < length / 2; i++) {
            if (left[i] > right[i]) {
                arr[i] = right[i];
            }
            else {
                arr[i] = left[i];
            }
        }
        arr[length - 1] = right[length - length / 2 - 1];
        print_arr(arr, length);
    }


    free(left);
    free(right);
}

void print_arr(double *arr, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%0.2f", arr[i]);
        if (i != length - 1) printf(", ");
    }
    printf("]\n");
}



