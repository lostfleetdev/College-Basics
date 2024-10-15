#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5      // Maximum number of jobs in the queue
#define MAX_LEN 20 // Maximum length of each job ID string

char queue[MAX][MAX_LEN]; // 2D array to hold the job queue (job IDs as strings)
int front = -1, rear = -1; // Front and rear pointers for the queue

// Function to add a job to the queue
void addJob() {
    if (rear == MAX - 1) {
        printf("Queue is full. Cannot add more jobs.\n");
        return;
    }
    char job[MAX_LEN];
    printf("Enter job ID to add: ");
    scanf("%s", job);
    
    if (front == -1) {
        front = 0; // Set front to 0 if the queue is initially empty
    }
    rear++;
    strcpy(queue[rear], job); // Copy job ID to the queue
    printf("Job '%s' added successfully!\n", job);
}

// Function to delete a job from the queue
void deleteJob() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. No job to delete.\n");
        return;
    }
    printf("Job '%s' deleted from the queue.\n", queue[front]);
    front++;
    
    // If all jobs are deleted, reset the queue
    if (front > rear) {
        front = rear = -1;
    }
}

// Function to display the jobs in the queue
void displayJobs() {
    if (front == -1) {
        printf("Queue is empty. No jobs to display.\n");
        return;
    }
    printf("Jobs in the queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int choice;
    
    while (1) {
        printf("\nJob Queue Menu:\n");
        printf("1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addJob();
                break;
            case 2:
                deleteJob();
                break;
            case 3:
                displayJobs();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
