#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

void showLoading();
int registration_driver();

typedef struct
{
    char name[50];
    char address[50];
    int age;
    long long int phone_no;
    long long int account_no;
    char password[15];
    int amount;
} Account;

Account account[100];

void loaddata()
{
    FILE *file = fopen("file.csv", "r");
    int i = 0;
    while (fscanf(file, "%[^,],%[^,],%d,%lld,%lld,%[^,],%d\n", &account[i].name, &account[i].address, &account[i].age, &account[i].phone_no, &account[i].account_no, &account[i].password, &account[i].amount) == 7)
    {
        i++;
        continue;
    }
}

int registration_driver()
{
    int count = 0, n = 1, age, i, input, check, paisa, rows, ask;
    long long int mn;
    char names[50], add[50], pass[15], ch;
    int Account_number;
    FILE *file;
    

    long long int min = pow(10, 8);
    long long int max = pow(10, 9) - 1;

    
    printf("                                               WELCOME TO SAMRIDDHI BANK\n\n");
start:
    printf("What would you like to do?\n1. Register new account.\n2. Login into an existing account.\n");

    printf("Your choice: ");

    scanf("%d", &input);

    switch (input)

    {
    case 1:
        file = fopen("file.csv", "a");
        if (file == NULL)
        {
            printf("Error opening the file.\n");
            return 1;
        }


        for (int i = 0; i < n; i++)
        {
            getchar(); // To consume the newline character left by the previous scanf
            printf("\nPlease enter your name: ");
            fgets(names, sizeof(names), stdin);
            names[strcspn(names, "\n")] = '\0'; // Remove the trailing newline
            strcpy(account[i].name, names);

            printf("Please enter your city: ");
            fgets(add, sizeof(add), stdin);
            add[strcspn(add, "\n")] = '\0';
            strcpy(account[i].address, add);

            printf("Please enter your age in years: ");
        age:
            scanf("%d", &age);
            if (age >= 18 && age <= 130)
            {
                account[i].age = age;
            }
            else if (age < 18 && age > 0)
            {
                printf("\n You are under 18 years of age and are not eligible to get a bank account.");
                return 1;
            }
            else
            {
                printf("Invalid input!\n Please enter a valid age: ");
                goto age;
            }

            printf("Enter your Phone number: ");
        mobo:
            scanf("%lld", &mn);
            account[i].phone_no = mn;
            if (mn < 6 * pow(10, 9) || mn >= pow(10, 10))
            {
                printf("Invalid moible number! \nEnter your mobile number again: ");
                goto mobo;
            }

            srand(time(NULL));
            Account_number = rand() % (max - min + 1) + min;
            account[i].account_no = Account_number;
            fflush(stdin);
            printf("Input a password(Between 6 - 12 characters): ");
            fgets(pass, sizeof(pass), stdin);
            pass[strcspn(pass, "\n")] = '\0';

            // Copy at most 14 characters to ensure null-termination
            strncpy(account[i].password, pass, sizeof(account[i].password) - 1);
            account[i].password[sizeof(account[i].password) - 1] = '\0';

            showLoading();
            printf("Account created.\n\n");
            printf("Please enter an initial deposit amount in rupess: ");
            scanf("%d", &paisa);
            account[i].amount = paisa;

            printf("\n_______________________________________________________________________________________________________\n");
        }

        for (int i = 0; i < n; i++)
        {
            fprintf(file, "%s,%s,%d,%lld,%lld,%s,%d\n",
                    account[i].name,
                    account[i].address,
                    account[i].age,
                    account[i].phone_no,
                    account[i].account_no,
                    account[i].password,
                    account[i].amount);

            if (ferror(file))
            {
                printf("Error writing to file.\n");
                return 1;
            }
        }

        fclose(file);

        printf("\nACCOUNT DETAILS:\n\n");

        file = fopen("file.csv", "r");

        if (file == NULL)
        {
            printf("Error opening the file.\n");
            return 1;
        }

        for (i = 0; i < n; i++)
        {
            fscanf(file, "%d,%s,%s,%lld,%lld,%s,%d\n",
                   &account[i].age,
                   account[i].name,
                   account[i].address,                   
                   &account[i].phone_no,
                   &account[i].account_no,
                   account[i].password,
                   &account[i].amount);

            printf("Name: %s\n", account[i].name);
            printf("City: %s\n", account[i].address);
            printf("Age: %d\n", account[i].age);
            printf("Phone Number: %lld\n", account[i].phone_no);
            printf("Account Number(Login ID):%lld\n", account[i].account_no);
            printf("Password : %s\n", account[i].password);
            printf("Current Balance: Rs. %d\n", account[i].amount);
            printf("\n");
            printf("(Please remember the account number and password for future references)\n");
            printf("______________________________________________________________________________________________________\n");
        }

        if (file == NULL)
        {
            printf("Could not open file %s\n", file);
            return 1; // Exit with an error
        }

        // Read the file character by character
        while ((ch = fgetc(file)) != EOF)
        {
            // Count newline characters to determine rows
            if (ch == '\n')
            {
                rows++;
            }
        }

        fclose(file);
        Sleep(3000);
        goto start;
        break;

    case 2:

        showLoading();

        system("cls");

        printf("\nWelcome to the login page.\n");

        int file_check = 0;
        long long int log;
        char passw[15];
    pass:
        printf("\nEnter your LOGIN ID(Account number) : ");
    id:
        scanf("%lld", &log);
        fflush(stdin);
        printf("\nEnter your Password (It is case sensitive): ");
        fgets(passw, sizeof(passw), stdin);
        passw[strcspn(passw, "\n")] = '\0';

        file = fopen("file.csv", "r");
        int i = 0;
        while (fscanf(file, "%lld,%s", &account[i].account_no, account[i].password) != EOF)
        {
            fscanf(file, "%lld,%s\n", &account[i].account_no, account[i].password);
            if (account[i].account_no == log && (strcmp(account[i].password, passw) == 0))
            {
                file_check++;
                printf("\nYou have successfully logged into your account.\n");
                int user_inp;
            go_back:
                printf("\n\nWhat would you like to do?\n");
                printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Explore more options\n5. Exit");
                printf("Your choice: ");
            re_enter:
                scanf("%d", &user_inp);

                switch (user_inp)
                {
                    int dep, with;
                case 1:
                    printf("The balance in your account is: ");
                    printf("%d", account[i].amount);
                    goto go_back;

                case 2:
                    printf("Enter the amount to deposit: ");
                    scanf("%d", &dep);

                    account[i].amount += dep;
                    printf("The balance in your account after deposition is: ");
                    printf("%d", account[i].amount);
                    goto go_back;

                case 3:
                    printf("The balance in your account is:");
                    printf("%d", account[i].amount);
                withdraw:
                    printf("\nEnter the amount to withdraw: ");
                    scanf("%d", &with);
                    if (with > account[i].amount)
                    {
                        printf("\nYou don't have enough balance in your account.");
                        goto withdraw;
                    }
                    else
                    {
                        account[i].amount -= with;
                        printf("The balance after withdrawal in your account is: ");
                        printf("%d", account[i].amount);
                        goto go_back;
                    }

                case 4:
                    return 0;

                case 5:
                    return 1;

                default:
                    printf("Invalid input!\n");
                    goto go_back;
                }

                break;
            }
            i++;
        }

        if (file_check == 0)
        {
            printf("\n You have entered wrong login details.\nDo you want to exit?\n1. Yes\n2. No\nYour choice: ");
        choice:
            scanf("%d", &ask);
            switch (ask)
            {
            case 1:
                return 1;
                break;

            case 2:
                goto pass;
                break;

            default:
                printf("Enter a valid choice: ");
                goto choice;
            }
        }

        fclose(file);
        break;

    case 3:

        return 1;
        break;

    default:
        printf("Invalid entry!\n");
        goto start;
    }

end:
    return 0;
}

void showLoading()
{
   /*const char chars[] = {'|', '/', '-', '\\'};
    const int numChars = sizeof(chars) / sizeof(chars[0]);
    const int numIterations = 20;

    for (int i = 0; i < numIterations; ++i)
    {
        printf("Loading... %c\r", chars[i % numChars]);
        fflush(stdout);
        Sleep(100); // Sleep for 100 microseconds (0.1 seconds)
    }

    printf("                     \n");*/
    int i;
    int n = 3; // Number of iterations or steps in your task, i.e. we want 3 dots.

    printf("Loading ");

    for (i = 0; i < n; i++)
    {
        printf(".");
        fflush(stdout); // Flush the output to the console
        Sleep(500);     // Sleep for 0.5 second (500 milliseconds) This created a pause after each iteration
    }
    printf("\r");
    for (int j = 0; j < 14; j++)
    { // Adjust the number of spaces as needed
        printf(" ");
    }
    printf("\n");

    fflush(stdout);
}

