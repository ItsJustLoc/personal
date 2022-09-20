/*#include <stdio.h> 
#include <string.h> 
 
typedef struct irish{ 
 
  char irish_name[20]; 
  char pick; 
  char english_equiv[20]; 
 
 
}irish; 
 
int read_file(int nums, irish names[]); 
void find_name(char* name, char *lang, int size, irish *names);
 
int main (int argc, char **argv) { 
 
  irish names[13]; 
  char n[10]; 
  char lang[10]; 
  int s=sizeof(names)/sizeof(names[0]); 
  int result=read_file(s, names); 
 
  if(result)
  { 
     printf("Enter name to look for and the language it is in: "); 
    scanf("%s %s", n, lang); 
 
    find_name(n, lang, s, names); 
  } 
 
   return 0; 
} 
 
int read_file(int nums, irish names[]) 
{ 
  char filename[20]; 
  printf("Enter the file name:\n"); 
  scanf("%s", filename); 
 
  FILE *fp=fopen(filename, "r+"); 
 
  if(fp!=NULL) 
  { 
    char line[50]; 
    int i=0; 
    char *token; 
 
    while(i<nums) 
    { 
      fgets(line, 50, fp); 
      token=strtok(line, ","); 
      strcpy(names[i].irish_name, token); 
      token=strtok(NULL, ",\n"); 
      names[i].pick=token[0]; 
      token=strtok(NULL, ",\n"); 
      strcpy(names[i].english_equiv, token); 
      i++; 
    } 
 
    printf("Info successfully read from file.\n"); 
        fclose(fp); 
        return 1; 
  } 
  else 
  { 
    printf("File didnt open. Exiting...\n"); 
        return 0; 
  } 
 
} 
 
void find_name(char* name, char *lang, int size, irish *names) 
{ 
  int i; 
  int index; 
 
  if(!strcmp(lang, "Irish")) 
  { 
    for(i=0;i<size;i++) 
    { 
      if(!strcmp((*names).irish_name, name)) 
      { 
        printf("Found a match!\n");         
        printf("The English equivalent for %s is %s.\n", name, names->english_equiv);
        break; 
      } 
      names++; 
    } 
  } 
 
  else
  { 
    for(i=0;i<size;i++) 
    { 
      if(!strcmp(names->english_equiv, name)) 
      { 
        printf("Found a match!\n");         
        printf("The Irish equivalent for %s is %s.\n", name, (*names).irish_name);
        break; 
      } 
 
      names++; 
    } 
  } 
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char iname[20];
    char pick;
    char ename[20];
}irish;

int rfile(int nums, irish names[]);
void fname(char* name, char* lang, int size, irish* names);

int main(int argc, char** argv)
{
    irish names[13];
    char n[10];
    char lang[10];
    int s = sizeof(names)/sizeof(names[0]);
    int result=rfile(s, names);

    if(result)
    {
        printf("Enter name and language it is in: ");
        scanf("%s %s", n, lang);

        fname(n, lang, s, names);
    }
}

int rfile(int nums, irish names[])
{
    char fn[20];
    printf("Enter file name:\n");
    scanf("%s", fn);

    FILE *fp=fopen(fn, "r+");

    if(fp)
    {
        char line[100];
        int i = 0;
        char* token;

        while(i<nums)
        {
            fgets(line, 100, fp);
            token=strtok(line,",");
            strcpy(names[i].iname,token);
            token=strtok(NULL,",\n");
            names[i].pick=token[0];
            token=strtok(NULL,",\n");
            strcpy(names[i].ename,token);
            i+=1;
        }

        printf("Info has been read.\n");
        fclose(fp);
        return 1;
    }
    else
    {
        printf("SRY file didn't open\n");
        return 0;
    }
}

void fname(char* name, char* lang, int size, irish* names)
{
    int i;
    int index;

    if(!strcasecmp(lang, "Irish"))
    {
        for (i=0;i<size;i+=1)
        {
            if(!strcmp((*names).iname,name))
            {
                printf("Found a match!\n");
                printf("The English equivalent for %s, is %s.\n", name, names->ename);
            }
            names+=1;
        }
    }
    else
    {
        for(i=0;i<size;i++) 
            { 
                if(!strcmp(names->ename, name)) 
                { 
                    printf("Found a match!\n");
                    printf("The Irish equivalent for %s is %s.\n", name, (*names).iname);
                    break; 
                }
 
                names++;
            }
    } 

}