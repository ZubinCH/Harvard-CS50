#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define ROWS 3
#define COLS 3

typedef struct {
    int rows;
    int cols;
    int data[ROWS][COLS];

} matrix; 

int main(void) {

    matrix k;
    k.rows = ROWS;
    k.cols = COLS;
    k.data[ROWS][COLS] = {
        {1, 2, 3},
        {2, 0, 1},
        {0, 0, 1}
    }



}


void print_matrix(int arr[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("[");
        for (int j = 0; j < cols - 1; j++) {
            printf("%i, ", arr[i][j]);
        }
        printf("%i]\n", arr[i][cols - 1]);
    }

}