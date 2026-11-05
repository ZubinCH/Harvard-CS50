#include <stdio.h>
#include <string.h>


int main(void) {
    char names[][6] = {"Kelly", "David", "Johnny"};
    int numbers[] = {12356, 654321, 121212};

    char name[6];
    printf("Name: ");
    scanf(" %s", name);

    for (int i = 0; i < 3; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found %s with number %i\n", names[i], numbers[i]);

            return 0;
        }

    }


    return 1;
}