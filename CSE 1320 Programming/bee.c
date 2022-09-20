#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct person{

char* month;
int day;
int year;
}PERSON;

void input(PERSON *p, int num)
{
int i;
char* token;
int line_length = 200;
char line[line_length];

fgets(line, line_length, stdin);
token = strtok(line, "\n");



for (i=0;i<num;i+=1)
{
fgets(line, line_length, stdin);

p->month = malloc(30);
token = strtok(NULL, " ");
strcpy(p->month, token);

p->day = atoi(strtok(NULL, ","));

p->year = atoi(strtok(NULL, ",\n"));

p+=1;
}
}

void output(PERSON *p, int num)
{
int i;

for (i=0;i<num;i+=1)
{
printf("Year: %d\n", p->year);
free(p);
p+=1;
}
}

int main(int argc, char** argv)
{
int num;
char* token;
int line_length = 200;
char line[line_length];

fgets(line, line_length, stdin);
token = strtok(line, "\n");
num = atoi(line);

PERSON* people = malloc(sizeof(PERSON)*num);

input(people, num);

output(people, num);

free(people);

return 0;
}
