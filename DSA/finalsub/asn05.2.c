#include <stdio.h>
#include <ctype.h> // For isalnum()
#include <string.h> // For string manipulation functions

#define MAX 100 // Maximum stack size

// Stack structure
struct Stack {
    char arr[MAX]; // Array to hold stack elements
    int top; // Index of the top element
};

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = -1; // Stack is initially empty
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1; // Check if the stack is full
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1; // Check if the stack is empty
}

// Function to push an element onto the stack
void push(struct Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %c\n", value);
    } else {
        stack->arr[++(stack->top)] = value; // Increment top and add value
    }
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return '\0'; // Return null character if stack is empty
    } else {
        return stack->arr[(stack->top)--]; // Return top value and decrement top
    }
}

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Return null character if stack is empty
    } else {
        return stack->arr[stack->top]; // Return top value
    }
}

// Function to check if parentheses are balanced
int areParenthesesBalanced(const char* expression) {
    struct Stack stack;
    initStack(&stack); // Initialize the stack

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == '(') {
            push(&stack, '('); // Push '(' onto the stack
        } else if (expression[i] == ')') {
            if (isEmpty(&stack)) {
                return 0; // Unbalanced if stack is empty
            }
            pop(&stack); // Pop from stack for ')'
        }
    }
    return isEmpty(&stack); // Return true if stack is empty (balanced)
}

// Function to get the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // For non-operators
}

// Function to convert infix expression to postfix
void infixToPostfix(const char* expression, char* postfix) {
    struct Stack stack;
    initStack(&stack); // Initialize the stack
    int j = 0; // Index for postfix

    for (int i = 0; expression[i] != '\0'; i++) {
        char ch = expression[i];

        // If character is an operand (letter or number), add it to postfix
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } 
        // If character is '(', push it onto the stack
        else if (ch == '(') {
            push(&stack, ch);
        } 
        // If character is ')', pop operators until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack); // Remove '(' from stack
        } 
        // If character is an operator
        else {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch); // Push the current operator onto the stack
        }
    }

    // Pop all remaining operators from the stack
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char expression[MAX];
    char postfix[MAX];

    // Input the infix expression
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Remove trailing newline

    // Check for balanced parentheses
    if (areParenthesesBalanced(expression)) {
        printf("The parentheses are balanced.\n");
    } else {
        printf("The parentheses are unbalanced.\n");
        return 1; // Exit if parentheses are unbalanced
    }

    // Convert infix to postfix
    infixToPostfix(expression, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
