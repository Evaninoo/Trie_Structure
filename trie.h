#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Trie node main structure
typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end;
} TrieNode;

// Creates a new Trie node
TrieNode *create_node(void);

// Checks if a node has any children
int has_children(TrieNode *node);

// Inserts a word into the Trie
void insert(TrieNode *root, const char *word);

// Searches for a word in the Trie
int search(TrieNode *root, const char *word);

// Deletes a word from the Trie (recursive)
int delete_word(TrieNode *node, const char *word, int depth);

// Collects and prints all words in the Trie
void collect_words(TrieNode *node, char *buffer, int depth);

// Frees all allocated nodes in the Trie
void free_trie(TrieNode *node);

#endif

