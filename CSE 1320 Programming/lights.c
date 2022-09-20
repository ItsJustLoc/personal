#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct Node{ 
  char * color;
  int ** details;
  struct Node* next; 
}Node;

Node* addNode(Node* head, )

Node* light_info(char *filename);

int main(int argc, char** argv)
{

}

Node* light_info(char *filename)
{
    
}*/

/*typedef struct Node
{
    char* name;
    char* phone_num;
    char* city;
    struct Node* next;
}Node;

Node* poulate_list()
{
    FILE* fp = fopen("callcenter.txt", "r");

    char* token;
    char* line = malloc(100);
    Node* head = NULL;
    Node* temp = NULL;
    
    while (fgets(line, sizeof(line), fp))
    {
        token = strtok(line, ",");
        temp = malloc(sizeof(Node));
        temp->name=malloc(sizeof(token)+1);
        strcpy(temp->name, token);

        token = strtok(NULL, ",");
        temp->phone_num=malloc(sizeof(token)+1);
        strcpy(temp->phone_num, token);

        temp->city = malloc(20);

        if (atoi(token) == 817)
        {
            strcpy(temp->city, "Fort Worth");
        }
        else if (atoi(token)==214)
        {
            strcpy(temp->city, "Dallas");
        }
        else
        {
            strcpy(temp->city, "Grand Prairie");
        }

        temp->next = head;
        head = temp;
    }

    free (line);
    return head;
}

Node* pick_next(Node* list, char* city_name)
{
    while (list)
    {
        if (!strcmp(list->city, city_name))
        {
            return list;
        }
        list = list->next;
    }

    return NULL;
}

Node* completed(Node* current, char* name)
{
    Node* temp = NULL;
    Node* head = current;

    if (!current)
    {
        return current;
    }

    if (!strcmp(current->name, name))
    {
        printf("Call completed!\n");
        temp = current;
        current = current->next;
        free(temp);
        return current;
    }

    current = current->next;

    while (current)
    {
        if (!strcmp(name, current->name))
        {
            temp->next=current->next;
            free(current);
            printf("Call completed!\n");
            break;
        }

        temp = current;
        current = current->next;
    }

    return head;
}

void show_list(Node* head)
{
    printf("\n--Current list--\n");
    while (head)
    {
        printf("%s \n", head->name);
        head=head->next;
    }
}

int main(int argc, char** argv)
{
    Node* call_wait=poulate_list();
    char* answer=malloc(20);
    Node* cur=call_wait;
    char c = 'a';
    int minutes = 0, total = 0;

    printf("\nCall center loading...session started.");
    show_list(call_wait);
    printf("\nWhich city are we taking callers from?\n");
    strtok(answer, "\n");

    while (cur)
    {
        cur=pick_next(call_wait, answer); 
        if (cur)
        {
            printf("\n--Now on the line: %s\n", cur->name);

            while (c!='d')
            {
                minutes+=1;
                printf("Minutes: %d\n", minutes);
                scanf(" %c", &c);
            }

            call_wait=completed(call_wait, cur->name);
            c='a';
            total+=1;
        }
    }

    printf("\nTotal time (in minutes) spent for callers from %s: %d\n", answer, total);
    show_list(call_wait);
    printf("Ending session...\n");
}

*/
typedef struct Node 
{ 
    char *name; 
    char* phone_num; 
    char *city; 
    struct Node *next; 
}Node; 
 
Node* populate_list() 
{ 
   FILE *fp=fopen("callcenter.txt", "r"); 
 
   char *token; 
   char *line=malloc(100); 
   struct Node *head = NULL; 
   struct Node *temp=NULL; 
 
    while(fgets(line, 100,fp)) 
    { 
      token=strtok(line, ","); 
      temp = malloc(sizeof(Node)); 
      temp->name=malloc(20); 
      strcpy(temp->name,token); 
      token=strtok(NULL, ","); 
      temp->phone_num=malloc(20); 
      strcpy(temp->phone_num, token);  
 
      temp->city=malloc(20); 
      if(atoi(token)==817)  /*will go up to the -, get the first 3 nums */ 
      { 
          strcpy(temp->city,"Fort Worth"); 
      } 
 
      else if(atoi(token)==214) 
      { 
          strcpy(temp->city,"Dallas"); 
      } 
 
      else 
      { 
          strcpy(temp->city,"Grand Prairie"); 
      } 
 
      temp->next=head; 
      head=temp; 
 
    //How the items will look out: 
    //printf("pPhone number:%s, city: %s, %d\n", temp->phone_num,temp->city, atoi(token)); 
    //Phone number:817-966-7771 
    //, city: Fort Worth, 817 
    } 
 
    free (line); 
    return head; 
} 
 
Node* pick_next(Node*list, char*city_name) 
{ 
  while(list) 
  { 
    if(!strcmp(list->city, city_name)) 
    { 
      return list; 
    } 
     list=list->next; 
  } 
  return NULL; /*we can't find anyone from that city*/ 
} 
 
Node *completed(Node *current, char *name) 
{ 
  Node* temp=NULL; 
  Node* head=current; 
     
  if(!current) /*handle empty list, current==NULL */ 
  { 
    return current; 
  } 
   
  if(!strcmp(current->name, name)) /*handle case that node to delete is the first one in the list*/ 
  { 
      printf("Call completed!\n"); 
      temp=current; /*save original head of list...to delete*/ 
      current=current->next; /*new head of list is the next one*/ 
      free(temp); 
      return current; 
  } 
 
  current=current->next; //set to second node (since we know first is not the name) 
 
  while(current) 
  { 
    if(!strcmp(name, current->name)) /*found node to delete*/ 
    { 
      temp->next=current->next; 
      free(current); 
      printf("Call completed!\n"); 
      break; 
    } 
      temp=current; //hold on to previous during next round 
      current=current->next; 
  } 
  return head; 
} 
 
void show_list(Node* head) 
{ 
  printf("\n--Current list--\n"); 
  while(head) 
  { 
    printf("%s  \n", head->name); 
    head=head->next; 
  } 
} 
 
int main(int argc, char **argv) 
{ 
  Node* call_wait=populate_list(); 
  char *answer=malloc(20); 
  Node* cur=call_wait; 
  char c='a'; 
  int minutes=0, total=0; /*starting minutes, total, loop*/ 
 
  printf("\nCall center loading...session started."); 
  show_list(call_wait); 
  printf("\nWhich city are we taking callers from?\n"); 
  fgets(answer,20,stdin); 
  strtok(answer,"\n"); 
 
  while(cur) 
  { 
      cur=pick_next(call_wait, answer); 
      if(cur) /*no more callers from this city*/ 
      { 
        printf("\n--Now on the line: %s\n", cur->name); 
 
        while(c!='d') 
        { 
          minutes++; 
          printf("Minutes: %d\n", minutes); 
          scanf(" %c", &c); 
        } 
 
        call_wait=completed(call_wait, cur->name); /*you could have deleted node directly in the 
pick_next function*/ 
        c='a'; 
        total++; 
      } 
  } 
 
  printf("\nTotal time (in minutes) spent for callers from %s: %d\n", answer,total); 
  show_list(call_wait); 
  printf("Ending session...\n"); 
}