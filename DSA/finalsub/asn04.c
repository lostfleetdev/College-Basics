#include <stdio.h>
#include <string.h>

#define SIZE 10

// Structure to hold student data
struct Student {
    char name[50];
    int roll_no;
    float sgpa;
};

// Function to display the student database
void display(struct Student students[], int size) {
    printf("Roll No\tName\t\tSGPA\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t%-10s\t%.2f\n", students[i].roll_no, students[i].name, students[i].sgpa);
    }
}

// Bubble sort to arrange students by roll number in ascending order
void sortByRoll(struct Student students[], int size) {
    struct Student temp;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(students[j].roll_no > students[j + 1].roll_no) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Hash function for simple search by SGPA (modular hash)
int hashBySGPA(float sgpa) {
    return (int)(sgpa * 10) % SIZE; // Simple hash using SGPA
}

// Search by name
int searchByName(struct Student students[], int size, char* name) {
    for(int i = 0; i < size; i++) {
        if(strcmp(students[i].name, name) == 0) {
            return i; // Return the index if found
        }
    }
    return -1; // Not found
}

// Search by SGPA using hashing
int searchBySGPA(struct Student students[], float sgpa) {
    int index = hashBySGPA(sgpa);
    for(int i = 0; i < SIZE; i++) {
        if(students[i].sgpa == sgpa) {
            return i; // Return index if found
        }
    }
    return -1; // Not found
}

int main() {
    // Student database
    struct Student students[SIZE] = {
        {"Pratik", 41, 8.5}, {"Prem", 31, 9.2}, {"Rohan", 57, 7.8},
        {"Rushi", 50, 8.0}, {"Prince", 44, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 49, 6.5}, {"Palak", 43, 7.9}, {"Kaustubh",6, 8.5}, {"Kaustubh",5,9.8}
    };

    printf("Original Student Database:\n");
    display(students, SIZE);
    
    // Sort by roll number
    sortByRoll(students, SIZE);
    printf("\nSorted by Roll Number:\n");
    display(students, SIZE);
    
    // Search for a student by name
    char search_name[50];
    printf("\nEnter the name of the student to search: ");
    scanf("%s", search_name);
    int index = searchByName(students, SIZE, search_name);
    if(index != -1) {
        printf("Student Found: %s with SGPA: %.2f\n", students[index].name, students[index].sgpa);
    } else {
        printf("Student not found.\n");
    }

    // Search for a student by SGPA
    float search_sgpa;
    printf("\nEnter the SGPA of the student to search: ");
    scanf("%f", &search_sgpa);
    index = searchBySGPA(students, search_sgpa);
    if(index != -1) {
        printf("Student Found: %s with Roll No: %d\n", students[index].name, students[index].roll_no);
    } else {
        printf("Student not found.\n");
    }

    return 0;
}