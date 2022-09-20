#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*typedef struct cookie{ 
  char message[100]; 
  int lucky_nums[6];   
}fortune_cookie; 
 
 
void fill_cookies(fortune_cookie*f) 
{ 
  char line[500]; 
  int i,j; 
  char *token; 
   
 
  fgets(line, 500, stdin); 
  token=strtok(line, ","); 
   
  for(i=0;i<2;i++) 
  { 
    token=strtok(NULL, ","); 
    strcpy(f[i].message,token); 
    for(j=0;j<6;j++) 
    { 
      token=strtok(NULL, ",\n"); 
      f[i].lucky_nums[j]=atoi(token); 
    } 
  }   
} 
 
void cookie_info(fortune_cookie*f, int num) 
{ 
  printf("message: %s\n",f[num].message);
  int i;
  printf("Lucky nums are:\n");
  for(i=0;i<6;i++)
  { 
    printf("%d\n", f[num].lucky_nums[i]);
  } 
} 
 
int main (int argc, char **argv) 
{ 
  fortune_cookie f1[2];
  fill_cookies(f1);
  cookie_info(f1, 0);
}*/

typedef struct{
    char mess[100];
    int luckNums[6];
}cookies;

void fill(cookies* f)
{
    char line[500];
    int i,j;
    char* token;

    fgets(line, 500, stdin);
    token = strtok(line,",");

    for(i=0;i<2;i+=1)
    {
        token=strtok(NULL,",");
        strcpy(f[i].mess,token);

        for(j=0;j<6;j+=1)
        {
            token=strtok(NULL,",\n");
            f[i].luckNums[j]=atoi(token);
        }
    }
}

void info(cookies* f, int num)
{
    printf("Message: %s\n", f[num].mess);
    int i;
    printf("Lucky Numbers are: \n");
    for(i=0;i<6;i+=1)
    {
        printf("%d\n", f[num].luckNums[i]);
    }
}

int main(int argc, char** argv)
{
    cookies f1[2];
    cookies* f = f1;

    fill(f);
    for(int i=0;i<2;i+=1)
    {
        info(f,i);
    }
}