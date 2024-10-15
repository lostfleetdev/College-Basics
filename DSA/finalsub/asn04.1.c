#include <stdio.h>
#include <string.h>

#define SIZE 9  // Size of the student database

// Structure for student information
struct Student {
    char name[50];
    int roll_no;
    float sgpa;
};

// Function to perform binary search on the array of students based on SGPA
int binarySearch(struct Student students[], int size, float targetSGPA) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the target SGPA is found at mid index
        if (students[mid].sgpa == targetSGPA) {
            return mid;  // Return the index of the student
        }

        // If the target SGPA is smaller than mid SGPA, move to the left half
        if (students[mid].sgpa > targetSGPA) {
            right = mid - 1;
        }
        // If the target SGPA is larger than mid SGPA, move to the right half
        else {
            left = mid + 1;
        }
    }

    return -1;  // Return -1 if student is not found
}

// Function to display student information
void displayStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("SGPA: %.2f\n", s.sgpa);
}

void displayTable(struct Student stud[]){
    printf("Roll No\tName\t\tSGPA\n");
    printf("----------------------------\n");
    for (size_t i = 0; i < SIZE; i++){
        printf("%d\t%-10s\t%.2f\n", stud[i].roll_no, stud[i].name, stud[i].sgpa);
    }
}

int main() {
    struct Student students[SIZE] = {
        {"Pratik", 4, 8.5}, {"Prem", 2, 9.2}, {"Rohan", 1, 7.8},
        {"Rushi", 3, 8.0}, {"Prince", 7, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 9, 6.5}, {"Palak", 6, 7.9}, {"Rutika", 8, 9.9}
    };

    displayTable(students);
    // Sorting students by SGPA using bubble sort (for binary search to work)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (students[j].sgpa > students[j + 1].sgpa) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    // Ask user for SGPA to search
    float targetSGPA;
    printf("Enter the SGPA to search for: ");
    scanf("%f", &targetSGPA);

    // Perform binary search
    int index = binarySearch(students, SIZE, targetSGPA);

    if (index != -1) {
        printf("Student found at index %d:\n", index);
        displayStudent(students[index]);
    } else {
        printf("Student with SGPA %.2f not found.\n", targetSGPA);
    }

    return 0;
}
