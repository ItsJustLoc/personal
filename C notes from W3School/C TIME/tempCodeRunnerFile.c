#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int read_file(char filename[], char all_penguins_mood[][20], int penguin_count[]); 

void penguin_report(char filename[], char all_penguins_mood[][20], int penguin_count);


int main (int argc, char **argv)

{

  int i, total_penguins=0;

  char moods[3][20];

  int counts[3];

  int file=read_file(argv[1], moods, counts);




  if(file)

  {
    for(i=0;i<3;i++)
      {
            total_penguins+=counts[i]; //note that this could also be written as: total_penguins=total_penguisn+counts[i];

    }




penguin_report(argv[2], moods, total_penguins);

  }




  else

  {

    printf("File didn't open...exiting\n");

  }




}




int read_file(char filename[], char all_penguins_mood[][20], int penguin_count[])

{
  char line[40];
int i; 
File *fp=fopen(filename,"r");

  if(!fp)
{
  return 0;
}

else
{
  while(fgets(line, 40, fp)
{
fgets(line, 40,fp)
strtok("\n");


fscanf("%s %d %s %d %s %d", all_penguin_mood[0], &penguin_count[0], all_penguin_mood[1], &penguin_count[1], all_penguin_mood[2], &penguin_count[2]);
 
}
fclose(fp);
return 1;
}

}

void penguin_report(char filename[], char all_penguins_mood[][20], int penguin_count)


{
int i;
File *fp=(filename,"w");

fprintf("*** %d Penguins!***\n", penguin_count);
fprintf("-Moods: %s, %s and %s!", all_penguin_mood[0], all_penguin_mood[1], all_penguin_mood[2]);

fclose(fp);

}