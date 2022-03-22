#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

int my_strcmp(char* s1, char* s2);//line 10  in function.c
char* my_strcpy(char* dst, char* src);// line 21
char * codeGenerator(char* num);// line 28
char * getCode(int mainAC, char ** mainAV, char* code);//line 47
int getAttempt(int mainAC, char ** mainAV,int attempt);// line 71
void codeGuessCompare(char* guess, char* code);// line 96
void codeRepeatTest(char * num);// line 108
void codeTest(char* code);// line 116
void roundGenerator(int round,char* code, char* guess); // line 135
#endif
