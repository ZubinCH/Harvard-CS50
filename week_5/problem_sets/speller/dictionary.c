// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

unsigned int dict_words = 0;


// Trie
node *root;


// Returns true if word is in dictionary, else false
bool check(const char *word) {
    node *sequencing_node = root;

    for (int i = 0; word[i] != '\0'; i++) {
        unsigned int hashed_char = hash(word[i]);

        if (sequencing_node->next[hashed_char])
            sequencing_node = sequencing_node->next[hashed_char];
        else return false;
    }


    return (sequencing_node && sequencing_node->is_end_of_word);



    /* 
        
        WHILE reading word
            hash char

            IF sequencing_node->next[hash] && sequencing_node->next[hash] has_char
                sequencing_node = sequencing_node->next[hash]
            ENDIF

            ELSE
                RETURN false
            END ELSE

        END WHILE

        RETURN (sequencing_node && is end of word)
    

        */

}

// Hashes word to a number
unsigned int hash(const char word) {
    return (word == '\'') ? HASH_LENGTH - 1 : toupper(word) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    // open dictionary file
    FILE *dict = fopen(dictionary, "r");
    if (!dict) {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // Initialise root of trie and create next layer
    root = malloc(sizeof(node));
    if (!root) {
        printf("Could not allocate memory.\n");
        fclose(dict);
        return false;
    }
    root->is_end_of_word = false;
    create_trie_layer(root);

    // Set sequence root equal to root
    node *sequence_node = root;

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
        else if (sequence_node->next[hashed_value]) {
            sequence_node = sequence_node->next[hashed_value];
        }

        // else if character doesn't exist and new layer must be created
        else {
                sequence_node->next[hashed_value] = malloc_node(sequence_node->next[hashed_value]);
                if (!sequence_node->next[hashed_value]) {
                    printf("Memory allocation failed.\n");
                    return false;
                }
            sequence_node = sequence_node->next[hashed_value];
        }

    }

    fclose(dict);
    return true;


    /*
        IF b == 0:
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
bool unload(void) {
    free_nodes(root);
    if (!root) return false;

    return true;
}

void free_nodes(node *sequencing_node) {
    if (!sequencing_node) return;

    for (int i = 0; i < HASH_LENGTH; i++) {
        if (sequencing_node->next[i]) {
            free_nodes(sequencing_node->next[i]);
        }
    }

    free(sequencing_node);
}

void create_trie_layer(node *curr) {
    for (int i = 0; i < HASH_LENGTH; i++) {
        curr->next[i] = NULL;
    }

    return;
}

node *malloc_node(node *curr) {
    curr = malloc(sizeof(node));
    if (!curr) return NULL;
    curr->is_end_of_word = false;
    create_trie_layer(curr);
    return curr;
}



