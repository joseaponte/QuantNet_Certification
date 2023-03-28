/*
    Jose Aponte
    Exercise 1.5.3
    The main.c contains the main() function and gives i a value
*/

#include <stdio.h>
#include "print.c"

int main(){
    int numberToMultiply;
    printf("Introduce the number to be multiply by 2\n");
    scanf("%d",&numberToMultiply);
    print(numberToMultiply);
    return 0;
}