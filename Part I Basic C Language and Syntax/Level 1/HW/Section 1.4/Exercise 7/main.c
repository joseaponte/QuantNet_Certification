/* 
    Jose Aponte
    Exercise 7
    This program is an extension of the exercise 6 in such way
    that the frequency of number 3 is shown in words/
    E.g.: Number three appears two times.

    Only print the frequency when it is smaller than three. If
    the frequency is three or larger, then print: "The number 
    three appears more than two times"
*/

#include <stdio.h>

// Ascii equivalents
const int zero=48;
const int one=48;
const int two=48;
const int three=48;
const int zero=48;


#define newLine 10
#define space 32

#define getName(var)    #var

/*
    newline and space were added because they were counted
    in the default section.
*/

int main(){
    int number;
    int numberSmallerThanThree = 0; 
    int three = 0;
    int four = 0;
    int five = 0;
    int six = 0;
    int seven = 0;
    int eightNumber = 0;
    int nineNumber = 0;

    do{
        number = getchar();
        switch (number){
            case EOF:
                break;
            case zero...two:
                ++numberSmallerThanThree;
                break;
            case three:
                ++threeNumber;
                break;
            case four:
                ++fourNumber;
                break;
            case five:
                ++fiveNumber;
                break;
            case six:
                ++sixNumber;
                break;
            case seven:
                ++sevenNumber;
                break;
            case eight:
                ++eightNumber;
                break;
            case nine:
                ++nineNumber;
                break;
            default:
                break;
        }
    }while(number!=EOF);



    printf("\n%d\n", numberSmallerThanThree);
    printf("The number three appears more than %s times\n", getName(threeNumber));
    printf("The number four appears more than %d times\n", fourNumber);
    printf("The number five appears more than %d times\n", fiveNumber);
    printf("The number six appears more than %d times\n", sixNumber);
    printf("The number seven appears more than %d times\n", sevenNumber);
    printf("The number eight appears more than %d times\n", eightNumber);
    printf("The number nine appears more than %d times\n", nineNumber);

    return 0;
}