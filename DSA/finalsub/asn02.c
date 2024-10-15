#include <stdio.h>
#include <string.h>

// Define the Student structure
struct Student {
    char name[50];
    int roll_no;
    float sgpa;
};

// Function to sort students by roll number using Bubble Sort
void sortByRollNo(struct Student students[], int n) {
    struct Student temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

// Function to sort students by name using Insertion Sort
void sortByName(struct Student students[], int n) {
    struct Student key;
    int j;
    for (int i = 1; i < n; i++) {
        key = students[i];
        j = i - 1;

        // Move elements that are greater than the key to one position ahead
        while (j >= 0 && strcmp(students[j].name, key.name) > 0) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
    }
}

// Function to display the student list
void displayStudents(struct Student students[], int n) {
    printf("Roll No\tName\t\tSGPA\n");
    printf("----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%.2f\n", students[i].roll_no, students[i].name, students[i].sgpa);
    }
}

int main() {
    // Initialize the student database
    struct Student students[] = {
        {"Pratik", 4, 8.5}, {"Prem", 2, 9.2}, {"Rohan", 1, 7.8},
        {"Rushi", 3, 8.0}, {"Prince", 7, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 9, 6.5}, {"Palak", 5, 7.9}, {"Rutika", 6, 9.9}
    };

    int n = sizeof(students) / sizeof(students[0]);

    // Display original list
    printf("Original Student List:\n");
    displayStudents(students, n);

    // Sort by Roll Number using Bubble Sort and display
    sortByRollNo(students, n);
    printf("\nSorted by Roll Number (Using Bubble Sort):\n");
    displayStudents(students, n);

    // Sort by Name using Insertion Sort and display
    sortByName(students, n);
    printf("\nSorted by Name (Using Insertion Sort):\n");
    displayStudents(students, n);

    return 0;
}
