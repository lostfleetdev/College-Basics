#include<stdio.h> 
#include<stdlib.h>  // Use stdlib.h instead of malloc.h for dynamic memory allocation

// Define a structure for the node
struct node {
    int data;
    struct node* left; 
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node *n;
    n = (struct node*) malloc(sizeof(struct node)); // memory allocation
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Preorder traversal: Root -> Left -> Right
void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder traversal: Left -> Right -> Root
void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    } 
}

// Inorder traversal: Left -> Root -> Right
void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    } 
}

int main() {
    // creating nodes
    struct node *p = createNode(2); 
    struct node *p1 = createNode(4); 
    struct node *p2 = createNode(6); 
    struct node *p3 = createNode(8); 
    struct node *p4 = createNode(1);

    // nodes in a tree
    p->left = p1;
    p->right = p2; 
    p1->left = p3; 
    p1->right = p4;

    // traversals
    printf("Preorder: ");
    preOrder(p); 
    printf("\n");

    printf("Postorder: ");
    postOrder(p); 
    printf("\n");

    printf("Inorder: ");
    inOrder(p); 
    printf("\n");

    return 0;
}