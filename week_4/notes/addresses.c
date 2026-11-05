#include <stdio.h>


typedef char* string;

string s = "string";

int main(void) {
    char string[] = "Hi!";
    char *str = "Hi";

    printf("%s\n", str);
    printf("%p: %s\n", string, string);

    for (int i = 0; i < 4; i++) {
        printf("%p: %c\n", &string[i], string[i]);
    }

}