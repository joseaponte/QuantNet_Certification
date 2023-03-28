/*
    Jose Aponte
    Exercise 1.9.1

    Exercise 1
    Create a C-program that reads the characters from the 
    keyboard and shows them on screen (the inputted characters
    should only be displayed when the user hits 'enter', line
    by line). When ^A is entered, the program must end properly. 
    Then the following message will appear: “CTRL + A is
    a correct ending.”
    
    Tip: getchar() reads and putchar() writes the type int. 
    The value of ^A is 1.
*/

#include <stdio.h>
#include <stdlib.h>                                 // stdlib.h include for 
                                                    // dynamic memory
const int MAX = 100;                                // 100 character maximum
const int ENTER = 10;                               // ENTER ASCII Value

int main(){
    int* charDisplay;                                       // Pointer to a dynamic array
    int i = 0;
    int j;
    charDisplay = (int*)malloc(MAX*sizeof(int));            // Memory allocation
    while (((charDisplay[i]=getchar())!=1)){                // The while loop makes the program
        if (charDisplay[i] == ENTER){                       // to continue untl ^A is pressed.
            printf("\n");
            for(j=0;j<i;j++){
                putchar(charDisplay[j]);                    // Print 
            }
            free(charDisplay);                              // Free Array memory
            charDisplay = (int*)malloc(MAX*sizeof(int));    // Allocate memory
            j=0;
            i = 0;
            printf("\n");
        }
        ++i;
    }
    return 0;    
}