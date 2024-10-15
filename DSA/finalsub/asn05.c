#include <stdio.h>
#define MAX 5 // maximum size of the stack

int stack[MAX];
int top = -1; // top of the stack, initially set to -1 (empty)

// function to add an element to the stack (push)
void push(int value) {
    if (top == MAX - 1) {
        printf("stack overflow! cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed to stack\n", value);
    }
}

// function to remove an element from the stack (pop)
int pop() {
    if (top == -1) {
        printf("stack underflow! no elements to pop\n");
        return -1;
    } else {
        int value = stack[top];
        top--;
        printf("%d popped from stack\n", value);
        return value;
    }
}

// function to view the top element of the stack (peek)
int peek() {
    if (top == -1) {
        printf("stack is empty, nothing to peek\n");
        return -1;
    } else {
        return stack[top];
    }
}

// function to display the elements in the stack
void display() {
    if (top == -1) {
        printf("stack is empty\n");
    } else {
        printf("stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    // display the menu continuously until the user chooses to exit
    while (1) {
        printf("\nstack operations menu:\n");
        printf("1. push\n2. pop\n3. peek\n4. display\n5. exit\n");
        printf("enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // push operation
                printf("enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            
            case 2: // pop operation
                pop();
                break;
            
            case 3: // peek operation
                value = peek();
                if (value != -1) {
                    printf("top element is %d\n", value);
                }
                break;
            
            case 4: // display operation
                display();
                break;
            
            case 5: // exit
                printf("exiting...\n");
                return 0;
            
            default: // invalid choice
                printf("invalid choice! please select a valid option\n");
        }
    }

    return 0;
}
