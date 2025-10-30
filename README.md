# 🧠 Trie in C

## 📖 Description

This project implements a **Trie** data structure in **C**.
A Trie is a specialized tree used to store and efficiently search strings, especially useful for tasks such as:

- Word autocompletion
- Spell checking
- Dictionary implementations
- Text pattern search

The Trie stores each word by chaining characters in a tree structure.
Each node represents a letter, and a special marker (`is_end`) indicates the end of a valid word.

You can insert words, search for them, delete them, and list all words stored in the Trie.

---

## 🧩 How It Works

Each node in the Trie contains:
- An array of pointers to its children (one for each letter `a–z`)
- A flag `is_end` marking if the node completes a valid word

When inserting a word, the algorithm traverses or creates nodes for each character.
When searching, it follows the same path and checks whether the final node is a word-ending node.

---

## 🖼️ Trie Structure Illustration
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/d7969c2f-59e3-47c8-8a00-e571ec8809e8" />

---

## 🧱 Project Structure

```
📁 project_root/
├── trie.c        # Implementation of the Trie
├── trie.h        # Header file (function prototypes)
├── main.c        # Example usage
├── Makefile      # Build and clean targets
└── README.md     # Project documentation
```

---

## 🧰 Build and Run

To compile and run the program:

```bash
make
./trie_app
```

To clean all generated files:

```bash
make clean
```

---

## 🧮 Example Usage

```bash
Search 'chien' : found
Search 'chouette' : not found

Words before deletion :
chat
chapeau
chien
chou
choix

Deleting 'chou'...

Words after deletion :
chat
chapeau
chien
choix
```

---

## 🙏 Credits

Original Python implementation by [**github.com/syphh**](https://gist.github.com/syphh)
C version rewritten and adapted by **myself**, focusing on:
- Memory management (allocation and cleanup)
- Fixed-size alphabet array (`a–z`)
- Readable, structured Allman-style formatting
