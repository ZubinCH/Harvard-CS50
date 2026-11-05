#include <stdio.h>

void print_arr(const int arr[], int length);
void bubble(int *arr, int length);

#define SIZE 8

int main(void) {
    int unsorted[SIZE] = {7, 6, 3, 2, 0, 4, 1, 5};


    bubble(unsorted, SIZE);
    print_arr(unsorted, SIZE);
    return 0;
}

void bubble(int *arr, int length) {
    if (!arr || length < 2) return;
    int swapped = 0;

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
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