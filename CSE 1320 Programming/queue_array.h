#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#define MAX 3

typedef struct queue {
    int queue_array[MAX];
    int front;
    int rear;
} QUEUE;

void enqueue(QUEUE* queue);
void dequeue(QUEUE* queue);
void display(QUEUE* queue);

#endif