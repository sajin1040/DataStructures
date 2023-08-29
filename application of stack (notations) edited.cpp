#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %d.\n", value);
    } else {
        stack->items[++stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1; // Return a sentinel value
    } else {
        return stack->items[stack->top--];
    }
}

// Function to evaluate an expression in postfix notation
int evaluatePostfix(char* expression) {
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isspace(c)) {
            continue; // Ignore spaces
        }

        if (isdigit(c)) {
            push(&stack, c - '0'); // Convert char to int
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Operator encountered, make sure there are at least 2 operands
            if (isEmpty(&stack) || stack.top < 1) {
                printf("Error: Not enough operands for operator %c.\n", c);
                return -1;
            }

            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (c) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        push(&stack, operand1 / operand2);
                    } else {
                        printf("Error: Division by zero.\n");
                        return -1;
                    }
                    break;
            }
        } else {
            printf("Invalid character: %c\n", c);
            return -1;
        }
    }

    if (!isEmpty(&stack) && stack.top == 0) {
        return stack.items[stack.top]; // Result is on top of the stack
    } else {
        printf("Error: Invalid expression.\n");
        return -1;
    }
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    
    if (result != -1) {
        printf("Result: %d\n", result);
    }

    return 0;
}

