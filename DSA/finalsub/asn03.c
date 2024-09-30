#include <stdio.h>

// Structure for singly linked list node
struct SinglyNode {
    int data;
    struct SinglyNode* next; // Pointer to the next node
};

// Structure for doubly linked list node
struct DoublyNode {
    int data;
    struct DoublyNode* prev; // Pointer to the previous node
    struct DoublyNode* next; // Pointer to the next node
};

// Function to print the singly linked list
void printSinglyList(struct SinglyNode* head) {
    struct SinglyNode* current = head;
    printf("Singly Linked List: \n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}

// Function to print the doubly linked list
void printDoublyList(struct DoublyNode* head) {
    struct DoublyNode* current = head;
    printf("Doubly Linked List: \n");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next; // Move to the next node
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes for singly linked list
    struct SinglyNode node1, node2, node3;
    node1.data = 10;  // First node data
    node1.next = &node2; // Point to next node
    node2.data = 20;  // Second node data
    node2.next = &node3; // Point to next node
    node3.data = 30;  // Third node data
    node3.next = NULL; // End of list

    // Creating nodes for doubly linked list
    struct DoublyNode dnode1, dnode2, dnode3;
    dnode1.data = 100;  // First node data
    dnode1.prev = NULL; // First node has no previous
    dnode1.next = &dnode2; // Point to next node
    dnode2.data = 200;  // Second node data
    dnode2.prev = &dnode1; // Point to previous node
    dnode2.next = &dnode3; // Point to next node
    dnode3.data = 300;  // Third node data
    dnode3.prev = &dnode2; // Point to previous node
    dnode3.next = NULL; // End of list

    // Print singly linked list
    printSinglyList(&node1);

    // Print doubly linked list
    printDoublyList(&dnode1);

    return 0;
}
