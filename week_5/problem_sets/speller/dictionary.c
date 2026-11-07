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

    // Initialise root of trie and create next layer
    root = calloc(1, sizeof(node));
    if (!root) {
        printf("Could not allocate memory.\n");
        return false;
    }
    root->has_char = malloc(sizeof(bool));
    root->is_end_of_word = calloc(1, sizeof(bool));
    if (!root->has_char || !root->is_end_of_word) {
        printf("Memory allocation failed.\n");
        return false;
    }
    root->has_char = true;

    root = create_trie_layer(root);
    if (!root) {
        printf("Memory allocation failed.\n");
        return false;
    }

    // Set sequence root equal to root
    node *sequence_node = root;


    // open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (!dict) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // Read byte for byte
    char b;

    while (fread(&b, sizeof(char), 1, dict)) {
        // hash function
        unsigned int hashed_value = hash(b);

        // Check if word ended
        if (b == '\n') {
            dict_words++;
            sequence_node->is_end_of_word = true;
            sequence_node = root;
        }

        // if character already exists in node
        else if (sequence_node->next[hashed_value]->has_char == true) {
            sequence_node = sequence_node->next[hashed_value];
        }

        // else if character doesn't exist and new layer must be created
        else {
            sequence_node->next[hashed_value] = create_trie_layer(sequence_node->next[hashed_value]);
            sequence_node->next[hashed_value]->has_char = true;
            sequence_node = sequence_node->next[hashed_value];
        }

    }


    return true;


    /*
        IF b == \n:
            dict_words++
            go to root hash table
            continue
        ENDIF

        hash b

        IF node in layer already has a value
            go to next
            continue
        ENDIF
        
        allocate memory for next node layer
        store the result in the trie
        go to next



    */
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *sequencing_node = root;
    bool empty_node = false;
    for (int i = 0; i < HASH_LENGTH; i++) {
        if (!sequencing_node->next[i]->has_char) {
            free(sequencing_node->next[i]->has_char);
            free(sequencing_node->next[i]->is_end_of_word);
            free(sequencing_node->next[i]);
        }
        

    }

    return false;
    /*
    
    if (!sequencing_node->next[i]) {
        free sequencing_node's booleans
        tmp = sequencing_node
    free
    
    
    */
}

node *free_nodes(node *snode) {
    


}


node *create_trie_layer(node *curr) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        curr->next[i] = calloc(1, sizeof(node));
        if (!curr->next[i]) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        curr->next[i]->has_char = calloc(1, sizeof(bool));
        curr->next[i]->is_end_of_word = calloc(1, sizeof(bool));
        
        if (!curr->next[i]->has_char || 
            !curr->next[i]->is_end_of_word) {
            printf("Memory allocation failed.\n");
            return NULL;
        }


    }

    return curr;
}


