#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node
struct SinglyNode {
    int data;
    struct SinglyNode* next;
};

// Doubly Linked List Node
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

// Function to insert at the end of a Singly Linked List
void insertSingly(struct SinglyNode** head, int data) {
    struct SinglyNode* newNode = (struct SinglyNode*)malloc(sizeof(struct SinglyNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;  // First node
    } else {
        struct SinglyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;  // Append at the end
    }
}

// Function to display a Singly Linked List
void displaySingly(struct SinglyNode* head) {
    struct SinglyNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" --> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert at the end of a Doubly Linked List
void insertDoubly(struct DoublyNode** head, int data) {
    struct DoublyNode* newNode = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;  // First node
    } else {
        struct DoublyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;  // Link back to the previous node
    }
}

// Function to display a Doubly Linked List
void displayDoubly(struct DoublyNode* head) {
    struct DoublyNode* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <--> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Singly Linked List Example
    struct SinglyNode* singlyHead = NULL;
    insertSingly(&singlyHead, 1);
    insertSingly(&singlyHead, 8);
    insertSingly(&singlyHead, 7);
    insertSingly(&singlyHead, 52);
    insertSingly(&singlyHead, 69);

    printf("Singly Linked List: ");
    displaySingly(singlyHead);

    // Doubly Linked List Example
    struct DoublyNode* doublyHead = NULL;
    insertDoubly(&doublyHead, 8);
    insertDoubly(&doublyHead, 7);
    insertDoubly(&doublyHead, 45);
    insertDoubly(&doublyHead, 69);
    insertDoubly(&doublyHead, 3);

    printf("Doubly Linked List: ");
    displayDoubly(doublyHead);

    return 0;
}
