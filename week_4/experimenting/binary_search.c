#include <stdio.h>
#include <stdlib.h>

#define SIZE 200

void print_arr(const int arr[], int length);
void search(int number, int *arr, int length);

int main(void) {
    int *numbers;
    numbers = malloc(SIZE * sizeof(int));
    if (!numbers) return 1;

    int input;

    for (int i = 0; i < SIZE; i++) {
        numbers[i] = i;
    }

    print_arr(numbers, SIZE);

    printf("What number are you looking for? (The size is 0 to %i): ", SIZE - 1);
    scanf(" %i", &input);

    search(input, numbers, SIZE);


    free(numbers);
    return 0;
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

// Binary search function
void search(int number, int *arr, int length) {

    // Control for invalid search
    if (length < 2) {
        printf("Array for search too short.\n");
        return;
    } else if (!arr) {
        printf("Invalid array for search.\n");
        return;
    }

    // Initialisers
    int start = 0;
    int end = length - 1;
    

    // Main looping function 
    while (start <= end) {
        int n = start + (end - start) / 2;

        if (arr[n] == number) {
            printf("Found number %i at index %i.\n", number, n);
            return;
    }
        else if (arr[n] > number) end = n - 1;
        else if (arr[n] < number) start = n + 1;
}
    printf("Number not found.\n");
    return;


}



