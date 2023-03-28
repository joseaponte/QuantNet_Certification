/*
    Jose Aponte
    Exercise 4
    C-program that prints two columns on the screen with the temperature in degrees 
    Farenheit and the equivalent temperature in degrees celsius.
*/

#include <stdio.h>

#define START 0
#define END 300

int main(){
    float farenheit = START;
    float celsius;
    printf("********** Temperature Conversion **********\n");
    printf("\tFarenheit\t\tCelsius\n");
    while(farenheit<=END){
        celsius = ((farenheit-32)*5)/9;
        printf("\t%10.1f\t\t%10.1f\n",farenheit,celsius);
        farenheit+=20;
    }
    return 0;
}