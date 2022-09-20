#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct all_values{ 
  char word[40]; 
  float numbers[1][2]; 
  int** int_dblptr; 
  int* int_ptr; 
};

typedef struct all_values RANDOM;

void fill_in_struct_info(RANDOM *random, int **val_one, int *val_two)
{
    if(*val_one==val_two)
    {
        printf("Enter a word to put at random.word: ");
        scanf("%s", (random[0]).word);
        printf("Enter a float for random.numbers[0][0]: ");
        scanf("%f", &(random[0]).numbers[0][0]);
        printf("Enter a float for random.numbers[0][1]: ");
        scanf("%f", &(random[0]).numbers[0][1]);
        printf("Assigning parameter val_one to random.int_dblptr...\n");
        (random[0]).int_dblptr=val_one;
        printf("Assigning parameter val_two to random.int_ptr...\n");
        (random[0]).int_ptr=val_two;
    }
    else
    {
        printf("Enter a word to put at random.word: ");
        scanf("%s", (random[1]).word);
        printf("Enter a float for random.numbers[0][0]: ");
        scanf("%f", &(random[1]).numbers[0][0]);
        printf("Enter a float for random.numbers[0][1]: ");
        scanf("%f", &(random[1]).numbers[0][1]);
        printf("Assigning parameter val_one to random.int_dblptr...\n");
        (random[1]).int_dblptr=val_one;
        printf("Assigning parameter val_two to random.int_ptr...\n");
        (random[1]).int_ptr=val_two;
    }
}

void print_out_struct_info(random_ptr);
 
int main(int argc, char**argv) 
{ 
   int num=atoi(argv[1]); 
   int* number=&num; 
 
   int num_two=atoi(argv[2]); 
  int* number_two=&num_two; 
 
   RANDOM random_stuff[2]; 
   RANDOM* random_ptr=random_stuff;  
 
   fill_in_struct_info(random_stuff, &number, &num); //fills in first struct element of random_stuff (random_stuff[0]) 
   random_ptr++; 
   fill_in_struct_info(random_ptr, &number_two, &num_two); //fills in second struct element of random_stuff (random_stuff[1])
 
   print_out_struct_info(&random_stuff[0]); //prints out first struct element of random_stuff, at index 0  
   print_out_struct_info(random_ptr); //prints out second struct element of random_stuff, at index 1 
} 