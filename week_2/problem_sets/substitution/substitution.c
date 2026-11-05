#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A readable key: uqwrapsdefghjkilzxcvobnmyt

char *get_string(char *text);



int main(int argc, char *argv[]) {
    
    if (argc != 2) {
        printf("Invalid argument. Usage:\n  ./program KEY\n");
        return 1;
    }

    int isanalpha = 1;
    int unique = 1;
    int keylen = strlen(argv[1]);

    // Check all items in the key are alpha and unique. Then capitalise key.
    for (int i = 0; i < keylen; i++) {
        if(!isalpha(argv[1][i])) isanalpha = 0;
        else {
            argv[1][i] = toupper(argv[1][i]);
        }
        for (int j = 0; j < keylen; j++) {
            if ( i != j && argv[1][j] == argv[1][i]) unique = 0;
        }
    }
    // Check valid key
    if (keylen != 26 || !isanalpha || !unique) {
        printf("INVALID KEY\n");
        return 1;
    }

    // Create copy of key in lowercase.
    char *lowerkey = malloc((keylen + 1) * sizeof(char));
    if (lowerkey == NULL) return 1;
    for (int i = 0; i < keylen; i++) {
        lowerkey[i] = tolower(argv[1][i]);
    }
    lowerkey[keylen] = '\0';


    
    char* plaintext = get_string("Plaintext: ");

    int plainlen = strlen(plaintext);
    char *ciphertext = malloc((plainlen + 1) * sizeof(char));
    if (ciphertext == NULL) {
        free(lowerkey);
        return 1;
    }


    for (int i = 0; i < plainlen; i++) {
        if(islower(plaintext[i])) {
            ciphertext[i] = lowerkey[plaintext[i] - 'a'];
        }

        else if (isupper(plaintext[i])) {
            ciphertext[i] = argv[1][plaintext[i] - 'A'];
        }
        else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[plainlen] = '\0';

    printf("Ciphertext: %s", ciphertext);
    printf("\n");
    


    free(lowerkey);
    free(ciphertext);
    return 0;
}





char *get_string(char *text) {
    #define MAX_SIZE 500
    char input[MAX_SIZE];

    printf("%s", text);
    fgets(input, MAX_SIZE, stdin);

    input[strcspn(input, "\n")] = '\0';

    char *trunc = malloc(strlen(input) + 1);
    if (trunc == NULL) return NULL;

    return strcpy(trunc, input);
}