#include <stdio.h>
#define MAX 5 // Maximum size of the queue

int queue[MAX];
int front = -1; // Front index of the queue
int rear = -1;  // Rear index of the queue

// Function to check if the queue is empty
int isEmpty() {
    return front == -1; // Returns 1 (true) if empty, otherwise 0 (false)
}

// Function to add an element to the queue (enqueue)
void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0; // Initialize front when first element is added
        }
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

// Function to remove an element from the queue (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! No elements to dequeue\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) { // If the queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front++; // Move front to the next element
        }
        printf("%d dequeued from queue\n", value);
        return value;
    }
}

// Function to get the number of elements in the queue
int count() {
    if (isEmpty()) {
        return 0; // If empty, return 0
    } else {
        return rear - front + 1; // Calculate number of elements
    }
}

// Function to view the front element of the queue (peek)
int peek() {
    if (isEmpty()) {
        printf("Queue is empty, nothing to peek\n");
        return -1;
    } else {
        return queue[front]; // Return the front element
    }
}

// Function to display the elements in the queue
void show() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    // Performing operations on the queue
    enqueue(10);
    enqueue(20);
    enqueue(30);
    show();

    printf("Front element is %d\n", peek());
    printf("Number of elements in the queue: %d\n", count());

    dequeue();
    show();

    enqueue(40);
    enqueue(50);
    enqueue(60); // This will show overflow as the queue size is 5
    show();

    return 0;
}
    