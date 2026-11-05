#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    char *s = "here is a string";
    if (s == NULL) {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL) {
        return 1;
    }
    
    strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);


    free(t);

    return 0;
}
