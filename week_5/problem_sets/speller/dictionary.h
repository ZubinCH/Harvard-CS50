// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASH_LENGTH 27

// Represents a node in a trie
typedef struct node
{
    struct node *next[HASH_LENGTH];
    bool is_end_of_word;
} node;

// Prototypes
bool check(const char *word);
unsigned int hash(const char word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

// Helper prototypes
void create_trie_layer(node *curr);
void free_nodes(node *sequencing_node);
node *malloc_node(node *curr);



#endif // DICTIONARY_H
