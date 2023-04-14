/*
    Jose Aponte
    Exercise 3
*/

#include <stdio.h>

int main(){
    int characterAmount = 0;
    int wordsAmount = 0; 
    //int spaceAmount = 0;
    int newlineAmount = 0;
    int character;
    printf("********** Type the Text **********\n");
    character=getchar();
    while(character!=-1){
       // printf("%d\n",character);
        switch (character){
            case 32:
                while(character==32){
                    //printf("%d",character);
                    character = getchar();
                    //printf("1");
                }
                ++characterAmount;
            break;

            case 10:
                //printf("%d",character);
                ++newlineAmount;
                character = getchar();
            break;

            default:
                while((character!=32)&&(character!=10)){
                    ++characterAmount;
                    //printf("%d\n",character);
                    character = getchar();
                }
                ++wordsAmount;
            break;
        }
    }
printf("\n\nNumber of characters typed:\t%d\n",characterAmount);
printf("Number of word typed:\t\t%d\n",wordsAmount);
//printf("Number of spaces typed:\t\t%d\n",spaceAmount);
printf("Number of newline typed:\t%d\n",newlineAmount);
return 0;
}