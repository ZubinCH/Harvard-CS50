#include <stdio.h>



int main(void) {
    char strings[6][10] = {"battleship", "boot______", "cannon____", "iron______", "thimble___", "top_hat___"};

    char s[15];
    printf("Choose a ship: ");
    scanf(" %s", s);
    
    for (int i = 0; i < 6; i++) {
        int t = 0;
        int j = 0;
        while (j < 10) {
            if (strings[i][j] == s[j]) {
                t++;
            }
            j++;
        }
        if (j == t) {
            printf("Found at index %i\n", i);
            return 0;
        }

    }

    printf("Not found %s\n", s);
    return 1;


}