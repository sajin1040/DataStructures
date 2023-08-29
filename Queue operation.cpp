#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Queue 
{
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue *q) 
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) 
{
    return (q->front == -1 && q->rear == -1);
}

int isFull(struct Queue *q) 
{
    return (q->rear == MAX_SIZE - 1);
}

void enqueue(struct Queue *q, int value) 
{
    if (isFull(q)) 
	{
        printf("Queue is full. Cannot enqueue.\n");
    } 
	else 
	{
        if (isEmpty(q)) 
		{
            q->front = q->rear = 0;
        } 
		else 
		{
            q->rear++;
        }
        q->items[q->rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

int dequeue(struct Queue *q) 
{
    int dequeuedItem = -1;
    if (isEmpty(q)) 
	{
        printf("Queue is empty. Cannot dequeue.\n");
    } 
	else 
	{
        dequeuedItem = q->items[q->front];
        if (q->front == q->rear) 
		{
            q->front = q->rear = -1;
        } 
		else 
		{
            q->front++;
        }
        printf("%d dequeued from the queue.\n", dequeuedItem);
    }
    return dequeuedItem;
}

void display(struct Queue *q) 
{
    if (isEmpty(q)) 
	{
        printf("Queue is empty.\n");
    } 
	else 
	{
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) 
		{
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() 
{
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    display(&q);

    return 0;
}

