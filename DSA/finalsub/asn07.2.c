#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a node in the tree
struct TreeNode {
    char title[100];  // Title of chapter/section/subsection
    struct TreeNode* firstChild; // Pointer to the first child (next level)
    struct TreeNode* nextSibling; // Pointer to the next sibling (same level)
};

// Function to create a new node
struct TreeNode* createNode(char* title) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    strcpy(newNode->title, title);
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

// Function to add a child to a node
void addChild(struct TreeNode* parent, struct TreeNode* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child; // If no child exists, add first child
    } else {
        struct TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling; // Traverse to the last sibling
        }
        temp->nextSibling = child; // Add the child as the next sibling
    }
}

// Function to print the tree (book structure)
void printTree(struct TreeNode* root, int level) {
    if (root == NULL) return;

    // Print the current node with indentation based on the level
    for (int i = 0; i < level; i++) {
        printf("\t");  // Indentation based on the level of the node
    }
    printf("%s\n", root->title);

    // Recursively print the first child and the siblings
    printTree(root->firstChild, level + 1);
    printTree(root->nextSibling, level);
}

// Main function
int main() {
    // Create the book (root of the tree)
    struct TreeNode* book = createNode("Book: Learn Programming in C");

    // Create chapters
    struct TreeNode* chapter1 = createNode("Chapter 1: Introduction");
    struct TreeNode* chapter2 = createNode("Chapter 2: Basics of C");
    struct TreeNode* chapter3 = createNode("Chapter 3: Functions");

    // Add chapters to the book
    addChild(book, chapter1);
    addChild(book, chapter2);
    addChild(book, chapter3);

    // Create sections and subsections for Chapter 1
    struct TreeNode* section1_1 = createNode("Section 1.1: What is Programming?");
    struct TreeNode* section1_2 = createNode("Section 1.2: History of C");

    struct TreeNode* subsection1_1_1 = createNode("Subsection 1.1.1: Importance of Programming");
    struct TreeNode* subsection1_1_2 = createNode("Subsection 1.1.2: Different Programming Languages");

    addChild(chapter1, section1_1);
    addChild(chapter1, section1_2);

    addChild(section1_1, subsection1_1_1);
    addChild(section1_1, subsection1_1_2);

    // Create sections and subsections for Chapter 2
    struct TreeNode* section2_1 = createNode("Section 2.1: Variables and Data Types");
    struct TreeNode* section2_2 = createNode("Section 2.2: Operators");

    struct TreeNode* subsection2_1_1 = createNode("Subsection 2.1.1: Integer and Float");
    struct TreeNode* subsection2_1_2 = createNode("Subsection 2.1.2: Char and Strings");

    addChild(chapter2, section2_1);
    addChild(chapter2, section2_2);

    addChild(section2_1, subsection2_1_1);
    addChild(section2_1, subsection2_1_2);

    // Print the book structure
    printf("Book Structure:\n");
    printTree(book, 0);

    return 0;
}
