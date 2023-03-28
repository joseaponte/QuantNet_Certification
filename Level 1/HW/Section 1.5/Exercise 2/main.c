/*
    Jose Aponte
    Exercise 1.5.2
    C-program that prints the factorial of a number (recursive function)
*/

#include <stdio.h>

int factorial(int number){
    if(number>1){
        return number*factorial(number-1);
    }
    else
        return 1;
};

int main(){
    int factorialNumber;
    printf("\nIntroduce number to be calculated its factorial\n");
    scanf("%d",&factorialNumber);
    printf("The factorial result of %d! is %d\n",factorialNumber,factorial(factorialNumber));
    return 0;
}