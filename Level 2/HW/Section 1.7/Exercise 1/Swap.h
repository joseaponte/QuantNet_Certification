/*
    Jose Aponte
    Exercise 1.7.1
    The header file contains the funtion swap().
    This function must exchange the value of two 
    variables. 
*/

#include <stdio.h>

#ifndef SWAP_H
#define SWAP_H

void swap(int *i,int *j){
    int temp;
    temp =* i;
    *i = *j;
    *j = temp;
}

#endif