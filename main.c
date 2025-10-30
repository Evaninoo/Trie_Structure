#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trie.h"

// Trie usage example
int main()
{
    TrieNode* root = create_node();
    char buffer[64];

    insert(root, "chat");
    insert(root, "chien");
    insert(root, "chou");
    insert(root, "choix");
    insert(root, "chapeau");

    printf("Search 'chien' : %s\n",
           search(root, "chien") ? "found" : "not found");

    printf("Search 'chouette' : %s\n",
           search(root, "chouette") ? "found" : "not found");

    printf("\nWords before deletion :\n");
    collect_words(root, buffer, 0);

    printf("\nDeleting 'chou'...\n");
    delete_word(root, "chou", 0);

    printf("\nWords after deletion :\n");
    collect_words(root, buffer, 0);

    free_trie(root);

    return 0;
}
