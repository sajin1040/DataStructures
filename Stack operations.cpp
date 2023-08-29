#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack 
{
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) 
{
    stack->top = -1;
}

int isEmpty(struct Stack* stack) 
{
    return stack->top == -1;
}

int isFull(struct Stack* stack) 
{
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) 
{
    if (isFull(stack)) 
	{
        printf("Stack overflow. Cannot push %d.\n", value);
    } 
	else 
	{
        stack->items[++stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

int pop(struct Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    } 
	else 
	{
        int popped = stack->items[stack->top--];
        return popped;
    }
}

int peek(struct Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    } 
	else 
	{
        return stack->items[stack->top];
    }
}

int main() 
{
    struct Stack stack;
    initialize(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element of the stack: %d\n", peek(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    printf("Top element of the stack: %d\n", peek(&stack));

    return 0;
}
