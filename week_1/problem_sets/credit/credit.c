#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *get_string(char *text);
void print_arr(int *array, size_t size);


int main(void) {
    // Get card number and ensure all digits are numbers.
    char *card_number;
    int isadigit = 1;
    do {
        isadigit = 1;
        card_number = get_string("Card number: ");

        for (int i = 0, n = strlen(card_number); i < n; i++) {
            if (!isdigit(card_number[i])) { 
                isadigit = 0; 
                free(card_number);
                break;
            }

        }
        
    }
    while (!isadigit);

    size_t len = strlen(card_number);
    int *arr = malloc(len * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0, n = strlen(card_number); i < n; i++) {
        arr[i] = card_number[i] - '0';
    }

    // Checksum
    int sum = 0;
    int double_digit = 0;

    for (int i = len - 1; i >= 0; i--) {
        int digit = arr[i];

        if (double_digit) {
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        double_digit = !double_digit;
    }

    if (sum % 10 != 0) {
        printf("INVALID\n");
        free(card_number);
        free(arr);
        return 0;
    }


    // Card type
    if (arr[0] == 3 && (arr[1] == 4 || arr[1] == 7) && len == 15) {
        printf("AMEX\n");
    }
    else if (arr[0] == 5 && arr[1] >= 1 && arr[1] <= 5 && len == 16) {
        printf("MASTERCARD\n");
    }
    else if (arr[0] == 4 && (len == 13 || len == 16)) {
        printf("VISA\n");
    }
    else {
        printf("OTHER\n");
    }






    free(card_number);
    free(arr);
    return 0;
}









char *get_string(char *text) {
    #define MAX_SIZE 100
    char input[MAX_SIZE];

    printf("%s", text);
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    char *trunc = malloc(strlen(input) + 1);
    if (trunc == NULL) return NULL;

    return strcpy(trunc, input);
}


void print_arr(int *array, size_t size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%i", array[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}