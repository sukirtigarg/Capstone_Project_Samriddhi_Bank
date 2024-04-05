#include <stdio.h>
#include "FD.c"
#include "Insurance.c"
#include "Loan.c"
#include "Registration.c"
int main()
{
    loaddata();
    int user_input, user;
    registration_driver();
    if (user == 1)
    {
        goto the_end;
    }
start:
    printf("\n\nWhat would you like to do?\n");

    printf("1. Create an FD\n2. Apply for Loan\n3. Apply for Insurance\n4. Exit\nYour Choice: ");
enter_2:
    scanf("%d", &user_input);

    switch (user_input)
    {
    case 1:
        fd_driver();
        goto start;
        break;

    case 2:
        loan_driver();
        goto start;
        break;

    case 3:
        insurance_driver();
        goto start;
        break;

    case 4:
        goto the_end;
        break;

    default:
        printf("Invalid input!\nEnter a valid choice: ");
        goto enter_2;
    }

the_end:
    printf("\nDo visit us again..");
    return 0;
}