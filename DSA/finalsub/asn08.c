#include <stdio.h>
#include <stdlib.h>

// Define a structure for the node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    struct Node* temp = NULL;
    int value;
    char choice;

    // Input for root node
    printf("Enter the value of the root node: ");
    scanf("%d", &value);
    root = createNode(value);

    // Loop to insert nodes
    do {
        printf("Enter the value to insert: ");
        scanf("%d", &value);
        temp = root;

        while (1) {
            if (value < temp->data) {
                if (temp->left == NULL) {
                    temp->left = createNode(value);
                    break;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->right == NULL) {
                    temp->right = createNode(value);
                    break;
                } else {
                    temp = temp->right;
                }
            }
        }

        printf("Do you want to insert another value (y/n)? ");
        scanf(" %c", &choice); 
    } while (choice == 'y');

    // Display in-order traversal
    printf("In-order traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0; 
}
