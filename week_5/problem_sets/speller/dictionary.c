// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

const unsigned int N = 26;
unsigned int dict_words = 0;

// Represents a node in a trie
typedef struct node
{
    struct node *next[HASH_LENGTH];
    bool *has_char;
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


// Trie
node *root;


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
    root = calloc(1, sizeof(node));
    if (!root) {
        printf("Could not allocate memory.\n");
        return false;
    }
    root->has_char = true;

    root = create_trie_layer(root);
    if (!root) {
        printf("Memory allocation failed.\n");
        return false;
    }

    node *sequence_node = root;


    FILE *dict = fopen(dictionary, "r");
    if (!dict) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }


    char word[LENGTH + 1];
    char b;
    int i = 0;

    while (fread(&b, sizeof(char), 1, dict)) {
        // Check if word ended
        if (b == '\n') {
            dict_words++;
            sequence_node->is_end_of_word = true;
            sequence_node = root;
            continue;
        }

        // hash function
        unsigned int hashed_value = hash(b);
        

        // if character already exists in node
        if (sequence_node->next[hashed_value]->has_char == true) {
            sequence_node = sequence_node->next[hashed_value];
            continue;
        }

        // else if character doesn't exist and new layer must be created
        sequence_node->next[hashed_value] = create_trie_layer(sequence_node->next[hashed_value]);
        sequence_node->next[hashed_value]->has_char = true;
        sequence_node = sequence_node->next[hashed_value];

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

node *create_trie_layer(node *curr) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        curr->next[i] = calloc(1, sizeof(node));
        if (!curr->next[i]) {
            printf("Memory allocation failed.\n");
            return NULL;
        }

    }

    return curr;
}


