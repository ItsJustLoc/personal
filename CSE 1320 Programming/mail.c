#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mailbox{
  char first_name[20];
  char last_name[20];
  int apt_num;
  char all_mail[2][400];
  int pieces_of_mail;
}MAILBOX;

int set_info(char* arg, MAILBOX* mail);
int deliver_mail(char* arg, MAILBOX* mail, int num_tenet);
void exit_program(char* arg, MAILBOX* mail, int num_tenet);

int main(int argc, char** argv)
{
  MAILBOX all_residents[5];

  if(set_info(argv[1], all_residents))
  {
    int mail_info=deliver_mail(argv[2], all_residents, 5);
      
    if (!mail_info)
    {
      printf("\nAll mail was successfully delivered!\n");
    }
    else
    {
      printf("\nSome mailboxes were full, number of undelivered letters: %d\n", mail_info);
    }

    int check = 1;
    int lol, i, j;
    char input[100];

    while (check)
    {
      printf("\nEnter resident's last name or apt numer: ");
      fgets(input, sizeof(input), stdin);
      strtok(input, "\n");
      lol = atoi(input);

        for (i=0;i<5;i+=1)
        {
          if ((!strcmp(input, (all_residents[i].last_name))) || (lol == all_residents[i].apt_num))
          {
            printf("%s %s, resident in apt %d, has %d letter(s):\n", (all_residents[i].first_name), (all_residents[i].last_name), (all_residents[i].apt_num), (all_residents[i].pieces_of_mail));
            
            for (j=0;j<all_residents[i].pieces_of_mail;j+=1)
            {
              printf("%d.%s\n", (j+1), (all_residents[i].all_mail[j]));
            }
          }
          else if (!strcmp(input, "exit"))
          {
            check = 0;
          }
        }
    }

    exit_program(argv[3], all_residents, 5);
  }
}

int set_info(char* arg, MAILBOX* mail)
{
  int i, len = 400;
  char line[len];

  FILE* fp = fopen(arg, "r+");

  if(!fp)
  {
    printf("\nError opening file try again.\n");
    return 0;
  }
  else
  {
    printf("\nReading all residents info from %s...\n", arg);

    while (fgets(line, sizeof(line), fp))
    {
      strcpy(mail->first_name, strtok(line, " "));

      strcpy(mail->last_name, strtok(NULL, ","));

      strtok(NULL, " ");
      mail->apt_num = atoi(strtok(NULL, ","));

      mail->pieces_of_mail = atoi(strtok(NULL, "\n"));

      printf("Creating mailbox for %s %s in apt %d. Currently has %d letter(s).\n", (mail->first_name), (mail->last_name), (mail->apt_num), (mail->pieces_of_mail));

      mail += 1;
    }

    printf("All mailboxes created!\n\n");
    printf("************\n\n");
    fclose(fp);
  }

  return 1;
}

int deliver_mail(char* arg, MAILBOX* mail, int num_tenet)
{
  int i, lol, undelivered = 0, len = 400;
  char line[len];
  char* token,* token_two;

  FILE* fp = fopen(arg, "r+");

  if(!fp)
  {
    printf("Error opening file try again.\n");
    return 0;
  }
  else
  {
    printf("~~Delivering mail...\n");

    while(fgets(line, sizeof(line), fp))
    {
      token = strtok(line, ":");
      lol = atoi(token);

        for (i=0;i<num_tenet;i+=1)
        {
            if ((!strcmp(token, (mail[i].last_name))) || (lol == mail[i].apt_num))
            {
                token_two = strtok(NULL, "\n");
                if(!lol)
                {
                    printf("Delivering to %s:%s\n", token, token_two);
                }
                else if(lol)
                {
                    printf("Delivering to %d:%s\n", lol, token_two);
                }

                if (mail[i].pieces_of_mail < 2)
                {
                    strcpy(mail[i].all_mail[mail[i].pieces_of_mail], token_two);
                    mail[i].pieces_of_mail += 1;

                    if(mail[i].pieces_of_mail == 2)
                    {
                        printf("%d currently has %d letter(s). Mailbox is now full.\n\n", mail[i].apt_num, mail[i].pieces_of_mail);
                    }
                    else
                    {
                        printf("%d currently has %d letter(s).\n\n", mail[i].apt_num, mail[i].pieces_of_mail);
                    }
                }
                else
                {
                    undelivered += 1;
                    printf("Sorry, mailbox is full. %d undelivered letter(s)\n\n", undelivered);
                }
            }
        }
    }

    fclose(fp);
  }

  printf("************\n");
  return undelivered;
}

void exit_program(char* arg, MAILBOX* mail, int num_tenet)
{
  int i;
  FILE* fp = fopen(arg, "w+");

  printf("\nExiting program...mail report being saved into file %s...\n", arg);

  for (i=0;i<num_tenet;i+=1)
  {
    fprintf(fp, "%s, %s: %d\n", (mail[i].last_name), (mail[i].first_name), (mail[i].pieces_of_mail));
  }

  fclose(fp);
}