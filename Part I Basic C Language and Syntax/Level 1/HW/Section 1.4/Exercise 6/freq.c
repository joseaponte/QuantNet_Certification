/*
    Jose Aponte
    Exercise 6
    C-programm that counts how many times each of the numbers 0-4 have been
    typed. Use a switch-case construction. Use Default to count the number of
    the characters.
*/

#include <stdio.h>

// Ascii equivalents
#define zero 48
#define one 49
#define two 50
#define three 51
#define four 52
#define newLine 10
#define space 32

/*
    newline and space were added because they were counted
    in the default section.
*/

int main(){
    int number;
    int zeroCounter = 0; 
    int oneCounter = 0;
    int twoCounter = 0; 
    int threeCounter = 0;  
    int fourCounter = 0;
    int everythingElse = 0;

    do{
        number = getchar();
        switch (number){
            case EOF:
                break;
            case zero:
                ++zeroCounter;
                break;
            case one:
                ++oneCounter;
                break;
            case two:
                ++twoCounter;
                break;
            case three:
                ++threeCounter;
                break;
            case four:
                ++fourCounter;
                break;
            case newLine:
                break;
            case space:
                break;
            default:
                everythingElse++;
                break;
        }
    }while(number!=EOF);
    printf("Zero was pressed\t%d\n", zeroCounter);
    printf("One was pressed\t\t%d\n", oneCounter);
    printf("Two was pressed\t\t%d\n", twoCounter);
    printf("Three was pressed\t%d\n", threeCounter);
    printf("Four was pressed\t%d\n", fourCounter);
    printf("Else was pressed\t%d\n", everythingElse);
    return 0;
}