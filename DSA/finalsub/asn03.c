#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for singly linked list node (for club members)
struct SinglyNode {
    int reg_no; //registration number
    char name[50];
    struct SinglyNode* next; // Pointer to the next node
};

// Structure for doubly linked list node (for club members with previous pointer)
struct DoublyNode {
    int reg_no; // MIS registration number
    char name[50];
    struct DoublyNode* prev; // Pointer to the previous node
    struct DoublyNode* next; // Pointer to the next node
};

// Function to add a member at the end of the singly linked list
void addMemberSingly(struct SinglyNode** head, int reg_no, char* name) {
    struct SinglyNode* new_member = (struct SinglyNode*)malloc(sizeof(struct SinglyNode));
    new_member->reg_no = reg_no;
    strcpy(new_member->name, name);
    new_member->next = NULL;

    if (*head == NULL) {
        *head = new_member;
    } else {
        struct SinglyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_member;
    }
}

// Function to delete a member from the singly linked list
void deleteMemberSingly(struct SinglyNode** head, int reg_no) {
    struct SinglyNode* temp = *head;
    struct SinglyNode* prev = NULL;

    // If the member to be deleted is the head
    if (temp != NULL && temp->reg_no == reg_no) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the member to delete
    while (temp != NULL && temp->reg_no != reg_no) {
        prev = temp;
        temp = temp->next;
    }

    // If member not found
    if (temp == NULL) {
        printf("Member not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Function to count total number of members in the singly linked list
int countMembersSingly(struct SinglyNode* head) {
    int count = 0;
    struct SinglyNode* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display the singly linked list members
void displayMembersSingly(struct SinglyNode* head) {
    struct SinglyNode* temp = head;
    printf("Members List (Singly Linked):\n");
    while (temp != NULL) {
        printf("Reg No: %d, Name: %s\n", temp->reg_no, temp->name);
        temp = temp->next;
    }
}

// Recursive function to display the singly linked list in reverse order
void displayReverseSingly(struct SinglyNode* head) {
    if (head == NULL) return;
    displayReverseSingly(head->next);
    printf("Reg No: %d, Name: %s\n", head->reg_no, head->name);
}

// Function to concatenate two singly linked lists
void concatenateSingly(struct SinglyNode** head1, struct SinglyNode* head2) {
    if (*head1 == NULL) {
        *head1 = head2;
    } else {
        struct SinglyNode* temp = *head1;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head2;
    }
}

// Function to add a member in the doubly linked list
void addMemberDoubly(struct DoublyNode** head, int reg_no, char* name) {
    struct DoublyNode* new_member = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    new_member->reg_no = reg_no;
    strcpy(new_member->name, name);
    new_member->prev = NULL;
    new_member->next = NULL;

    if (*head == NULL) {
        *head = new_member;
    } else {
        struct DoublyNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_member;
        new_member->prev = temp;
    }
}

// Function to display the doubly linked list members
void displayMembersDoubly(struct DoublyNode* head) {
    struct DoublyNode* temp = head;
    printf("Members List (Doubly Linked):\n");
    while (temp != NULL) {
        printf("Reg No: %d, Name: %s\n", temp->reg_no, temp->name);
        temp = temp->next;
    }
}

// Main function to test the implementation
int main() {
    struct SinglyNode* clubSinglyHead = NULL;
    struct DoublyNode* clubDoublyHead = NULL;

    // Add president and secretary in both singly and doubly linked lists
    addMemberSingly(&clubSinglyHead, 1, "President");
    addMemberSingly(&clubSinglyHead, 2, "Secretary");

    addMemberDoubly(&clubDoublyHead, 1, "President");
    addMemberDoubly(&clubDoublyHead, 2, "Secretary");

    // Add some club members
    addMemberSingly(&clubSinglyHead, 3, "Rutika");
    addMemberSingly(&clubSinglyHead, 4, "Rohan");

    addMemberDoubly(&clubDoublyHead, 3, "Rutika");
    addMemberDoubly(&clubDoublyHead, 4, "Rohan");

    // Display members in singly linked list
    displayMembersSingly(clubSinglyHead);

    // Display members in doubly linked list
    displayMembersDoubly(clubDoublyHead);

    // Display reverse order using recursion
    printf("\nDisplaying Members in Reverse Order (Singly Linked List):\n");
    displayReverseSingly(clubSinglyHead);

    // Delete a member
    deleteMemberSingly(&clubSinglyHead, 3); 
    // deleteMemberDoubly(&clubDoublyHead, 3); 

    // Display after deletion
    printf("\nAfter Deletion (Singly Linked List):\n");
    displayMembersSingly(clubSinglyHead);

    // Concatenate two lists
    struct SinglyNode* clubSinglyHead2 = NULL;
    addMemberSingly(&clubSinglyHead2, 5, "Palak");
    addMemberSingly(&clubSinglyHead2, 6, "Prem");
    concatenateSingly(&clubSinglyHead, clubSinglyHead2);

    // Display concatenated list
    printf("\nAfter Concatenating Two Lists (Singly Linked List):\n");
    displayMembersSingly(clubSinglyHead);

    return 0;
}
