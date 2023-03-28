/*
    Jose Aponte
    Exercise 1.4.1
    C-program that asks for text input from the keyboard. The output 
    of this program should be the amount of characters, the amount of 
    words and the amount of newlines that have been typed. Multipe 
    consecutive spaces should not be coundted as multiple words
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
    while(character!=-1){
        if(character==32){
            while (character == 32){
                character = getchar();
            }
            ++characterAmount;    
        }
        else if(character==10){
            ++newlineAmount;
            character = getchar();
        }
        else{
            while ((character !=32)&&(character!=10)){
                    ++characterAmount;
                    character=getchar();
                    //printf("1");
                } 
                ++wordsAmount;
        }    
    }
    printf("\n\nNumber of characters typed:\t%d\n",characterAmount);
    printf("Number of word typed:\t\t%d\n",wordsAmount);
   // printf("Number of spaces typed:\t\t%d\n",spaceAmount);
    printf("Number of newline typed:\t%d\n",newlineAmount);
    return 0;
}
