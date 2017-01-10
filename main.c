/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Vaibhav Ariyur
 *
 * Created on January 5, 2017, 9:41 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strToInt(const char*s);
char* intToStr(int x);
int binaryToInt(const char*s);
/*
 * 
 */
//convert string to int

int main(int argc, char** argv) {
    int x=binaryToInt("10110110");
    printf("%d\n",x);

    return (EXIT_SUCCESS);
}

int strToInt(const char*s){
    int n=1;
    int sum=0;
    int i=strlen(s)-1;
    for(i;i>=0;i--){
        sum+=(s[i]-48)*n;
        n=n*10;
    }
    return(sum);
}

char* intToStr(int x){
    int greatestDigit=1;
    int count;
    count=1;
    while(1){
        if(x/greatestDigit<10){
          count++;
          break;}
        else{
          greatestDigit=greatestDigit*10;
          count++;
        }
    }
    char*numstr=calloc(count,sizeof(char));
    //null character has to be '\0'
    numstr[count-1]='\0';
    for(int i=0;i<count-1;i++){
        numstr[i]=(x/greatestDigit)+48;
        x%=greatestDigit; 
        greatestDigit/=10;
        
}
    return(numstr);
}
//time taken is 2n, or O(n);
int binaryToInt(const char*s){
    int n=1;
    int x=0;
    int p;
    int i=strlen(s)-1;
    for(i;i>0;i--){
        n*=2;
    }
    for(i=strlen(s)-1;i>=0;i--){
        p=(s[i]-'0')*n;
        n/=2;
        x+=p;
    }
    return(x);
}    

