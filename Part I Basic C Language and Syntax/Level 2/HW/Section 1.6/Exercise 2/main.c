/*
    Jose Aponte
    Exercise 1.6.2

    Create the two macros MAX2(x,y) and MAX3(x,y,z). These macros must return the
    maximum value of the given arguments. Let the macro MAX3 make use of the macro
    MAX2. Add these macros to the file “Defs.h”.
 
*/

#include <stdio.h>
#include "Defs.h"

int main(){
    int a, b, c;
    printf("\n********** Printing from Macros **********\n");
    printf("Introduce a -> ");
    scanf("%d",&a);
    printf("\nIntroduce b -> ");
    scanf("%d",&b);
    printf("\nIntroduce c -> ");
    scanf("%d",&c);
    printf("\nPrint maximum value between a and b\n");
    PRINT1(MAX2(a,b));
    printf("\nPrint maximum value between a,b and c\n");
    PRINT1(MAX3(a,b,c));
    return 0;
}