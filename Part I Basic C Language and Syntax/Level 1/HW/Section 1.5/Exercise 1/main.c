/*
    Jose Aponte
    Exercise 1.5.1
    C-Program that calls a function minus(). This function
    receives two arguments and returns the difference (regular
    subtraction, not absolute). This difference should be 
    printed on screen 
*/

#include <stdio.h>

int minus(int minuend, int subtrahend){
   return minuend - subtrahend; 
};

int main(){
    int minuendNumber;
    int subtrahendNumber;
    printf("\nIntroduce numbers to be sustracted\n");
    scanf("%d",&minuendNumber);
    scanf("%d",&subtrahendNumber);
    printf("The result is %d\n", minus(minuendNumber, subtrahendNumber));
    return 0;
}