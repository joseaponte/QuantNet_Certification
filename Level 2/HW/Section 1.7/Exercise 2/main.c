/*
    Jose Aponte
    Exercise 1.7.2

    Calculates the lenght of an array using pointers  
*/

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30

// String lenght declaration
int Length(char str[]);
int main(){
    char string[MAXLINE+1];  // Line of maxium 30 chars + \0
    int c;                   // The input character
    int i=0;                 // The counter
    
    // Print intro text
    printf("Type up to %d chars. Exit with ^D\n", MAXLINE);
    // On MacOS EOF is ^D instead of ^Z

    // Get the characters
    while ((c=getchar())!=EOF && i<MAXLINE) {
        string[i++]=(char)c;
    }
    string[i]='\0';          // String must be closed with \0

    printf("String length is %d\n", Length(string));
    return 0;
}
/* Implement the Length() function here */

int Length(char str[]){
    char *p = str;      // Pointer to str address
    int counter = 0;
    while(p[counter]!='\0'){    // Iteration until the value is '\0'
        ++counter;
    }
    return counter;   // Size excluding '\0'
};