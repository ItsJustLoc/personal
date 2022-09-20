#include <stdio.h>
#include <stdlib.h>
#include "queue_linked_list.h"

void enqueue(queue* q, int data) {
    node* queue_node = malloc(sizeof(node));
    if (queue_node == NULL) {
        printf("Error saving data");
        return;
    }

    queue_node->data = data;
    queue_node->next = NULL;

    if (q->front == NULL) {
        q->front = queue_node;
        q->rear = queue_node;
    }
    else {
        q->front->next = queue_node;
        q->rear->next = queue_node;
        q->rear = queue_node;
    }

    printf("%d enqueued to queue.\n", data);
}

int dequeue(queue* q) {
    if (q->front) {
        int value = q->front->data;
        node* tmp = q->front;
        q->front = q->front->next;
        return value;
    }
    else {
        printf("Queue is empty...\n");
        return -1;
    }
}

void peek(queue* q) {
    printf("front of the queue: %d,", q->front->data);
    printf("Readr of the queue: %d\n", q->rear->data);
}