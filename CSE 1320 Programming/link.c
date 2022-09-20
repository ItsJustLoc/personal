#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
typedef struct node 
{ 
  int number; 
  struct node *next; 
}node; 
 
/*create a node. When head is NULL (meaning we’re creating the first node), notice that temp->next is equal 
to NULL (meaning the first node is created)*/ 
node* addNode(node* head, int n) 
{ 
  node *temp = malloc(sizeof(node)); 
  temp->number = n; 
  temp->next = head; 
  return temp; 
} 
int main(void) 
{ 
  node *head = NULL, *temp;  
  int i; 
 
  for(i = 0; i < 3; i++) 
  { 
    head = addNode(head, i); 
  } 
 
  while(head != NULL) 
  { 
    printf("freeing: %d\n", head->number); 
    temp = head->next; 
    free( head ); 
    head = temp; 
  } 
} 