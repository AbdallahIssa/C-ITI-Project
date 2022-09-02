#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "STD_TYPES.h"
#include "BANK_Config.h"
#include "BANK_Interface.h"

#include "BANK_program.c"

//TODO:
/*
    0- national_ID shouid be 14 digits
    1- make sure that random_ generates 4 digits as length
    2- Client_changeAccountPassword() * feature
    3- try to remove #include "BANK_program.c"
    4- try to remove all warnings
    5- apply doubleCompare()
	6- Finite State Machine design
*/


int main()
{
    srand(time(NULL));
    InitTheSystem();

    startTheSystem();

    //printf("%d\n", doubleCompare(1.023571, 1.023571));

    /*
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));

    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));


    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));


    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    printf("%d\n", random_(MIN_RANDOM_PASSWORD, MAX_RANDOM_PASSWORD));
    */

    /*
    char ch[6] = {0};

    u8 i;

    for (i=0; i<5; i++) {
        ch[i] = getch();
        printf("*");

    }

    printf("Received 5 character Input: %s\n", ch);
    */
    return 0;
}
