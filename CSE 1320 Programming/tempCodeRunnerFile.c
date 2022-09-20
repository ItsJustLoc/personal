//please read comments!! instructions for question unclear.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "airport.h" //<-in the .c file different from airport.h and airport.c



/*typedef struct ticket_info{

    char* terminal;

    int gate;

    struct ticket_info* next;




}ticket_info;

ticket_info* read_file(char* filename, int num);
ticket_info* createNode(char* line);
void state_terminal(ticket_info* ti);
void free_linked_list(ticket_info* head);
^^should be in airport.h file*/

/*int main (int argc, char** argv) {


     ticket_info* all_tickets=read_file(argv[1], 4);
     state_terminal(all_tickets);

     free_linked_list(all_tickets);
}
^^should be in the .c file different from airport.h and airport.c*/

ticket_info* read_file(char* filename, int num) {

     int i, STR_LEN = 200;
    char* token;
    char line[STR_LEN];

     FILE* fp = fopen(filename, "r+");
     if (!fp) {
          printf("Error accessing file.\n");
          return;
     }

     printf("Retrieving info for %d tickets...\n", num);

     ticket_info* head;
     ticket_info* tail;
     tail = head;

     ticket_info* current;

     while (fgets(line, sizeof(line), fp)) {
          current = createNode(line);
          tail = current;
          tail->next = current;
     }


     fclose(fp);
     return head;
}

//^^in airport.c file

ticket_info* createNode(char* line) {
     char* token;
     ticket_info* tmp = malloc(sizeof(ticket_info));
     if (tmp == NULL) {
          printf("malloc error.\n");
          return;
     }
     
     token = strtok(line, ",");
     tmp->terminal = malloc(sizeof(token)+1);
     strcpy(tmp->terminal, token);
     
     token = strtok(NULL, "\n");
     tmp->gate = atoi(token);

     return tmp;
}

//^^in airport.c file

void state_terminal (ticket_info* ti) {
     ticket_info* cursor;
     cursor = ti;

     while (cursor) {
          if (terminal[0] == 'A' || terminal[0] == 'B')) {
               printf("Please go to terminal %c, gate %d.\n", cursor->terminal[0], cursor->gate);
          }
          else {
               printf("Please take the train to the other side of the airport.\n");
          }
          
          cursor = cursor->next;

     }
}

//^^in airport.c file

void free_linked_list(ticket_info* head) {
    ticket_info* cursor;
    ticket_info* last_visited = NULL;
    cursor = head;

    while (cursor) {
        if(last_visited) {
            free(last_visited);
        }
        
        free(cursor->terminal);
        last_visited = cursor->next;
    }

    free(cursor);
    free(head);
}

//^^in airport.c file