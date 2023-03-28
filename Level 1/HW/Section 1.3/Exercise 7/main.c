/*
    Jose Aponte
    Exercise 7
    C-Program that efficiently multiplies a number by a factor 2
    to the power n. The number to multiply and n are variables,
    which get at vakue at the start of the program
*/

#include <stdio.h>

int main(){
    int numberToMultiply, nPower, result;
    numberToMultiply = 5;
    nPower = 3;
    result = numberToMultiply << nPower;
    printf("Result is: %d",result);
    return 0;
}