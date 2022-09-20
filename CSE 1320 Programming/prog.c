#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define SIZE 4 
 
typedef struct dessert{ 
   
  char size; 
  float price; 
  char* flavor; 
  int available; 
   
}dessert; 
 
void give_info(dessert *des, int size, char*filename) 
{ 
   
  FILE *fp=fopen(filename,"r"); 
  char *token; 
  char line[40]; 
  int i; 
 
 
  for(i=0;i<size;i++) 
  { 
    fgets(line, 40, fp); 
    token=strtok(line,","); 
    des[i].size=token[0]; 
     
    token=strtok(NULL,","); 
    des[i].price=atof(token); 
     
    token=strtok(NULL,","); 
    des[i].flavor=malloc(30); 
    strcpy(des[i].flavor,token); 
     
    token=strtok(NULL,"\n"); 
    des[i].available=atoi(token); 
  } 
 
  fclose(fp); 
} 
 
void print_report(dessert *d, int size) 
{ 
  int i; 
 
  printf("\nCURRENT INVENTORY:\n"); 
 
  for(i=0;i<size;i++) 
  { 
    printf("***Info for Item %d***\n", (i+1)); 
    printf("Size: %c\n", (*d).size); 
    printf("Price: %.2f\n", (*d).price); 
    printf("Flavor: %s\n", (*d).flavor); 
    printf("Flavor, first letter: %c\n", *((*d).flavor)); 
    printf("Availiblity: %d\n\n", (*d).available); 
    d++; 
  } 
 
} 
 
int main (int argc, char **argv) 
{ 
  int num=atoi(argv[1]); 
   
  dessert *des=malloc(sizeof(dessert)*num);

    //char * ptr=argv[2]; 
  //printf("%lu %lu\n", sizeof(des), sizeof(dessert));
   
  if(!des) 
  { 
    printf("Error getting you some memory!  Bye.\n"); 
  } 
   
  else 
  { 
    give_info(des, num, argv[2]); 
    print_report(des, num); 
  } 
   
  free(des); 
   
} 