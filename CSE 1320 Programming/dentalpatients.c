#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct patient{




 char* name;

 int** brush_morning_night; //should contain both morning and night brushing-0 means no, 1 means yes

 int dentist_vists;




}PATIENT;


void read_file(char message[], PATIENT* p)
{
FILE* fp = fopen(message, "r");

if(!fp)
{
printf("Error opening file.\n");
}
else
{
int line_len=200;
char line[line_len];
char* token;

while(fgets(line, line_len, fp))
{
token = strtok(line, ",");

p->name = malloc(50);
strcpy(p->name, token);

(p->brush_morning_night) = (int*)malloc(sizeof(int)*2);
token = strtok(NULL, ",");
if (strcmp(token, "yes"))
{
*(p->brush_morning_night[0]) = 1;
}
else if(strcmp(token, "no"))
{
*(p->brush_morning_night[0]) = 0;
}

token = strtok(NULL, ",");
if (strcmp(token, "yes"))
{
*(p->brush_morning_night[1]) = 1;
}
else if(strcmp(token, "no"))
{
*(p->brush_morning_night[1]) = 0;
}

p->dentist_vists = malloc(sizeof(int));
p->dentist_vists = atoi(strtok(NULL, ",\n"));

p+=1;
}
}

fclose(fp);
}



int update_info(PATIENT* p, int num)
{
int i, value = 1;
char input[100];

while(value)
{
printf("Type in name of patient to update:\n");
scanf("%s", input);

for (i=0;i<5;i+=1)
{
if(!strcmp(input, p->name))
{
printf("What are you updating?\n");
printf("1. morning brush\n2. night brush\n3. number of visits\n");
scanf("%s", input);

if(!strcmp(input, "1"))
{
if(*(p->brush_morning_night[0]) == 1)
{
printf("%s currently brushes in the morning. Switching to: does not brush in the morning...\n", p->name);

*(p->brush_morning_night[0]) = 0;
}
else if(*(p->brush_morning_night[0]) == 0)
{
printf("%s currently does not brushes in the morning. Switching to: does brush in the morning...\n", p->name);

*(p->brush_morning_night[0]) = 1;
}
}

if(!strcmp(input, "2"))
{
if(*(p->brush_morning_night[1]) == 1)
{
printf("%s currently brushes at night. Switching to: does not brush at night...\n", p->name);

*(p->brush_morning_night[1]) = 0;
}
else if(*(p->brush_morning_night[1]) == 0)
{
printf("%s currently does not brushes at night. Switching to: does brush at night...\n", p->name);

*(p->brush_morning_night[1]) = 1;
}
}

if(!strcmp(input, "3"))
{
printf("%s currently does %d dental visit(s). Enter new value:\n", p->name, p->dentist_vists);
scanf("%d", &(p->dentist_vists));
}

}

if(!strcmp(input, "exit"))
{
printf("exitting...\n");
free(p);
value = 0;
}
p+=1;
}
}
return value;
}





int main (int argc, char **argv)

{

 PATIENT* all_patients=malloc(sizeof(PATIENT)*5);

 read_file("dentalpatients.txt",all_patients);

 int value=1;




 while(value)

 {
 
 value=update_info(all_patients,5);

 }

}