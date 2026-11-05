#include <stdio.h>
#include <string.h>

typedef struct {
    char name[7];
    int number;

} person;

int main(void) {

    person people[3];

    strcpy(people[0].name, "Kelly");
    people[0].number = 123456;
    
    strcpy(people[1].name, "David");
    people[1].number = 654321;
    
    strcpy(people[2].name, "Johnny");
    people[2].number = 121212;
    


    char name[6];
    printf("Name: ");
    scanf(" %s", name);

    for (int i = 0; i < 3; i++) {
        if (strcmp(people[i].name, name) == 0) {
            printf("Found %s with number %i\n", people[i].name, people[i].number);

            return 0;
        }

    }

    printf("Number of %s not found.\n", name);
    return 1;
}