#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Function to find the number of nodes in the longest path
int findLongestPath(struct Node* root) {
    if (root == NULL) return 0;
    int leftDepth = findLongestPath(root->left);
    int rightDepth = findLongestPath(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Function to find the minimum value in the tree
int findMinValue(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty\n");
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

// Function to swap left and right pointers at every node
void swapPointers(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    swapPointers(root->left);
    swapPointers(root->right);
}

// Function to search for a value in the tree
struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) return root;
    
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

// Function to print the tree in-order (for testing)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to read input and construct the initial BST
struct Node* constructInitialBST() {
    struct Node* root = NULL;
    char input[1000];
    char* token;
    int value;

    printf("Enter the values to insert into the BST (separated by spaces or new lines):\n");
    printf("Ctrl+Z followed by Enter to finish input.\n");

    while (fgets(input, sizeof(input), stdin) != NULL) {
        token = strtok(input, " \n");
        while (token != NULL) {
            value = atoi(token);
            root = insert(root, value);
            token = strtok(NULL, " \n");
        }
    }

    return root;
}

int main() {
    struct Node* root = constructInitialBST();
    int choice, value;

    while (1) {
        printf("\n1. Insert a node");
        printf("\n2. Find number of nodes in longest path");
        printf("\n3. Find minimum value");
        printf("\n4. Swap left and right pointers");
        printf("\n5. Search a value");
        printf("\n6. Print the tree (in-order)");
        printf("\n7. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Number of nodes in longest path: %d\n", findLongestPath(root));
                break;
            case 3:
                printf("Minimum value: %d\n", findMinValue(root));
                break;
            case 4:
                swapPointers(root);
                printf("Pointers swapped\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL)
                    printf("Value found in the tree\n");
                else
                    printf("Value not found in the tree\n");
                break;
            case 6:
                printf("Tree (in-order): ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}