/*
    Jose Aponte
    Exercise 1.6.1

    Header that includes two prints
*/

#include <stdio.h>

#ifndef DEFS_H  // Include these directives
#define DEFS_H  // to avoid prosible errors

// PRINT1 just print value of a
void PRINT1(int a){
    printf("\n----- PRINT1 Function -----\n");
    printf("%d",a);
}

// PRINT2 prints a and b
void PRINT2(int a, int b){
    printf("\n----- PRINT2 Function -----\n");
    printf("%d and %d\n",a,b);
}

#endif