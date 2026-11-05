#include <stdio.h>

#define SIZE 8

void sort(int *arr, int length);
void print_arr(const int arr[], int length);

int main(void) {
    int unsorted[SIZE] = {7, 6, 3, 2, 0, 4, 1, 5};
    sort(unsorted, SIZE);
    print_arr(unsorted, SIZE);
    return 0;
}

// Selection sort
void sort(int *arr, int length) {
    if (!arr || length < 2) return;

    for (int i = 0; i < length - 1; i++) {
        int max_i = 0;

        for (int j = 1; j < length - i; j++) {
            if (arr[j] > arr[max_i]) max_i = j;
        }

        int tmp = arr[length - 1 - i];
        arr[length - 1 - i] = arr[max_i];
        arr[max_i] = tmp;

    } 
}


// Print array function
void print_arr(const int arr[], int length) {
    if (length <= 0) return; 

    printf("[");
    for (int i = 0; i < length - 1; i++) {
        printf("%i, ", arr[i]);
    }
    printf("%i]\n", arr[length - 1]);


}