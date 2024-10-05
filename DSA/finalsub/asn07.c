#include <stdio.h>
#include <stdlib.h>

// Define a structure for the binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node in the binary tree
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Recursive Inorder Traversal (Left, Root, Right)
void inorderRecursive(struct Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

// Recursive Preorder Traversal (Root, Left, Right)
void preorderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

// Recursive Postorder Traversal (Left, Right, Root)
void postorderRecursive(struct Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// Non-Recursive Inorder Traversal
void inorderNonRecursive(struct Node* root) {
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Non-Recursive Preorder Traversal
void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* current = stack[top--];
        printf("%d ", current->data);

        if (current->right != NULL) stack[++top] = current->right;
        if (current->left != NULL) stack[++top] = current->left;
    }
}

// Non-Recursive Postorder Traversal
void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;

    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if (current->left != NULL) stack1[++top1] = current->left;
        if (current->right != NULL) stack1[++top1] = current->right;
    }

    while (top2 != -1) {
        printf("%d ", stack2[top2--]->data);
    }
}

int main() {
    // Creating a simple binary tree:
    //         1
    //       /   \
    //      2     3
    //     / \   / \
    //    4   5 6   7

    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Recursive Inorder: ");
    inorderRecursive(root);
    printf("\nNon-Recursive Inorder: ");
    inorderNonRecursive(root);
    
    printf("\n\nRecursive Preorder: ");
    preorderRecursive(root);
    printf("\nNon-Recursive Preorder: ");
    preorderNonRecursive(root);
    
    printf("\n\nRecursive Postorder: ");
    postorderRecursive(root);
    printf("\nNon-Recursive Postorder: ");
    postorderNonRecursive(root);

    return 0;
}
