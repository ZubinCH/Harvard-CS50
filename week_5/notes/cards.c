#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define SIZE 52

typedef struct card {
    char type;
    uint8_t number; 

} card;


int main(void) {
    card deck[52];

    char types[4] = {'A', 'D', 'H', 'S'};

    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 13; j++) {
            deck[(i+1)*(j)].number = j;

        }
        


    }





}