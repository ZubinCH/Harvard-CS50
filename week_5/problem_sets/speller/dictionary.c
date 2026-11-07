// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

const unsigned int N = 26;
unsigned int dict_words = 0;

// Represents a node in a hash table
typedef struct node
{
    struct node *next;
    bool *contains_word;
    bool *is_end_of_word;
} node;


/*
    if b == \n:
        dict_words++
        go to root hash table
        continue
    hash b
    if trie already has a value
        go to next
    else
        root[b]->next 
    store the result in the trie



*/


// Hash table
node *root[HASH_LENGTH];


// Returns true if word is in dictionary, else false
bool check(const char *word) {
    


    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
    return (word[0] == '\'') ? HASH_LENGTH - 1 : toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    FILE *dict = fopen(dictionary, "r");
    if (!dict) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    for (int i = 0; i < HASH_LENGTH; i++) {
        root[i]->next = malloc(sizeof(node));
        if (!root[i]->next) {
            printf("Failed to allocate memory.\n");
            return false;
        }
    }

    char word[LENGTH + 1];
    char b;
    int i = 0;

    while (fread(&b, sizeof(char), 1, dict)) {
        if (b == '\n') {
            dict_words++;
            // create function to go to root 
            continue;
        }

    }





    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}

bool create_trie_layer(node *curr) {
    curr->next = calloc(HASH_LENGTH, sizeof(node));
    if (curr->next != NULL) return false;
    return true;
}


