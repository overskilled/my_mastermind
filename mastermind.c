#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//declaration of global variables
int misplaced=0,welplaced=0;

//function to compaire  two string, return 0 if same and 1 if different
int my_strcmp(char* s1, char* s2){
    int i,test=0,strlength=strlen(s1);
    for(i=0;i<strlen(s1);i++){
        if(s1[i]==s2[i]) test++;
        else test--;
    }
    if(test==strlength) return 0;
    else return 1;
}

//function to copy one string in another
char* my_strcpy(char* dst, char* src){
    int i;
    for(i=0;i<strlen(src);i++) dst[i]=src[i];
    return dst;
}

//function to generate a random secrete code of 4 digit without repeatition
char * codeGenerator(char* num){
    int i,j;
    char set[8]={ '0','1','2','3','4','5','6','7'};
    srand(time(NULL));
    for(i=0;i<4;i++){
        //line to generate a random digit push in the string code
        random:
        num[i]=set[(rand() % 8)];
        //loop in case of repeated digit
        for(j=0;j<i;j++){
            //in case of repeated digit, goto line random to generate a new digit
            if(num[i]==num[j]) goto random;
        }
    }
    return num;
}

//function to get secrete code after option -c from user using main argument count and value
//or generate a random code in case of no given code
char* getCode(int mainAC, char ** mainAV, char* code){
    if(mainAC==3){
        if(my_strcmp("-c",mainAV[1])==0){
            my_strcpy(code,mainAV[2]);
        }
        else{
        my_strcpy(code,codeGenerator(code));
        }
    }
    else if(mainAC==5){
        if(my_strcmp("-c",mainAV[3])==0){
            my_strcpy(code,mainAV[4]);
        }
        else if(my_strcmp("-c",mainAV[1])==0){
            my_strcpy(code,mainAV[2]);
        }
    }
    else{
        my_strcpy(code,codeGenerator(code));
    }
    return code;
}

// function to get game attempt after option -t from user
int getAttempt(int mainAC, char ** mainAV,int attempt){
    if(mainAC==3){
        if(my_strcmp("-t",mainAV[1])==0){
            attempt=atoi(mainAV[2]);
        }
        else{
        attempt=10;
        }
    }
    else if(mainAC==5){
        if(my_strcmp("-t",mainAV[3])==0){
            attempt=atoi(mainAV[4]);
        }
        else if(my_strcmp("-t",mainAV[1])==0){
            attempt=atoi(mainAV[2]);
        }
    }
    else{
        attempt=10;
    }
    return attempt;
}


//function to compaire user guess code with secrete code, producing well placed and misplaced digit in the code
void codeGuessCompaire(char* guess, char* code){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(guess[j]==code[i]){
                if(i==j) welplaced++;
                else misplaced++;
            }
        }
    }
}
//function to test if user guess code have repeated digit
void codeRepeateTest(char * code){
    while(code[0]==code[1]||code[0]==code[2]||code[0]==code[3]||code[1]==code[2]||code[1]==code[3]||code[2]==code[3]){
        printf("Wrong input \n>");
        scanf("%s",code);
    }
}

//function to test if user guess code is valid
void codeTest(char* code){
    int i,test=0;
    while(test!=1){
        if(strlen(code)==4){
            for(i=0;i<strlen(code);i++){
                if(code[i]>=48 && code[i]<=55) test=1;
                else goto output;
            }
           codeRepeateTest(code);
        }
        else{
            output:
                printf("Wrong input \n>");
                scanf("%s",code);
        }
    }
}

//function that generate each round played using number of attempts
void roundGenerator(int attempt, char* code, char* guess)
{
    int round=0;
    while(round<=attempt){
        printf("--- \nRound %d \n>",round);
        scanf("%s",guess);
        codeTest(guess);
        if(my_strcmp(guess,code)==0){
            printf("\n * Congratulation! You found the secret code! * \n");
            break;
        }
        else{
            codeGuessCompaire(guess,code);
            printf("Well placed pieces: %d \n",welplaced);
            printf("Misplaced pieces: %d \n",misplaced);
            welplaced=0;
            misplaced=0;
            round++;
        }
        if(round-1==attempt) printf("\n\n  |**      GAME OVER       **| \n\n");
    }
}