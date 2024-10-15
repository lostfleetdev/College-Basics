#include <stdio.h>
#include <string.h>

// define the student structure
struct Student {
    char name[50];
    int roll_no;
    float sgpa;
};

// function to display the student list
void displayStudents(struct Student students[], int n) {
    printf("roll no\tname\t\tSGPA\n");
    printf("----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%-10s\t%.2f\n", students[i].roll_no, students[i].name, students[i].sgpa);
    }
    printf("\n");
}

// function to sort students by roll number using bubble sort
int bubbleSortByRollNo(struct Student students[], int n) {
    struct Student temp;
    int pass_count = 0;
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0; // flag to check if any swapping occurred in this pass
        pass_count++;
        printf("bubble sort pass %d:\n", pass_count); // display pass number
        for (int j = 0; j < n - 1 - i; j++) {
            if (students[j].roll_no > students[j + 1].roll_no) {
                // swap if out of order
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = 1;
            }
        }
        displayStudents(students, n); // display the list after each pass
        if (!swapped) // if no swapping happened, the array is already sorted
            break;
    }
    return pass_count; // return the number of passes
}

// function to sort students by roll number using insertion sort
int insertionSortByRollNo(struct Student students[], int n) {
    struct Student key;
    int j, pass_count = 0;
    for (int i = 1; i < n; i++) {
        key = students[i];
        j = i - 1;
        pass_count++;

        // move elements that are greater than the key
        printf("insertion sort pass %d:\n", pass_count); // display pass number
        while (j >= 0 && students[j].roll_no > key.roll_no) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
        displayStudents(students, n); // display the list after each pass
    }
    return pass_count; // return the number of passes
}

int main() {
    // initialize the student database
    struct Student students[] = {
        {"Pratik", 4, 8.5}, {"Prem", 2, 9.2}, {"Rohan", 1, 7.8},
        {"Rushi", 3, 8.0}, {"Prince", 7, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 9, 6.5}, {"Palak", 5, 7.9}, {"Rutika", 6, 9.9},
        {"Kaustubh", 8, 9.8}
    };

    int n = sizeof(students) / sizeof(students[0]);

    // display original list
    printf("original student list:\n");
    displayStudents(students, n);

    // sort by roll number using bubble sort and display each pass
    printf("\nsorting by roll number (using bubble sort):\n");
    int bubble_passes = bubbleSortByRollNo(students, n);
    printf("bubble sort completed in %d passes\n", bubble_passes);

    // reset the array for insertion sort
    struct Student students_reset[] = {
        {"Pratik", 4, 8.5}, {"Prem", 2, 9.2}, {"Rohan", 1, 7.8},
        {"Rushi", 3, 8.0}, {"Prince", 7, 7.2}, {"Vedant", 10, 9.0},
        {"Raman", 9, 6.5}, {"Palak", 5, 7.9}, {"Rutika", 6, 9.9},
        {"Kaustubh", 8, 9.8}
    };
    memcpy(students, students_reset, sizeof(students_reset));

    // sort by roll number using insertion sort and display each pass
    printf("\nsorting by roll number (using insertion sort):\n");
    int insertion_passes = insertionSortByRollNo(students, n);
    printf("insertion sort completed in %d passes\n", insertion_passes);

    return 0;
}
