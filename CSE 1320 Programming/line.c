#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int find_filename(int n, char **b) 
{ 
  int i; 
  int counter=0; /*equals -1 if didnt find*/ 
  int check=0; 
   
  for(i=0;i<n&&!check;i++) 
  { 
    if(!strcmp(*b, "filename")) 
    { 
      check=1; 
    }
    counter++; 
    b++; 
  }
  if(check!=1) 
  { 
    counter=0; 
  }
  return (counter-1);  
}

int main(int argc, char** argv)
{
  char line[100];
  char *mode = "r";
  int n=find_filename(argc, argv);

  if(n>0)
  {
    FILE *fp = fopen(argv[n+1], mode);
        
    if(!fp)
    {
      printf("Cannot open file\n");
      return -1;
    }

    else
    {
      printf("Filename: %s\n", argv[n+1]);
      printf("We're dealing with %s info.\n", argv[n+2]);
      printf("\nContent of the file:\n");
    }

    while(fgets(line,100,fp))
    {
      printf("%s", line);
    }
  }

  else if(n<=0)
  {
    printf("No filename given. Bye!\n");
  }

  return 0;
}

