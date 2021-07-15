#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 50

void delay(int sec)
{
    int msec, start_time;
    msec = 1000 * sec;

    start_time = clock();

    while (clock() < (start_time) + (msec));
}

void main()
{
    int input, passDigits, ichar[68], repeat;
    char clpass[5], site[50], username[50];
    time_t t;
    FILE *ptr = NULL;

    // character data starts
    ichar[0] = 33;
    ichar[1] = 35;
    ichar[2] = 36;
    ichar[3] = 37;
    ichar[4] = 38;
    int next = 48;
    for (int i = 5; i < 15; i++)
    {
        ichar[i] = next;
        next++;
    }
    next = 65;
    ichar[15] = 64;
    for (int i = 16; i < 42; i++)
    {
        ichar[i] = next;
        next++;
    }
    next = 97;
    for (int i = 42; i < 68; i++)
    {
        ichar[i] = next;
        next++;
    }
    // character data ends
    system("color a");
    printf("Welcome to 'Crypt Legit'-Your personal Password Manager!\n");
    printf("--------------------------------------------------------\n");
    printf("Enter master password:-");
    gets(clpass);

    if (clpass[0] == 'a' && clpass[1] == 'b' && clpass[2] == 'c' && clpass[3] == 'd' && clpass[4] == 'e')
    {
label:
        printf("\nInput number corresponding to the action & press ENTER:\n\n");
        printf("1.Generate New Password\n2.Access All Passwords\n\nUSER INPUT:");
        scanf("%d", &input);

        if (input == 1)
        {
        	system("CLS");
            printf("\nEnter site name (in small letters): ");
            scanf("%s", &site);
            printf("Enter username: ");
            scanf("%s", &username);
            getchar();
            srand(time(NULL));
            passDigits = rand() % 4 + 9;
            char password[passDigits];

            for (int i = 0; i < passDigits; i++)
            {
                int random = rand() % 68;
                password[i] = ichar[random];
            }
            time(&t);
            printf("Your highly secured password is: ");

            for (int i = 0; i < passDigits; i++)
            {
                printf("%c", password[i]);
            }
            printf("\n");

            ptr = fopen("password_data.txt", "a");

            fprintf(ptr, "\n");
            fprintf(ptr, "%s--------------------\nSite: %s\nUsername: %s\nPassword: ", ctime(&t), site, username);
            for (int i = 0; i < passDigits; i++)
            {
                fputc(password[i], ptr);
            }

            fprintf(ptr, "\n");
            fclose(ptr);
        }

        else if (input == 2)
        {
            printf("\nLoading Passwords....\n");
            delay(2);
            system("CLS");
            ptr = fopen("password_data.txt", "r");
            char string[SIZE];

            while (fgets(string, SIZE, ptr) != 0)
            {
                printf("%s", string);
            }
            fclose(ptr);
        }

        else
        {
            printf("INVALID INPUT!!\n");
        }
    }

    else
    {
        printf("\nWrong Password! Press ENTER to exit....\n");
        goto end;
    }

    printf("\nTo continue using program enter 1, or enter any other number to exit: ");
    scanf("%d", &repeat);

    if (repeat == 1)
    {
        printf("--------------------------------------------------------\n");
        goto label;
    }

    else
    {
        printf("\nThank You!");
    }

end:
    getch();
}