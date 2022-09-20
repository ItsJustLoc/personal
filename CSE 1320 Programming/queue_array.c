#include <stdio.h>
#include "queue_array.h"

void enqueue(QUEUE* queue)
{
    if (queue->rear == MAX) {
        printf("No more space to enqueue elements...\n");
        return;
    }
    else {
        int value;
        printf("-Enter value to enqueue:\n");
        scanf("%d", &value);

        queue->queue_array[queue->rear] = value;
        queue->rear += 1;
    }
}

void dequeue(QUEUE* queue) {
    if (queue->front == queue->rear) {
        printf("Nothing in queue to dequeue.\n");
        return;
    }
    else {
        printf("Element dequeued from queue is %d\n", queue->queue_array[queue->front]);
        queue->front +=1 ;
    }
}

void display(QUEUE* queue) {
    int i;
    if (queue->rear == 0) {
        printf("Queue is empty\n");
        return;
    }
    else {
        printf("Queue is : \n");
        for (i = queue->front; i < queue->rear; i+=1) {
            printf("%d - ", queue->queue_array[i]);
        }
        printf("\n");
    }
}