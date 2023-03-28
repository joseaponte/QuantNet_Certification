/*
    Jose Aponte
    Exercise 1.5.4
    A recursive function printnumber() wich gets the number 
    to be printed. This number is an integer. The function
    should print the number digit by digit by using the putchar()
    function. Do not use printf()
*/

#include <stdio.h>

void printnumber(int n){
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n / 10 != 0)
        printnumber(n / 10);
    putchar((n % 10) + '0');
}

int main(){
    int number;
    scanf("%d",&number);
    printf("The printed number digit by digit is: \n");
    printnumber(number);
    return 0;
}
