/*
    Jose Aponte
    Exercise 5
    Program that shows the difference between --i and i--
*/

#include <stdio.h>

int main(){
    int i = 10, j;
    j = i--;
    printf("After postfix decrement i=%d j=%d\t\n",i,j);
    i = 10;
    j = --i;
    printf("After prefix decrement i=%d j=%d\t\n",i,j);
    
    return 0;
}