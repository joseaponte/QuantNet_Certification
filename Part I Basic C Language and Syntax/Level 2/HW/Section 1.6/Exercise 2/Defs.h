/*
    Jose Aponte
    Exercise 1.6.2

    Header that includes two prints and the max 
    between 2 numbers
*/

#include <stdio.h>

#ifndef DEFS_H  // Include these directives
#define DEFS_H  // to avoid prosible errors

// PRINT1 just print value of a
void PRINT1(int a){
    printf("\n----- PRINT1 Function -----\n");
    printf("%d\n",a);
}

// PRINT2 prints a and b
void PRINT2(int a, int b){
    printf("\n----- PRINT2 Function -----\n");
    printf("%d and %d\n",a,b);
}

// MAX2 returns the biggest value between
// x and y
int MAX2(int x, int y){
    return (x>y? x:y);
}

// MAX3 returns the biggest value between
// x, y and z
int MAX3(int x, int y, int z){
    return (MAX2(x,y)>z?MAX2(x,y):z);
}

#endif