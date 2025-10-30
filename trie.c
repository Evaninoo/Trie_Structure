i#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int is_end;
} TrieNode;

// Create new node
TrieNode *create_node()
{
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));
    if (!node)
    {
        fprintf(stderr, "Memory error\n");
        exit(EXIT_FAILURE);
    }

    node->is_end = 0;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

// Check if node has any children
int has_children(TrieNode *node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] != NULL)
        {
            return 1;
        }
    }

    return 0;
}

// Insert word
void insert(TrieNode *root, const char *word)
{
    TrieNode *node = root;

    for (int i = 0; word[i]; i++)
    {
        char c = word[i];

        if (c < 'a' || c > 'z')
        {
            continue;
        }

        int index = c - 'a';

        if (!node->children[index])
        {
            node->children[index] = create_node();
        }

        node = node->children[index];
    }

    node->is_end = 1;
}

// Search for a word
int search(TrieNode *root, const char *word)
{
    TrieNode *node = root;

    for (int i = 0; word[i]; i++)
    {
        char c = word[i];

        if (c < 'a' || c > 'z')
        {
            return 0;
        }

        int index = c - 'a';

        if (!node->children[index])
        {
            return 0;
        }

        node = node->children[index];
    }

    return node->is_end;
}

// Delete recursively
int delete_word(TrieNode *node, const char *word, int depth)
{
    if (!node)
    {
        return 0;
    }
    if (word[depth] == '\0')
    {
        node->is_end = 0;
        return !has_children(node);
    }

    int index = word[depth] - 'a';

    if (delete_word(node->children[index], word, depth + 1))
    {
        free(node->children[index]);
        node->children[index] = NULL;
        return !node->is_end && !has_children(node);
    }

    return 0;
}

// Print words
void collect_words(TrieNode *node, char *buffer, int depth)
{
    if (node->is_end)
    {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i])
        {
            buffer[depth] = 'a' + i;
            collect_words(node->children[i], buffer, depth + 1);
        }
    }
}

// Free all nodes
void free_trie(TrieNode *node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i])
        {
            free_trie(node->children[i]);
        }
    }

    free(node);
}
