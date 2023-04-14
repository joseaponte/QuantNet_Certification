/*
    Jose Aponte
    Exercise 1.9.1

    Exercise 2
    Alter the last program of exercise 1 in such way that the output doesn't go to the screen
    but is written to a file. The file to write to must be specified by the user.
*/

#include <stdio.h>
#include <stdlib.h>                                 // stdlib.h include for dynamic memory
#include <string.h>                                 // 

const int MAX = 20;                                 // 20character maximum
const int ENTER = 10;                               // ENTER ASCII Value

int main(){
    int* charDisplay;                                       // Pointer to a dynamic array
    int i = 0;
    int j;
    FILE *filePointer;
    char nameFile[10];
    int avoid;

    charDisplay = (int*)malloc(MAX*sizeof(int));            // Memory allocation
    while((charDisplay[i]=getchar())!=1){
        if (charDisplay[i]==ENTER){
            printf("Introduce name of the file\n");
            scanf("%s",nameFile);
            strcat(nameFile,".txt");                        // It adds the extension to the file name
            filePointer = fopen(nameFile,"w+");             // w+ creates a new file and rewrite if exists
            if (filePointer == NULL){
                printf("File failed to open\n");
            }
            else{
                for(j=0;j<i;j++){
                    fprintf(filePointer,"%c",charDisplay[j]);   // Writing to the file
                }
            }
            printf("File was written successfully\n");
            fclose(filePointer);                                // Close the file
            free(charDisplay);                                  // Delete all info
            charDisplay = (int*)malloc(MAX*sizeof(int));        // Allocating memory
            i = 0;
            avoid = getchar();                                 // Added to avoid the program to misread ENTER
        }
        else{
            ++i;
        }
    }
    return 0;
}