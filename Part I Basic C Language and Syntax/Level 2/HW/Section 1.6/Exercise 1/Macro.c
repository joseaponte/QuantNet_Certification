/*
    Jose Aponte
    Exercise 1.6.1
    The Preprocessor

    C-program that contains two print macro calls. The first prints 
    the variable a, the second prints the variable a and b. Printing
    happens by the use of the PRINT1 and PRINT2 macros that accept 
    arguments. These macros must be defined in an include-file.
    The variable a and b gets their value in the function main().
*/

#include <stdio.h>
#include "Defs.h"

int main(){
    int a, b;
    printf("\n********** Printing from Macros **********\n");
    printf("Introduce a -> ");
    scanf("%d",&a);
    printf("\nIntroduce b -> ");
    scanf("%d",&b);
    PRINT1(a);
    PRINT2(a,b);
    return 0;
}