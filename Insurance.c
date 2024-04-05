#include<stdio.h>
#include<string.h>
#include<stdlib.h> //req. headers for rand() function
#include<time.h>   //req. headers for rand() function
#include<windows.h> // for sleep function
#include<conio.h>
int insurance();
int insurance_driver();

int policyNum()
{
    int policyNum=rand() % 9000000000 + 1000000000; //rand()=random number generator here,1000000000=1st no. in the range, 9000000000= no. of terms in the range
    return policyNum;
}
void show_load()
{
    int i;
    int n=3; //No. of steps in your task,i.e. no. of dots
    printf("Processing ");

    for (i=0;i<n;i++)
    {
        printf(".");
        fflush(stdout); //Flush the output to the console,Ensure the dot is printed immediately
        Sleep(1000); // Sleep for 1 sec,in Windows system-takes time as the number of milliseconds
    }
    printf("\r"); //"\r"-known as "carriage return"-moves the cursor to the beginning of the current line without going to the next line
    for (int j=0;j<14;j++)
    {
        printf(" "); // Adjust the no. of spaces as needed
    }
    printf("\n");

    fflush(stdout);
}
int insurance_driver()
{
    insurance();
    return 0;
}
int insurance()
{   //n = choice (1-3) for type of insurance
    //cover = choice (1-3) for coverage for life insurance:50L/1cr/2cr
    //b=policy number
    //cover_value = coverage amount
    //premium0=premium per month (life)
    //p=choice 0 to exit,1 to continue (life insurance)
    //age=age when applying for health insurance
    //alco=choice 0 for no alcohol consumption ,else 1
    //cover_amnt=choice for coverage amount fot health insurance
    //cover_amn=coverage amount
    //d=premium per month (health) 
    //k=choice 0 to exit,1 to continue (health insurance)
    //ag=age of the car owner
    //z=choice 0 to exit,1 to continue (car insurance)
    int value,value_car,cover_value,n,a,d,c,z,k,b,age_car,ag,year,p,acc_num,premium0,cover,age,cover_amnt,cover_amn,alco;
    float premium; //premium for car insurance
    char ph[100],benefi[100];
    srand(time(NULL)); //prevent sequence repetitions
                                                              
    printf("\n\n      WELCOME TO THE INSURANCE SECTION       \n");

    start:
    printf("\nChoose from the following options:");
    printf("\n1. Life Insurance");
    printf("\n2. Health Insurance");
    printf("\n3. Car Insurance");
    printf("\nEnter your choice:");
    scanf("%d",&n);
    getchar();
    b = policyNum();

    switch (n)
    {
        case 1:
        life_insurance:
        printf("\nYou have selected life insurance. \n");
        ph: //policy holder
        printf("\nEnter the name of policy holder:");
        gets(ph);
        for (int i=0;i<strlen(ph);i++)
        {
            //Alphabet or space
            if ((ph[i]>='a' && ph[i]<='z') || (ph[i]>='A' && ph[i]<='Z') || ph[i] == ' ')
            continue;
            else 
            {
                printf("Enter a valid name");
                goto ph;
            }
        }
        benefi:  //beneficiary
        printf("\nEnter the name of beneficiary:");
        gets(benefi);
        for (int j=0;j<strlen(benefi);j++)
        {
            //Alphabet or space
            if ((benefi[j]>='a' && benefi[j]<='z') || (benefi[j]>='A' && benefi[j]<='Z') || benefi[j] == ' ')
            continue;
            else 
            {
                printf("Enter a valid name");
                goto benefi;
            }
        }

        cover:
        printf("\nSelect the coverage for your life insurance:");
        printf("\n1. 50 lakhs");
        printf("\n2. 1 crore");
        printf("\n3. 2 crores");
        printf("\nEnter your choice (1-3):");
        scanf("%d",&cover);
        show_load();

        if ( cover == 1)
        {
            cover_value = 5000000;
            premium0 = 340;
            printf("\nThe premium you have to pay is Rs. 340 per month");
            select2:
            printf("\nEnter 1 to continue and 0 to exit");
            scanf("%d",&p);
            if (p == 0)
            {
                printf("\nYour insurance application has been cancelled");

                break;
            }
            else if (p == 1)
            {
                show_load();
                printf("\n-----------------------------------------------------------------------------");
                printf("\nThe details of your insurance are as follows:");
                printf("\n\nThe name of policy holder:");
                puts(ph);
                printf("\nThe name of beneficiary:");
                puts(benefi);
                printf("\nCoverage amount : 50 lakhs");
                printf("\nYour policy number for the insurance is %010d",b);
                printf("\nThe premium you have to pay is Rs. %d per month", premium0);
                printf("\n\nThank You for taking the insurance");
            }
            else 
            {
                printf("\nInvalid input");
                goto select2;
            }
        }

        else if (cover == 2)
        {
            cover_value = 10000000;
            premium0 = 580;
            printf("\nThe premium you have to pay is Rs. 580 per month");
            select3:
            printf("\nEnter 1 to continue and 0 to exit");
            scanf("%d",&p);
            if (p == 0)
            {
                printf("\nYour insurance application has been cancelled");

                break;
            }
            else if (p == 1)
            {
                show_load();
                printf("\n-----------------------------------------------------------------------------");
                printf("\nThe details of your insurance are as follows:");
                printf("\n\nThe name of policy holder:");
                puts(ph);
                printf("\nThe name of beneficiary:");
                puts(benefi);
                printf("\nCoverage amount : 1 crore");
                printf("\nYour policy number for the insurance is %010d",b);
                printf("\nThe premium you have to pay is Rs. %d per month", premium0);
                printf("\n\nThank You for taking the insurance");
            }
            else 
            {
                printf("\nInvalid input");
                goto select3;
            }
        }
        else if (cover == 3)
        {
            cover_value = 20000000;
            premium0 = 920;
            printf("\nThe premium you have to pay is Rs. 920 per month");
            select4:
            printf("\nEnter 1 to continue and 0 to exit");
            scanf("%d",&p);
            if (p == 0)
            {
                printf("\nYour insurance application has been cancelled");

                break;
            }
            else if (p == 1)
            {
                show_load();
                printf("\n-----------------------------------------------------------------------------");
                printf("\nThe details of your insurance are as follows:");
                printf("\n\nThe name of policy holder:");
                puts(ph);
                printf("\nThe name of beneficiary:");
                puts(benefi);
                printf("\nCoverage amount : 2 crores");
                printf("\nYour policy number for the insurance is %010d",b);
                printf("\nThe premium you have to pay is Rs. %d per month", premium0);
                printf("\n\nThank You for taking the insurance");
            }
            else 
            {
                printf("\nInvalid input");
                goto select4;
            }
        }
        else 
        {
            printf("\nInvalid input, please enter from 1 to 3");
            goto cover;
        }

        break;

      case 2:
      b=policyNum();
      printf("\nYou have selected health insurance. \n");
      benefi1:
      printf("\nEnter the name of beneficiary:");
      gets(benefi);

      for ( int j=0;j<strlen(benefi);j++)
      {
          if ((benefi[j] >= 'a' && benefi[j] <= 'z') || (benefi[j] >= 'A' && benefi[j] <= 'Z' )|| benefi[j] == ' ')
          continue;
          else 
          {
              printf("\nEnter a valid name");
              goto benefi1;
          }
        }
        age:
        printf("\nEnter your age:");
        scanf("%d",age);
        if (age >= 0 && age < 18)
        {
            printf("\nYou cannot apply for insurance.");
            return 0;
            break;
        }

      else if (age >=18)
      {
        alcohol:
        printf("\nEnter 1 if you smoke or consume alcohol else enter 0");
        printf("\nEnter your choice:");
        scanf("%d",&alco);
        if (alco != 1 && alco !=0)
        {
            printf("\nInvalid input.");
            goto alcohol;
        }
        health:
        printf("\nThe coverage amount available for you are as follows:");
        printf("\n1. 2,00,000");
        printf("\n2. 5,00,000");
        printf("\n3. 10,00,000");
        printf("\n4. 20,00,000");
        printf("\nChoose your desired coverage amount:");
        scanf("%d",&cover_amnt);
        if (cover_amnt ==1 || cover_amnt ==200000)
        {
            cover_amn=200000;
            if (age >60)
            {
                if (alco == 1)
                {
                    d=680;
                    printf("\nYou have to pay a premium of Rs. 680 per month for next 5 years");
                    approve15:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 680 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve15;
                    }
                }
                else 
                {
                    d = 540;
                    printf("\nYou have to pay a premium of Rs. 540 per month for next 5 years");
                    approve14:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 540 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve14;
                    }
                }
            }
            else if (age >= 18 && age <=60)
            {
                if (alco == 1)
                {
                    d = 580;
                    printf("\nYou have to pay a premium of Rs. 580 per month for next 5 years");
                    approve13:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 580 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve13;
                    }
                }
                else 
                {
                    d=470;
                    printf("\nYou have to pay a premium of Rs. 470 per month for next 5 years");
                    approve12:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 470 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve12;
                    }
                }
            }
        }
        else if (cover_amnt == 2 || cover_amnt == 500000)
        {
            cover_amn=500000;
            if (age >60)
            {
                if (alco == 1)
                {
                    d=880;
                    printf("\nYou have to pay a premium of Rs. 880 per month for next 5 years");
                    approve11:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 880 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve11;
                    }
                }
                else 
                {
                    d = 740;
                    printf("\nYou have to pay a premium of Rs. 740 per month for next 5 years");
                    approve10:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 740 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve10;
                    }
                }
            }
            else if (age >= 18 && age <=60)
            {
                if (alco == 1)
                {
                    d = 680;
                    printf("\nYou have to pay a premium of Rs. 680 per month for next 5 years");
                    approve9:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 680 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve9;
                    }
                }
                else 
                {
                    d=570;
                    printf("\nYou have to pay a premium of Rs. 570 per month for next 5 years");
                    approve8:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 570 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve8;
                    }
                }
            }
        }
        else if (cover_amnt == 3 || cover_amnt == 1000000)
        {
            cover_amn=1000000;
            if (age >60)
            {
                if (alco == 1)
                {
                    d=980;
                    printf("\nYou have to pay a premium of Rs. 980 per month for next 5 years");
                    approve7:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 980 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve7;
                    }
                }
                else 
                {
                    d = 740;
                    printf("\nYou have to pay a premium of Rs. 740 per month for next 5 years");
                    approve6:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 740 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve6;
                    }
                }
            }
            else if (age >= 18 && age <=60)
            {
                if (alco == 1)
                {
                    d = 780;
                    printf("\nYou have to pay a premium of Rs. 780 per month for next 5 years");
                    approve5:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 780 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve5;
                    }
                }
                else 
                {
                    d=570;
                    printf("\nYou have to pay a premium of Rs. 570 per month for next 5 years");
                    approve4:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 570 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve4;
                    }
                }
            }
        }
        else if (cover_amnt == 4 || cover_amnt == 2000000)
        {
            cover_amn=2000000;
            if (age >60)
            {
                if (alco == 1)
                {
                    d=1180;
                    printf("\nYou have to pay a premium of Rs. 1180 per month for next 5 years");
                    approve3:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 1180 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve3;
                    }
                }
                else 
                {
                    d = 940;
                    printf("\nYou have to pay a premium of Rs. 940 per month for next 5 years");
                    approve2:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 940 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve2;
                    }
                }
            }
            else if (age >= 18 && age <=60)
            {
                if (alco == 1)
                {
                    d = 980;
                    printf("\nYou have to pay a premium of Rs. 980 per month for next 5 years");
                    approve1:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 980 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve1;
                    }
                }
                else 
                {
                    d=770;
                    printf("\nYou have to pay a premium of Rs. 770 per month for next 5 years");
                    approve:
                    printf("\nEnter 1 to continue with the insurance and enter 0 to cancel the application");
                    scanf("%d",&k);

                    if (k == 0)
                    {
                        show_load();
                        printf("\nYour application has been cancelled");
                        break;
                    }
                    else if (k == 1)
                    {
                        show_load();
                        printf("\nThe details of your insurance is as follows:");
                        printf("\n");
                        printf("\nName of beneficiary:");
                        puts(benefi);
                        printf("\nAge : %d",age);
                        printf("\nCoverage amount : %d",cover_amn);
                        printf("\nYour policy number for the insurance is %010d",b);
                        printf("\nThe premium you have to pay is Rs. 770 per month for next 5 years");
                        printf("\n\nThank You for taking the insurance");
                    }
                    else 
                    {
                        printf("\nInvalid input");
                        goto approve;
                    }
                }
            }
        }
        else 
        {
            printf("\nInvalid input.Enter correct choice from the list");
            goto health;
        }
        break;
      }
      case 3:
      b=policyNum();
      printf("\nYou have selected car insurance");
      benefi2:
      printf("\nEnter your name:");
      gets(benefi);
      for (int j=0;j < strlen(benefi);j++)
      {
        if ((benefi[j] >= 'a' && benefi[j] <= 'z') || (benefi[j] >= 'A' && benefi[j] <= 'Z') || benefi[j] == ' ')
        continue;
        else 
        {
            printf("\nEnter a valid name");
            goto benefi2;
        }
      }
      age1:
      printf("\nEnter your age in years:");
      scanf("%d",&ag);
      if (ag < 18)
      {
        printf("\nYour are not eligible to apply.");
      }
      else if (ag >= 18 && ag <=80)
      {
        printf("\nEnter the value of your car (in Rs.):");
        scanf("%d",&value_car);
        printf("\nEnter the age of your car (in years):");
        scanf("%d",&age_car);
        if (age_car >0 && age_car <= 5)
        {
            premium = (value_car*2.3625)/100;
            printf("\nThe premium amount for you car insurance is Rs. %f per year",premium);
            printf("\n\nThe insurance will cover all the accidental damage to the car and repairing of any car body part including engine.");
            select:
            printf("\nEnter 1 to continue and 0 to exit:");
            scanf("%d",&z);
            if (z != 0 && z != 1)
            {
                printf("\nInvalid input");
                goto select;
            }
            else if (z == 0)
            {
                printf("\nYour application has been cancelled.");
                break;
            }
            else 
            {
                show_load();
                printf("\nCongratulations!Your insurance has been done");
                printf("\n\nThe details are as follows:");
                printf("\nName of policy holder:");
                puts(benefi);
                printf("\nAge of owner: %d",ag);
                printf("\nYour policy number for this insurance is %010d",b);
                printf("\nThe value of the car is %d",value_car);
                printf("\nThe age of the car is %d",age_car);
                printf("\n\nThank you for taking this insurance");

            }
        }
        else if (age_car > 5 && age_car <= 15)
        {
            premium = (value_car*3.3625)/100;
            printf("\nThe premium amount for you car insurance is Rs. %f per year",premium);
            printf("\n\nThe insurance will cover all the accidental damage to the car and repairing of any car body part including engine.");
            select1:
            printf("\nEnter 1 to continue and 0 to exit:");
            scanf("%d",&z);
            if (z != 0 && z != 1)
            {
                printf("\nInvalid input");
                goto select1;
            }
            else if (z == 0)
            {
                printf("\nYour application has been cancelled.");
                break;
            }
            else 
            {
                show_load();
                printf("\nCongratulations!Your insurance has been done");
                printf("\n\nThe details are as follows:");
                printf("\nName of policy holder:");
                puts(benefi);
                printf("\nAge of owner: %d",ag);
                printf("\nYour policy number for this insurance is %010d",b);
                printf("\nThe value of the car is %d",value_car);
                printf("\nThe age of the car is %d",age_car);
                printf("\n\nThank you for taking this insurance");

            }
        }
        else 
        {
            printf("\nFor this age of car you cannot apply for insurance.");
        }
      }
      else 
      {
        printf("\nInvalid input");
        goto age1;
      }
      break;

      default:
      printf("\nInvalid input");
      goto start;
    }
    return 0;
}