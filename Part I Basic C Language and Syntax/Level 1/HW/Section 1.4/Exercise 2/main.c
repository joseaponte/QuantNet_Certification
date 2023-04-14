/*
    Jose Aponte
    Exercise 1.4.2
    C-program that asks for text input from the keyboard. The output 
    of this program should be the amount of characters, the amount of 
    words and the amount of newlines that have been typed. Multipe 
    consecutive spaces should not be coundted as multiple words. Use do-while
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int characterAmount = 0;
    int wordsAmount = 0; 
   // int spaceAmount = 0;
    int newlineAmount = 0;
    char character;
    printf("********** Type the Text **********\n");
    character = getchar();
    do{
        if(character==32){
            do{
                character = getchar();
            }while (character == 32);
            ++characterAmount;   
        }
        else if(character==10){
            ++newlineAmount;
            character = getchar();
        }
        else{
            do{
                ++characterAmount;
                character=getchar();
            }while((character !=32)&&(character!=10));
            ++wordsAmount;
        }
    }while(character!=-1);
    printf("\n\nNumber of characters typed:\t%d\n",characterAmount);
    printf("Number of word typed:\t\t%d\n",wordsAmount);
    //printf("Number of spaces typed:\t\t%d\n",spaceAmount);
    printf("Number of newline typed:\t%d\n",newlineAmount);
    return 0;
}
