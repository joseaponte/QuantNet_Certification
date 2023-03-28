/*
    Jose Aponte
    Exercise 1.7.1
    This program swap the value between 2 variables using pointers
*/

#include <stdio.h>
#include "Swap.h"

int main(){
    int i,j;
    int *ptr_i=&i;              // Pointer that points the address of i
    int *ptr_j=&j;              // Pointer that points the address of j
    printf("\n***** Swap Value Between 2 Variables *****\n");
    printf("Value of i = ");
    scanf("%d", &i);
    printf("Value of j = ");
    scanf("%d", &j);
    swap(ptr_i,ptr_j);          //Passing the pointers to the function
    printf("The new values are i= %d and j= %d\n", i,j);
    return 0;
}