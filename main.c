#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mastermind.h"

// variable declaration
char userGuess[4], userCode[4];
int userAttempt,rounds,respond;

int main(int ac, char ** av)
{
    do{
        //gettiing secrete code to be guest and attempt to be used
        my_strcpy(userCode,getCode(ac,av,userCode));
        userAttempt=getAttempt(ac,av,userAttempt);

        printf("Will you find the secret code? \n");
        //calling function to generate round giving out number of well placed and misplaced
        roundGenerator(userAttempt,userCode,userGuess);
        //end of game printing secrete code
        printf("\n code is : %s \n",userCode);
        //asking user to play again or end game
        printf("\n Enter\t1:New Game\tAny key: Exit \n>");
        scanf("%d",&respond);
    }while(respond==1);
}

    
