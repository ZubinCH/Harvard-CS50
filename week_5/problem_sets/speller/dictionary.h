// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASH_LENGTH 27

// Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);

// Helper prototypes
node *create_trie_layer(node *curr);
void free_nodes(node *sequencing_node);
void free_self_node (node *no_next);



#endif // DICTIONARY_H
