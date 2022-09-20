#include <stdio.h>
#include <stdlib.h>
#include "queue_linked_list.h"

#define MAX 10

int main(int argc, char** argv) {
    queue* q;
    q->front=NULL;
    q->rear=NULL;
    
    enqueue(q,	10);
    enqueue(q,	20);
    enqueue(q,	30);
    enqueue(q,	40);
    printf("%d	dequeued	from	the	queue\n",	dequeue(q));
    printf("%d	dequeued	from	the	queue\n",	dequeue(q));
    peek(q);

    enqueue(q, 50);
    peek(q);

    return 0;
}