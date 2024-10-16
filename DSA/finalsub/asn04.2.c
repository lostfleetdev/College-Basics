#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10  // Size of the hash table

// Structure to store student data
struct Student {
    int rollNo;
    char name[20];
    float sgpa;
    struct Student* next; // For handling collisions
};

// Hash table (array of pointers to Student)
struct Student* hashTable[TABLE_SIZE];

// Hash function: returns index based on roll number
int hashFunction(int rollNo) {
    return rollNo % TABLE_SIZE; // Simple mod-based hash function
}

// Function to insert student data into the hash table
void insertStudent(int rollNo, const char* name, float sgpa) {
    int index = hashFunction(rollNo);  // Get the index from hash function
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->sgpa = sgpa;
    newStudent->next = NULL;

    // Collision handling: chaining method
    if (hashTable[index] == NULL) {
        hashTable[index] = newStudent;
    } else {
        struct Student* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;  // Add at the end of the linked list
    }
}

// Function to search a student by roll number
struct Student* searchStudent(int rollNo) {
    int index = hashFunction(rollNo);  // Get the index from hash function
    struct Student* temp = hashTable[index];

    // Traverse the linked list to find the student
    while (temp != NULL) {
        if (temp->rollNo == rollNo) {
            return temp;  // Student found
        }
        temp = temp->next;
    }
    return NULL;  // Student not found
}

// Function to display the hash table
void displayHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Student* temp = hashTable[i];
        while (temp != NULL) {
            printf("Roll No: %d, Name: %s, SGPA: %.2f -> ", temp->rollNo, temp->name, temp->sgpa);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main function
int main() {
    // Initialize hash table to NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    // Insert student data
    insertStudent(4, "Pratik", 8.50);
    insertStudent(2, "Prem", 9.20);
    insertStudent(1, "Rohan", 7.80);
    insertStudent(3, "Rushi", 8.00);
    insertStudent(7, "Prince", 7.20);
    insertStudent(10, "Vedant", 9.00);
    insertStudent(9, "Raman", 6.50);
    insertStudent(6, "Palak", 7.90);
    insertStudent(8, "Rutika", 9.90);

    // Display the hash table
    printf("Hash Table:\n");
    displayHashTable();

    // Search for a student by roll number
    int rollNo;
    printf("\nEnter roll number to search: ");
    scanf("%d", &rollNo);
    struct Student* student = searchStudent(rollNo);

    if (student != NULL) {
        printf("Student found: Roll No: %d, Name: %s, SGPA: %.2f\n", student->rollNo, student->name, student->sgpa);
    } else {
        printf("Student with roll number %d not found.\n", rollNo);
    }

    return 0;
}
