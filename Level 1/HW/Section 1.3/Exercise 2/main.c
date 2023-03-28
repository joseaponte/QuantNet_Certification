/*
    Jose Aponte HW 1.2
    Right Triangle Surface Calculator
*/

#include <stdio.h>

// Function
float surface(float fbase, float fheight){
    return fbase*fheight*0.5;
}

// Main
int main (){
    float base, height, surfaceResult;
    printf("***** Triangle Surface Calculator *****\n");
    printf("Introduce base\n");
    scanf("%f",&base);
    printf("Introduce height\n");
    scanf("%f",&height);
    surfaceResult = surface(base,height);
    printf("Result is = %.2f\n" ,surfaceResult);

    return 0;
}