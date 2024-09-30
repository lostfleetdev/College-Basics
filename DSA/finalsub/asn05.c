#include <stdio.h>
#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1; // Top of the stack, initially set to -1 (empty)

// Function to add an element to the stack (Push)
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// Function to remove an element from the stack (Pop)
int pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}

// Function to view the top element of the stack (Peek)
int peek() {
    if (top == -1) {
        printf("Stack is empty, nothing to peek\n");
        return -1;
    } else {
        return stack[top];
    }
}

// Function to display the elements in the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    // Performing basic operations on the stack
    push(10);
    push(20);
    push(30);
    display();
    
    printf("Top element is %d\n", peek());
    
    pop();
    display();
    
    push(40);
    push(50);
    display();

    return 0;
}
