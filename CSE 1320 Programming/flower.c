#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
  char name[40];
  int subs;
  float ppm;
}PHONE_PLAN;

int read_file_plans(char filename[], PHONE_PLAN* plan_ptr)
{
  int i;
  char line[100];
  char* token;
  FILE* fp = fopen(filename, "r+");

  if(fp)
  {
     for (i=0;i<4;i+=1)
     {
        fgets(line, 100, fp);
        token = strtok(line, ",");
        strcpy((plan_ptr)[i].name, token);
        token = strtok(NULL, "-\n");
        (plan_ptr)[i].subs = atoi(token);
        token = strtok(NULL, "\n");
        (plan_ptr)[i].ppm = atof(token);
     }
     fclose(fp);
      return 1;
  }
  else
  {
     printf("Sorry File didn't open\n");
     return 0;
  }
}

void all_members(PHONE_PLAN* all_plans, int num)
{
  int i;
  char input[20];
  int true = 1;

  while(true)
  {
     printf("Enter plan to add a member to (exit to quit):");
     scanf("%s", input);

     for(i=0;i<num;i+=1)
     {
       if(!strcmp(input, (all_plans)[i].name))
       {
          all_plans[i].subs += 1;
          printf("Ok, adding a member to this plan (%s). Total members: %d\n", (all_plans)[i].name, (all_plans)[i].subs);

          printf("Amount made from plan so far: $%.2f\n", (((all_plans)[i].ppm) * ((all_plans)[i].subs)));
       }
     }
    
     if(!strcmp(input, "exit"))
     {
        printf("Exiting...\n");
        true = 0;
     }
  }
}



int main(int argc, char**argv)

{

 PHONE_PLAN all_plans[4];

 PHONE_PLAN* plan_ptr=all_plans;




 if(read_file_plans("all_plans.txt", plan_ptr))//this should read the plan info from the file (each line in the file is a different plan) into the four structs

 {

 all_members(all_plans, 4);//this should produce the rest of the sample run (continuously prompting for a plan to add members to until user says exit)

 }

}