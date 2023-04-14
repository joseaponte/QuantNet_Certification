/*
    Jose Aponte
    Homework 6
    C-program that shifts any number two places to the right.
*/

#include <stdio.h>

int main()
{
    int toBeShifted;
    int shifted;
    printf("Introduce number to be shifted\n");
    scanf("%d",&toBeShifted);
    shifted = toBeShifted >> 2;
    printf("Shifted number: %d\n",shifted);
    return 0;
}