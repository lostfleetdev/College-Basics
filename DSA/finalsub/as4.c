#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 50
#define TABLE_SIZE 10

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float sgpa;
};

struct Student database[MAX_STUDENTS];
struct Student* hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hash(char* name) {
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        sum += name[i];
    }
    return sum % TABLE_SIZE;
}

void insertIntoHashTable(struct Student* student) {
    int index = hash(student->name);
    while (hashTable[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = student;
}

void bubbleSort(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].rollNumber > arr[j + 1].rollNumber) {
                struct Student temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

struct Student* searchByName(char* name) {
    int index = hash(name);
    int startIndex = index;
    
    do {
        if (hashTable[index] != NULL && strcmp(hashTable[index]->name, name) == 0) {
            return hashTable[index];
        }
        index = (index + 1) % TABLE_SIZE;
    } while (index != startIndex);
    
    return NULL;
}

struct Student* searchBySGPA(float sgpa) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (database[i].sgpa == sgpa) {
            return &database[i];
        }
    }
    return NULL;
}

int main() {
    initializeHashTable();

   struct Student database[MAX_STUDENTS]= {
        {"Pratik", 41, 8.5}, {"Prem", 31, 9.2}, {"Rohan", 57, 7.8},
        {"Rushi", 50, 8.0}, {"Prince", 44, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 49, 6.5}, {"Palak", 43, 7.9}, {"Kaustubh",6, 8.5}, {"Kaustubh",5,9.8}
    }; 

    bubbleSort(database, MAX_STUDENTS);

    printf("\nSorted Roll Call List:\n");
    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("%d. Roll Number: %d, Name: %s, SGPA: %.2f\n", i + 1, database[i].rollNumber, database[i].name, database[i].sgpa);
    }

    char searchName[MAX_NAME_LENGTH];
    printf("\nEnter a name to search: ");
    scanf("%s", searchName);
    struct Student* foundByName = searchByName(searchName);
    if (foundByName) {
        printf("Student found - Roll Number: %d, Name: %s, SGPA: %.2f\n", foundByName->rollNumber, foundByName->name, foundByName->sgpa);
    } else {
        printf("Student not found.\n");
    }

    float searchSGPA;
    printf("\nEnter SGPA to search: ");
    scanf("%f", &searchSGPA);
    struct Student* foundBySGPA = searchBySGPA(searchSGPA);
    if (foundBySGPA) {
        printf("Student found - Roll Number: %d, Name: %s, SGPA: %.2f\n", foundBySGPA->rollNumber, foundBySGPA->name, foundBySGPA->sgpa);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}