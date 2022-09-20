#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ALL_DAYS 7

int read_file(int val[][6], char *filename);
void run_lotto(char *day, int todays_nums[]);

int main(int argc, char **argv)
{
    int lotto_nums[ALL_DAYS][6];
    int status=0, counter=0;
    char* days[]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    char **days_ptr=days;
    int (*lotto_ptr)[6]=lotto_nums;

    status=read_file(lotto_nums, argv[1]);

    if(status)
    {
        while (counter<ALL_DAYS)
        {
            printf("\nSee today's lotto numbers? Enter 1 for yes, 2 for no: ");
            scanf("%d", &status);

            if(status==1)
            {
                run_lotto(*days_ptr, *lotto_ptr);
                days_ptr++;
                lotto_ptr++;
                counter++;
            }
            else
            {
                counter=10;
            }
        }   
    }

    printf("\nExiting program...\n");

}

int read_file(int val[][6], char *filename)
{
    FILE* fp;
    char* mode="r";
    int status;
    fp=fopen(filename, mode);

    if(!fp)
    {
        printf("No file found.\n");
        status=0;
    }
    else
    {
        status=1;
        int i=0, j=0;
        int current, previous=0;
        char line[100];
        char* token;

        while(!feof(fp))
        {
            fgets(line,100,fp);
            token=strtok(line, ",");

            while(token)
            {
                val[j][i]=atoi(token);
                token=strtok(NULL, ",\n");
                i++;
            }
            i=0;
            j++;
        }
        fclose(fp);
    }

    return status;
}

void run_lotto(char *day, int todays_nums[])
{
    int i;
    printf("\n--Today is: %s!!!!\n", day);
    printf("For your chance to win **5 billion dollars**,lotto numers are: ");

    for(i=0;i<6;i++)
    {
        printf("%d ", todays_nums[i]);
    }

    printf("\n");

}