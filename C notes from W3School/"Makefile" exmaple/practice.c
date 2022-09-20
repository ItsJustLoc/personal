#include <stdio.h> 
#include <stdlib.h> 
#include "queue_array.h" 
 
int main(int argc, char** argv) 
{ 
    QUEUE* queue=malloc(sizeof(QUEUE)); 
 
    if(queue) 
    { 
        queue->front=0; 
        queue->rear=0; 
        int value=1; 
 
        while(value!=4) 
        { 
            printf("***\n"); 
            printf("1. Enqueue\n"); 
            printf("2. Dequeue\n"); 
            printf("3. Display\n"); 
            printf("4. Quit \n"); 
            scanf("%d", &value); 
 
            if(value==1) 
            { 
                enqueue(queue);  
            } 
 
            else if(value==2) 
            { 
                dequeue(queue); 
            } 
 
            else if(value==3) 
            { 
                display(queue); 
            } 
 
            else if(value==4) 
            { 
                printf("Exiting...\n"); 
            } 
 
            else 
            { 
                printf("Unknown response...\n"); 
            } 
 
            if(queue->front==queue->rear) 
            { 
                queue->front=0; 
                queue->rear=0; 
            } 
        } 
 
        free(queue); 
    } 
     
} 