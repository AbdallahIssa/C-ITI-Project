#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "STD_TYPES.h"
#include "BANK_Interface.h"
#include "BANK_Private.h"

#define CLEAR_SCREEN()    system("cls")

void InitTheSystem(void)
{
    //To Initiate the BankAccount_ID for all customers with -1
    //to Avoid that doesBankAccountIDExist relys on default value 0
    for(u8 index = 0;index<NUMBER_OF_CUSTOMERS; index++)
    {
        AccountInfo_t[index].BankAccount_ID = -1;
    }

    for(u8 i=0; i<3; i++)
    {
        printf("                          *********************************************************************                          \n");
        printf("                          *                     Welcome to IMT Bank System                    *                          \n");
        printf("                          *********************************************************************                          \n");
        delay(500);
        CLEAR_SCREEN();
        delay(500);
    }
}

void startTheSystem(void)
{
    u32 systemChoice;
    u8 adminUsername[20] = {0}, choice;

    printf("Choose from these options:\n\n\
           1-for Administrator mode.\n\
           2-for Client mode.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &systemChoice);
    switch(systemChoice)
    {
    case 1:
        CLEAR_SCREEN();
        printf("Enter username please: ");
        scanf("%s", adminUsername);
        CLEAR_SCREEN();
        printf("Enter password please: ");
        //To make Password Invisible and predetermined with (ADMIN_PASSWORD_LENGTH) digits
        u8 adminPassword[5] = {0};
        for (u8 index=0; index<ADMIN_PASSWORD_LENGTH; index++) {
            adminPassword[index] = getch();
            printf("*");
        }
        adminPassword[4] = '\0';
        if((!strcmp(adminUsername, ADMIN_USERNAME)) && (!strcmp(adminPassword, ADMIN_PASSWORD)))
        {
            CLEAR_SCREEN();
            adminMode();
        }
        else
        {
            CLEAR_SCREEN();
            printf("You Enter invalid username or password, please try again...\n\n");
            printf("Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice)
            {
            case 1:
                CLEAR_SCREEN();
                startTheSystem();
                break;
            case 2: default:
                CLEAR_SCREEN();
                exitTheSystem();
                break;
            }
        }
        break;
    case 2:
        CLEAR_SCREEN();
        clientMode();
        break;
    default:
        CLEAR_SCREEN();
        printf("You entered invalid option\n\n");
        printf("Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            CLEAR_SCREEN();
            startTheSystem();
            break;
        case 2: default:
            CLEAR_SCREEN();
            exitTheSystem();
            break;
        }
        break;
    }
}


void adminMode(void)
{
    u8 choice1, choice2;

    printf("Choose from these options:\n\n\
           1-Create New Account.\n\
           2-Open Existing Account.\n\
           3-Exit the System.\n\
           4-TestPrintResults.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1)
    {
    case 1:
        CLEAR_SCREEN();
        createNewAccount();
        break;
    case 2:
        CLEAR_SCREEN();
        openExistingAccount();
        break;
    case 3:
        CLEAR_SCREEN();
        exitTheSystem();
        break;
    case 4:
        CLEAR_SCREEN();
        TestPrintResults();
        break;
    default:
        CLEAR_SCREEN();
        printf("You entered invalid option\n\n");
        printf("Do you want to continue?\n1-for Yes.\n2-for No.\n\nEnter your choice: ");
        scanf("%d", &choice2);
        switch(choice2)
        {
        case 1:
            CLEAR_SCREEN();
            Admin_returnToMainMenu();
            break;
        case 2: default:
            CLEAR_SCREEN();
            exitTheSystem();
            break;
        }
        break;
    }
}

void createNewAccount(void)
{
    static u32 i = 0;
    printf("Enter the full name please:  ");
    scanf("%s", &AccountInfo_t[i].fullName);
    fflush(stdin);
    printf("Enter the full address please:  ");
    scanf("%s", &AccountInfo_t[i].fullAddress);
    fflush(stdin);
    printf("Enter the national ID please:  ");
    scanf("%lf", &AccountInfo_t[i].national_ID);
    fflush(stdin);
    printf("Enter the age please:  ");
    scanf("%d", &AccountInfo_t[i].age);
    fflush(stdin);
    if(AccountInfo_t[i].age < 21)
    {
        AccountInfo_t[i].guardian = 1;
        printf("Enter the guardian national ID please:  ");
        scanf("%lf", &AccountInfo_t[i].guardianNational_ID);
        fflush(stdin);
    }
    else
    {
        AccountInfo_t[i].guardian = 0;
    }
    printf("Enter the balance please:  ");
    scanf("%lf", &AccountInfo_t[i].balance);
    fflush(stdin);

    AccountInfo_t[i].accountStatus = ACTIVE;
    AccountInfo_t[i].password = random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD);
    AccountInfo_t[i].BankAccount_ID = i;

    i++;

    CLEAR_SCREEN();
    for(u8 index=0; index<3; index++)
    {
        printf("             Registration process is Done Successfully!             ");
        delay(500);
        CLEAR_SCREEN();
        delay(300);
    }
    Admin_returnToMainMenu();
}

u8 doesBankAccountIDExist(f64 bankAccountID)
{
    u8 exist = 0;
    for(u8 index=0; index<NUMBER_OF_CUSTOMERS; index++)
    {
        if(AccountInfo_t[index].BankAccount_ID == bankAccountID)
        {
            exist = 1;
            break;
        }
    }
    return exist;
}

void openExistingAccount(void)
{
    f64 bankAccountID, Getcash, depositCash;
    u8 ID_exists1, ID_exists2, choice, bankAccountStatus, cashAvilablity;
    printf("Enter client bank account ID please: ");
    scanf("%lf", &bankAccountID);
    ID_exists1 = doesBankAccountIDExist(bankAccountID);
    if(ID_exists1)
    {
        CLEAR_SCREEN();
        printf("Choose from these options:\n\n\
               1- Make Transaction.\n\
               2- Change Account Status.\n\
               3- Get Cash.\n\
               4- Deposit in Account.\n\
               5- Return to main menu.\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            CLEAR_SCREEN();
            f64 receiverID, money;
            printf("please Enter amount of money: ");
            scanf("%lf", &money);

            printf("please Enter the Bank Account ID you want to transfer the money to: ");
            scanf("%lf", &receiverID);
            ID_exists2 = doesBankAccountIDExist(receiverID);

            if(ID_exists2)
            {
                u8 tranactionResult = Admin_MakeTransaction(bankAccountID, receiverID, money);
                if(tranactionResult == SUCCESS_OPERATION)
                {
                    CLEAR_SCREEN();
                    for(u8 index=0; index<3; index++)
                    {
                        printf("             Transaction process is Done Successfully!             ");
                        delay(500);
                        CLEAR_SCREEN();
                        delay(300);
                    }
                    Admin_returnToMainMenu();
                }
                else if(tranactionResult == FAIL_NOT_SUFFICIENT_MONEY)
                {
                    CLEAR_SCREEN();
                    printf("Operation failed because there is no sufficient money!");
                    delay(3000);
                    CLEAR_SCREEN();
                    Admin_returnToMainMenu();
                }
                else
                {
                    CLEAR_SCREEN();
                    printf("Operation failed because the user isn't an active user!");
                    delay(3000);
                    CLEAR_SCREEN();
                    Admin_returnToMainMenu();
                }
            }
            else
            {
                printf("This ID doesn't exist");
                delay(3000);
                CLEAR_SCREEN();
                Admin_returnToMainMenu();
            }
            break;



        case 2:
            CLEAR_SCREEN();
            printf("Choose from these options to enter the bank account status:\n\n\
            1- Set Account to Active State.\n\
            2- Set Account to Restricted State.\n\
            3- Set Account to Closed. \n\n");

            printf("Enter your choice: ");
            scanf("%d", &bankAccountStatus);
            Admin_changeAccountStatus(bankAccountID, bankAccountStatus);
            CLEAR_SCREEN();
            for(u8 index=0; index<3; index++)
            {
                printf("             Changing the account status is Done Successfully!             ");
                delay(500);
                CLEAR_SCREEN();
                delay(300);
            }
            Admin_returnToMainMenu();
            break;


        case 3:
            CLEAR_SCREEN();
            printf("Please enter the cash amount you want from this account : ");
            scanf("%lf", &Getcash);
            cashAvilablity = Admin_getCash(bankAccountID, Getcash);
            if(cashAvilablity)
            {
                CLEAR_SCREEN();
                for(u8 index=0; index<3; index++)
                {
                    printf("             Getting the cash is Done Successfully!             ");
                    delay(500);
                    CLEAR_SCREEN();
                    delay(300);
                }
                Admin_returnToMainMenu();
            }
            else
            {
                CLEAR_SCREEN();
                printf("Operation failed because there is no sufficient money!");
                delay(3000);
                CLEAR_SCREEN();
                Admin_returnToMainMenu();
            }

            break;


        case 4:
            CLEAR_SCREEN();
            printf("Please enter the cash amount you want to deposit to this account : ");
            scanf("%lf", &depositCash);
            Admin_depositInAccount(bankAccountID, depositCash);
            CLEAR_SCREEN();
            for(u8 index=0; index<3; index++)
            {
                printf("             deposit In Account is Done Successfully!             ");
                delay(500);
                CLEAR_SCREEN();
                delay(300);
            }
            Admin_returnToMainMenu();
            break;
        case 5:
            CLEAR_SCREEN();
            Admin_returnToMainMenu();
            break;
        default:
            CLEAR_SCREEN();
            printf("You entered invalid option\n\n");
            delay(3000);
            CLEAR_SCREEN();
            Admin_returnToMainMenu();
            break;
        }
    }
    else
    {
        CLEAR_SCREEN();
        printf("This ID doesn't exist");
        delay(3000);
        CLEAR_SCREEN();
        Admin_returnToMainMenu();
    }

}

u8 Admin_MakeTransaction(f64 senderID,f64 receiverID,f64 money)
{
    u8 transactionStatus;
    //make sure that the amount of money is less than the balance
    if(money < AccountInfo_t[(u8)senderID].balance)
    {
        if((AccountInfo_t[(u32)receiverID].accountStatus == ACTIVE) &&
            (AccountInfo_t[(u32)senderID].accountStatus == ACTIVE))
        {
            AccountInfo_t[(u32)senderID].balance -= money;
            AccountInfo_t[(u32)receiverID].balance += money;
            transactionStatus = SUCCESS_OPERATION;
        }
        else
        {
            transactionStatus = FAIL_NOT_AN_ACTIVE_USER;
        }
    }
    else
    {
        transactionStatus = FAIL_NOT_SUFFICIENT_MONEY;
    }
    return transactionStatus;
}



void Admin_changeAccountStatus(f64 userID, u8 bankAccountStatus)
{
    u8 choice;
    switch(bankAccountStatus)
    {
    case 1:
        AccountInfo_t[(u32)userID].accountStatus = ACTIVE;
        break;
    case 2:
        AccountInfo_t[(u32)userID].accountStatus = RESTRICTED;
        break;
    case 3:
        AccountInfo_t[(u32)userID].accountStatus = CLOSED;
        break;
    default:
        printf("You entered invalid account status\n");
        printf("Do you want to continue?\n1-for Yes\n2-for No\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            CLEAR_SCREEN();
            Admin_changeAccountStatus(userID, bankAccountStatus);
            break;
        case 2: default:
            CLEAR_SCREEN();
            Admin_returnToMainMenu();
            break;
        }
        break;
    }

}


u8 Admin_getCash(f64 userID, f64 cash)
{
    u8 cashAvilablity;
    if(AccountInfo_t[(u32)userID].balance > cash)
    {
        AccountInfo_t[(u32)userID].balance -= cash;
        cashAvilablity = 1;
    }
    else
    {
        cashAvilablity = 0;
    }

    return cashAvilablity;
}



void Admin_depositInAccount(f64 userID,f64 depositCash)
{
    AccountInfo_t[(u32)userID].balance += depositCash;
}


void Admin_returnToMainMenu(void)
{
    adminMode();
}


void exitTheSystem(void)
{


    CLEAR_SCREEN();
    printf("Thanks                                    \n");
    delay(500);
    printf("             For                          \n");
    delay(500);
    printf("                        Using             \n");
    delay(500);
    printf("                                       Our\n");
    delay(500);
    printf("                        IMT               \n");
    delay(500);
    printf("             Bank                         \n");
    delay(500);
    printf("System                                    \n");
    delay(500);
    CLEAR_SCREEN();
    exit(0);

}

void TestPrintResults(void)
{
    printf("Age            =     %d\n", AccountInfo_t[0].age);
    printf("BankAccount_ID =     %0.0lf\n", AccountInfo_t[0].BankAccount_ID);
    printf("accountStatus  =     %d\n", AccountInfo_t[0].accountStatus);
    printf("fullName       =     %s\n", AccountInfo_t[0].fullName);
    printf("fullAddress    =     %s\n", AccountInfo_t[0].fullAddress);
    printf("Balance        =     %0.5f\n", AccountInfo_t[0].balance);
    printf("guardian       =     %d\n", AccountInfo_t[0].guardian);
    printf("Gnational_ID   =     %0.0f\n", AccountInfo_t[0].guardianNational_ID);
    printf("national_ID    =     %0.0f\n", AccountInfo_t[0].national_ID);
    printf("password       =     %d\n", AccountInfo_t[0].password);

    printf("***************************************************\n");
    printf("***************************************************\n");

    printf("Age            =     %d\n", AccountInfo_t[1].age);
    printf("BankAccount_ID =     %0.0lf\n", AccountInfo_t[1].BankAccount_ID);
    printf("accountStatus  =     %d\n", AccountInfo_t[1].accountStatus);
    printf("fullName       =     %s\n", AccountInfo_t[1].fullName);
    printf("fullAddress    =     %s\n", AccountInfo_t[1].fullAddress);
    printf("Balance        =     %0.5f\n", AccountInfo_t[1].balance);
    printf("guardian       =     %d\n", AccountInfo_t[1].guardian);
    printf("Gnational_ID   =     %0.0f\n", AccountInfo_t[1].guardianNational_ID);
    printf("national_ID    =     %0.0f\n", AccountInfo_t[1].national_ID);
    printf("password       =     %d\n", AccountInfo_t[1].password);

    u8 choice;
    printf("\n\nDo you want to continue?\n1-for Yes\n2-for No\n\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
    case 1:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    case 2: default:
        CLEAR_SCREEN();
        exitTheSystem();
        break;
    }

}

void clientMode(void)
{
    f64 bankAccountID, Getcash, depositCash, receiverID, money;
    u32 Password, oldPass, newPass;
    u8 ID_exists1, passwordCorrect, ID_exists2, choice, bankAccountStatus, cashAvilablity, c;

    printf("Welcome in client mode\n\n\
           Choose from these options:\n\
           1-Enter Client Mode.\n\
           2-Back To Main Menu.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &c);
    switch(c)
    {
    case 1:
        CLEAR_SCREEN();
        printf("Enter client bank account ID please: ");
        scanf("%lf", &bankAccountID);
        ID_exists1 = doesBankAccountIDExist(bankAccountID);

        if(ID_exists1)
        {
            printf("Enter your Password please: ");
            scanf("%d", &Password);
            passwordCorrect = ((Password==AccountInfo_t[(u32)bankAccountID].password)?1:0);
            if(passwordCorrect)
            {
                CLEAR_SCREEN();
                printf("Choose from these options:\n\n\
                       1- Make Transaction.\n\
                       2- Change Account Password.\n\
                       3- Get Cash.\n\
                       4- Deposit in Account.\n\
                       5- Return to main menu.\n\n");

                printf("Enter your choice: ");
                scanf("%d", &choice);
                switch(choice)
                {
                case 1:
                    CLEAR_SCREEN();
                    printf("please Enter amount of money: ");
                    scanf("%lf", &money);
                    printf("please Enter the Bank Account ID you want to transfer the money to: ");
                    scanf("%lf", &receiverID);
                    ID_exists2 = doesBankAccountIDExist(receiverID);

                    if(ID_exists2)
                    {
                        u8 tranactionResult = Client_MakeTransaction(bankAccountID, receiverID, money);
                        if(tranactionResult == SUCCESS_OPERATION)
                        {
                            CLEAR_SCREEN();
                            for(u8 index=0; index<3; index++)
                            {
                                printf("             Transaction process is Done Successfully!             ");
                                delay(500);
                                CLEAR_SCREEN();
                                delay(300);
                            }
                            Client_returnToMainMenu();
                        }
                        else if(tranactionResult == FAIL_NOT_SUFFICIENT_MONEY)
                        {
                            CLEAR_SCREEN();
                            printf("Operation failed because there is no sufficient money!");
                            delay(3000);
                            CLEAR_SCREEN();
                            Client_returnToMainMenu();
                        }
                        else
                        {
                            CLEAR_SCREEN();
                            printf("Operation failed because the user isn't an active user!");
                            delay(3000);
                            CLEAR_SCREEN();
                            Client_returnToMainMenu();
                        }
                    }
                    else
                    {
                        printf("This ID doesn't exist");
                        delay(3000);
                        CLEAR_SCREEN();
                        Client_returnToMainMenu();
                    }
                    break;



                case 2:
                    CLEAR_SCREEN();
                    printf("Enter the old Password first: ");
                    scanf("%d", &oldPass);
                    if(AccountInfo_t[(u32)bankAccountID].password == oldPass)
                    {
                        printf("Now, enter the new Password: ");
                        scanf("%d", &newPass);
                        Client_changeAccountPassword(bankAccountID, newPass);
                        CLEAR_SCREEN();
                        for(u8 index=0; index<3; index++)
                        {
                            printf("             Changing the Password is Done Successfully!             ");
                            delay(500);
                            CLEAR_SCREEN();
                            delay(300);
                        }
                        Client_returnToMainMenu();
                    }
                    else
                    {
                        CLEAR_SCREEN();
                        printf("You entered the old password\n\n");
                        delay(3000);
                        CLEAR_SCREEN();
                        Client_returnToMainMenu();
                    }

                    break;


                case 3:
                    CLEAR_SCREEN();
                    printf("Please enter the cash amount you want from this account : ");
                    scanf("%lf", &Getcash);
                    cashAvilablity = Client_getCash(bankAccountID, Getcash);
                    if(cashAvilablity)
                    {
                        CLEAR_SCREEN();
                        for(u8 index=0; index<3; index++)
                        {
                            printf("             Getting the cash is Done Successfully!             ");
                            delay(500);
                            CLEAR_SCREEN();
                            delay(300);
                        }
                        Client_returnToMainMenu();
                    }
                    else
                    {
                        CLEAR_SCREEN();
                        printf("Operation failed because there is no sufficient money!");
                        delay(3000);
                        CLEAR_SCREEN();
                        Client_returnToMainMenu();
                    }

                    break;


                case 4:
                    CLEAR_SCREEN();
                    printf("Please enter the cash amount you want to deposit to this account : ");
                    scanf("%lf", &depositCash);
                    Client_depositInAccount(bankAccountID, depositCash);
                    CLEAR_SCREEN();
                    for(u8 index=0; index<3; index++)
                    {
                        printf("             deposit In Account is Done Successfully!             ");
                        delay(500);
                        CLEAR_SCREEN();
                        delay(300);
                    }
                    Client_returnToMainMenu();
                    break;
                case 5:
                    CLEAR_SCREEN();
                    Client_returnToMainMenu();
                    break;
                default:
                    CLEAR_SCREEN();
                    printf("You entered invalid option\n\n");
                    delay(3000);
                    CLEAR_SCREEN();
                    Client_returnToMainMenu();
                    break;
                }
            }
            else
            {
                CLEAR_SCREEN();
                printf("You entered invalid password\n\n");
                delay(3000);
                CLEAR_SCREEN();
                Client_returnToMainMenu();
            }

        }
        else
        {
            CLEAR_SCREEN();
            printf("This ID doesn't exist");
            delay(3000);
            CLEAR_SCREEN();
            Client_returnToMainMenu();
        }
        break;
    case 2:
        CLEAR_SCREEN();
        startTheSystem();
        break;
    default:
        CLEAR_SCREEN();
        printf("You entered invalid option\n\n");
        delay(3000);
        CLEAR_SCREEN();
        startTheSystem();
        break;
    }

}

void Client_returnToMainMenu(void)
{
    clientMode();
}


u8 Client_MakeTransaction(f64 senderID, f64 receiverID, f64 money)
{
    u8 transactionStatus;
    //make sure that the amount of money is less than the balance
    if(money < AccountInfo_t[(u8)senderID].balance)
    {
        if((AccountInfo_t[(u32)receiverID].accountStatus == ACTIVE) &&
            (AccountInfo_t[(u32)senderID].accountStatus == ACTIVE))
        {
            AccountInfo_t[(u32)senderID].balance -= money;
            AccountInfo_t[(u32)receiverID].balance += money;
            transactionStatus = SUCCESS_OPERATION;
        }
        else
        {
            transactionStatus = FAIL_NOT_AN_ACTIVE_USER;
        }
    }
    else
    {
        transactionStatus = FAIL_NOT_SUFFICIENT_MONEY;
    }
    return transactionStatus;
}



void Client_changeAccountPassword(f64 userID, u32 newPassword)
{
    AccountInfo_t[(u32)userID].password = newPassword;
}


u8 Client_getCash(f64 userID, f64 cash)
{
    u8 cashAvilablity;
    if(AccountInfo_t[(u32)userID].balance > cash)
    {
        AccountInfo_t[(u32)userID].balance -= cash;
        cashAvilablity = 1;
    }
    else
    {
        cashAvilablity = 0;
    }

    return cashAvilablity;
}


void Client_depositInAccount(f64 userID,f64 depositCash)
{
    AccountInfo_t[(u32)userID].balance += depositCash;
}





u32 random_(u32 minVal, u32 maxVal)
{
    u8 count = 0;
    u32 result = ((rand()%(( maxVal + 1 - minVal) + minVal)));
    u32 temp = result;
    while(temp!=0)
    {
       temp/=10;
       count++;
    }
    if(count>RANDOM_PASSWORD_LENGTH)
    {
        result = random_(minVal, maxVal);
    }
    return result;
}

void delay(u32 milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}


u8 doubleCompare(f64 num1, f64 num2)
{
    return (fabs(num1 - num2) < EPSILON);
}


