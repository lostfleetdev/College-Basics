#include <stdio.h>
#define MAX 10

// Structure for the deque
struct Deque {
    int arr[MAX];
    int front;
    int rear;
};

// Function to initialize the deque
void initializeDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

// Function to check if deque is full
int isFull(struct Deque* deque) {
    return ((deque->front == 0 && deque->rear == MAX - 1) || (deque->front == deque->rear + 1));
}

// Function to check if deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->front == -1);
}

// Function to add an element at the front end
void addFront(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }
    
    if (deque->front == -1) { // If deque is initially empty
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX - 1;
    } else {
        deque->front--;
    }
    
    deque->arr[deque->front] = data;
    printf("%d added to front.\n", data);
}

// Function to add an element at the rear end
void addRear(struct Deque* deque, int data) {
    if (isFull(deque)) {
        printf("Deque is full!\n");
        return;
    }
    
    if (deque->front == -1) { // If deque is initially empty
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    
    deque->arr[deque->rear] = data;
    printf("%d added to rear.\n", data);
}

// Function to delete an element from the front end
void deleteFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("%d deleted from front.\n", deque->arr[deque->front]);
    
    if (deque->front == deque->rear) { // Deque has only one element
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->front == MAX - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
}

// Function to delete an element from the rear end
void deleteRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }

    printf("%d deleted from rear.\n", deque->arr[deque->rear]);
    
    if (deque->front == deque->rear) { // Deque has only one element
        deque->front = -1;
        deque->rear = -1;
    } else if (deque->rear == 0) {
        deque->rear = MAX - 1;
    } else {
        deque->rear--;
    }
}

// Function to display the deque
void displayDeque(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty!\n");
        return;
    }
    
    printf("Deque elements: ");
    int i = deque->front;
    while (1) {
        printf("%d ", deque->arr[i]);
        if (i == deque->rear) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function
int main() {
    struct Deque deque;
    initializeDeque(&deque);

    // Adding elements to the deque
    addRear(&deque, 10);
    addRear(&deque, 20);
    addFront(&deque, 5);
    addFront(&deque, 45);
    addFront(&deque, 69);
    addFront(&deque, 2);
    addFront(&deque, 55);
    addFront(&deque, 1);
    addFront(&deque, 52);

    displayDeque(&deque);
    
    // Deleting elements from the deque
    deleteFront(&deque);
    deleteRear(&deque);
    
    displayDeque(&deque);
    
    return 0;
}
