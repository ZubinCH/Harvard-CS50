#include <stdio.h>



int main(void) {
    FILE *file = fopen("phonebook.csv", "a");
    // Use any time when using pointers to see if all went well.
    if (file == NULL) {
        return 1;
    }

    char *name = "Zubin Chowdhury";
    char *number = "0404 807 377";

    fprintf(file, "%s, %s\n", name, number);



    fclose(file);

    return 0;
}   