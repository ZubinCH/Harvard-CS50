#include <stdio.h>
#include <string.h>

int main(void) {
    int x;
    int y;
    char operator;
    int answer;

    do {
        printf("Type your first number: ");
        scanf("%d", &x);
    }
        while (!(x>0 || x<=0));

    do {
        printf("Type your second number: ");
        scanf("%d", &y);
    }
        while (!(y>0 || y<=0));

    do {
        printf("Select your operator (+, -, *, or /)");
        scanf("%c", &operator);
    }
        while (!(operator == '+' || operator == '-' || operator == '*' || operator == '/' ));

printf("\n");
printf("Your answer is: ");

    if ( operator == '+') {
        answer = x + y;
    }
    else if (operator == '-') {
        answer = x - y;
    }
    else if (operator == '*') {
        answer = x * y;
    }
    else if (operator == '/') {
        answer = x / y;
    }
    else {
        printf("There was an error with operator");
    }

    printf("%i\n", answer);


    return 0;
}