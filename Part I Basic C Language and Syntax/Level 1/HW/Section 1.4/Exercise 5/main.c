/*
    Jose Aponte
    Exercise 5
    C-program that prints two columns on the screen with the temperature in degrees 
    Celsius and the equivalent temperature in degrees Farenheit.
*/

#include <stdio.h>

#define START 0
#define END 19

int main(){
    float farenheit = START;
    float celsius;
    printf("********** Temperature Conversion **********\n");
    printf("\tCelsius\t\tFarenheit\n");

    for(celsius=0;celsius<=END;++celsius){
        farenheit = (9*celsius)/5+32;
        printf("   %10.1f\t    %10.1f\n",celsius,farenheit);
    }
    return 0;
}