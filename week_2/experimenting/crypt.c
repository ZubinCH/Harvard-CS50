#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(char *plaintext, int key);
void decrypt(char *ciphertext);
int get_int(char *prompt);

int main(void) {
    char *test = encrypt("Send me a new message to solve.", get_int("Key: "));

    printf("%s\n", test);

    decrypt("Mjqqt ymjwj! Ymnx rjxxflj nx jshwduyji bnym f Hfjxfw hnumjw. Hfs dtz ijhtij ny?");


    free(test);
}



char *encrypt(char *plaintext, int key) {
    char *ciphertext = malloc(strlen(plaintext) + 1);
    key = ((key % 26) + 26) % 26;

    if (ciphertext == NULL) return NULL;

    for (int i = 0; plaintext[i] != '\0'; i++) {

        if (isupper(plaintext[i])) {
            ciphertext[i] = (plaintext[i] - 'A' + key) % 26 + 'A';
        }
        else if (islower(plaintext[i])) {
            ciphertext[i] = (plaintext[i] - 'a' + key) % 26 + 'a';
        }
        else {
            ciphertext[i] = plaintext[i];
        }
        ciphertext[strlen(plaintext)] = '\0';
    }


    return ciphertext;
}


int get_int(char *prompt) {
    int input;
    printf("%s", prompt);
    scanf(" %i", &input);
    return input;
}


void decrypt(char *ciphertext) <%

    char *plaintext = malloc(strlen(ciphertext) + 1);
    if (plaintext == NULL) return;

    for (int key = 0; key < 26; key++) {

        for (int j = 0; ciphertext[j] != '\0'; j++) {

            if (isupper(ciphertext[j])) {
                plaintext[j] = (ciphertext[j] - 'A' - key + 26) % 26 + 'A';
            }
            else if (islower(ciphertext[j])) {
                plaintext[j] = (ciphertext[j] - 'a' - key + 26) % 26 + 'a';
            }
            else {
                plaintext[j] = ciphertext[j];
            }
        }

        plaintext[strlen(ciphertext)] = '\0';
        printf("[Plaintext: %s, Key: %i]\n", plaintext, key);
    }

    free(plaintext);
}
