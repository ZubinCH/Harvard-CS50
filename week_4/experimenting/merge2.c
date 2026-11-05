#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LENGTH 7

void print_arr(int *arr, int length);
int *sort(int *arr, int length);
int *merge(int *left, int *right, int length); // Merges two sorted arrays into a larger sorted array.





int main(void) {
    int *array = malloc(sizeof(int) * LENGTH);
    array[0] = 5;
    array[1] = 0;
    array[2] = 1;
    array[3] = 3;
    array[4] = 2;
    array[5] = 6;
    array[6] = 4;

    

    print_arr(array, LENGTH);

    array = sort(array, LENGTH);

    print_arr(array, LENGTH);



    free(array);
    return 0;
}



int *merge(int *left, int *right, int length) {
    int *arr = malloc(sizeof(int) * length);
    if (!arr) {
        printf("Memory could not be allocated.\n");
        return left;
    }

    int m = 0, n = 0;

    while (m < length / 2 && n < length - length / 2) {
        if (left[m] < right[n]) {
            arr[m + n] = left[m];
            m++;
        }
        else {
            arr[m + n] = right[n];
            n++;
        }
    }

    while (m < length / 2) {
        arr[m + n] = left[m];
        m++;
    }

    while (n < length - length / 2) {
        arr[m + n] = right[n];
        n++;
    }


    return arr;
}

int *sort(int *arr, int length) {

    // Base case
    if (length <= 1) return arr;


    // Allocate memory for left and right arrays
    int *left = malloc(sizeof(int) * (length / 2));
    int *right = malloc(sizeof(int) * (length - length / 2));
    if (left == NULL || right == NULL) {
        printf("Memory could not be allocated.\n");
    }

    // Populate left and right arrays
    for (int i = 0, n = length / 2; i < n; i++) {
        left[i] = arr[i];
        right[i] = arr[length / 2 + i];
    }
    right[length - length / 2 - 1] = arr[length - 1];



    // Sort the left side
    left = sort(left, length / 2);

    // Sort the right side
    right = sort(right, length - length / 2);

    // Merge
    arr = merge(left, right, length);


    free(left);
    free(right);

    return arr;
}




void print_arr(int *arr, int length) {
    printf("[");
    for (int i = 0; i < length; i++) {
        printf("%i", arr[i]);
        if (i != length - 1) printf(", ");
    }
    printf("]\n");
}




/*
 * Pseudocode:

    split in two

    if left unsorted:
        split in two
        if left unsorted:


        sort the left side

    sort the right side

    merge

    



 */


