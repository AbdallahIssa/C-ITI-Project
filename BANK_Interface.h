#ifndef BANK_INTERFACE_H_INCLUDED
#define BANK_INTERFACE_H_INCLUDED

#include "STD_TYPES.h"


typedef enum{
    ACTIVE = 1,
    RESTRICTED,
    CLOSED
}AccountStatus_t;

typedef enum{
    SUCCESS_OPERATION = 1,
    FAIL_NOT_SUFFICIENT_MONEY,
    FAIL_NOT_AN_ACTIVE_USER
}TransactionStatus_t;

struct
{
    u8 fullName[50];
    u8 fullAddress[50];
    u8 age;
    f64 national_ID;
    f64 BankAccount_ID;
    u8 guardian;
    f64 guardianNational_ID;
    f64 balance;
    AccountStatus_t accountStatus;//Default set to ACTIVE
    u32 password;//Auto generated
}AccountInfo_t[NUMBER_OF_CUSTOMERS];

//Start function of All the system
void InitTheSystem(void);
void startTheSystem(void);

//Admin functions
void adminMode(void);

void createNewAccount(void);
void openExistingAccount(void);
u8 doesBankAccountIDExist(f64 bankAccountID);
u8 Admin_MakeTransaction(f64 senderID, f64 receiverID, f64 money);
void Admin_changeAccountStatus(f64 userID, u8 bankAccountStatus);
u8 Admin_getCash(f64 userID, f64 cash);
void Admin_depositInAccount(f64 userID,f64 depositCash);
void Admin_returnToMainMenu(void);
void exitTheSystem(void);





//Client functions
void clientMode(void);

u8 Client_MakeTransaction(f64 senderID, f64 receiverID, f64 money);
void Client_changeAccountPassword(f64 userID, u32 newPassword);
u8 Client_getCash(f64 userID, f64 cash);
void Client_depositInAccount(f64 userID,f64 depositCash);
void Client_returnToMainMenu(void);

//Auxiliary functions
u32 random_(u32 minVal, u32 maxVal);
void delay(u32 milli_seconds);
u8 doubleCompare(f64 num1, f64 num2);
void TestPrintResults(void);



#endif // BANK_INTERFACE_H_INCLUDED
