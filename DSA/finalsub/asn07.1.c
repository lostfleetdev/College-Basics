#include <stdio.h>
#include <stdlib.h>

// Definition of a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary tree
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Use a simple rule to insert: Left for smaller, Right for larger
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Recursive Inorder Traversal (Left, Root, Right)
void inorderRecursive(struct Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

// Recursive Preorder Traversal (Root, Left, Right)
void preorderRecursive(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

// Recursive Postorder Traversal (Left, Right, Root)
void postorderRecursive(struct Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

// Non-recursive Inorder Traversal using Stack
void inorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;  // Push current node onto stack
            curr = curr->left;    // Move to the left child
        }
        curr = stack[top--];      // Pop the node from stack
        printf("%d ", curr->data);
        curr = curr->right;       // Move to the right child
    }
}

// Non-recursive Preorder Traversal using Stack
void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) stack[++top] = node->right;
        if (node->left != NULL) stack[++top] = node->left;
    }
}

// Non-recursive Postorder Traversal using Two Stacks
void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 != -1) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) stack1[++top1] = node->left;
        if (node->right != NULL) stack1[++top1] = node->right;
    }

    while (top2 != -1) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

// Main function
int main() {
    struct Node* root = NULL;
    int value;

    printf("Enter values to insert into the binary tree (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == -1) break;
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal (Recursive): ");
    inorderRecursive(root);

    printf("\nPreorder Traversal (Recursive): ");
    preorderRecursive(root);

    printf("\nPostorder Traversal (Recursive): ");
    postorderRecursive(root);

    printf("\nInorder Traversal (Non-Recursive): ");
    inorderNonRecursive(root);

    printf("\nPreorder Traversal (Non-Recursive): ");
    preorderNonRecursive(root);

    printf("\nPostorder Traversal (Non-Recursive): ");
    postorderNonRecursive(root);

    return 0;
}
