#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* rear;
} queue;

void enqueue(queue* q, int data);
int dequeue(queue* q);
void peek(queue* q);

#endif