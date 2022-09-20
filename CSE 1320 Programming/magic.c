#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check_tickets_valid(int* all_tickets, int* max_ticket, int** size_of_tickets);
int find_magic_number(int* all_tickets, int* num_valid_tickets, int** size_of_tickets);

int main(int argc, char **argv) 
{ 
    char text[20];
  int max_ticket_number=atoi(argv[1]); 
  int ticket_numbers[5]={120,625,345,700,300};   
  int size_tickets=5; 
  int* ptr_size=&size_tickets; 
 
  int total_valid=check_tickets_valid(ticket_numbers, &max_ticket_number, &ptr_size); 
  printf("Total valid tickets: %d\n\n", total_valid); 
  int* ptr_total=&total_valid; 
 
  if (1<total_valid) 
  { 
    int magic_number=find_magic_number(ticket_numbers, ptr_total, &ptr_size); 
    printf("Magic number is: %d\n", magic_number); 

    FILE *fp = fopen("magic.txt", "w");

    if(!fp)
    {
        printf("Couldn't create file sorry.\n");
    }
    else
    {
        printf("Writing to file magic.txt...\n");
        fprintf(fp,"***magic number: %d", magic_number);

        fclose(fp);
    }
  }
    return 0;
}

int check_tickets_valid(int* all_tickets, int* max_ticket, int** size_of_tickets)
{
    int i;
    int counter = 0;

    for(i=0;i<**size_of_tickets;i++)
    {
        if(all_tickets[i] < *max_ticket)
        {
            printf("Ticket number %d is welcome!\n", all_tickets[i]);
            counter++;
        }
        else
        {
            printf("Ticket %d: You are not allowed in the show Please leave.\n", all_tickets[i]);
            all_tickets[i] = 0;
        }
    }

    return counter;
}

int find_magic_number(int* all_tickets, int* num_valid_tickets, int** size_of_tickets)
{
    int i;
    int max = 0;

    for(i=0;i<**size_of_tickets;i++)
    {
        (all_tickets[i] > max) ? (max = all_tickets[i]) : (max = max); 
    }

    return (max % *num_valid_tickets);
}