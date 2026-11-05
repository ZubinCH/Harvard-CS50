#include <stdio.h>

float average(int length, int numbers[]);


int main(void) {
    const int N = 3;

    int total_scores[N];

    for (int i = 0; i < N; i++){

        printf("Score %i: ", i + 1);
        scanf(" %i", &total_scores[i]);

    }


    printf("%f", average(N, total_scores));
    
}



float average(int length, int numbers[]) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += numbers[i];
    }
    
    return sum / (float) length;
}