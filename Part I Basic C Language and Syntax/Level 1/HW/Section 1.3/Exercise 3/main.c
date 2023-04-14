/* Operators */
#include <stdio.h>
int main()
{
    int x;
    x=-3+4*5-6;
     /*
         4*5 = 20
        -3-6 = -9
        20 - 9 = 11
    */ 
    printf("x=%d\n", x);
    x=3+4%5-6;
    /*
        4%5 = 4
        3-6 = -3
        4-3 = 1
    */
    printf("x=%d\n", x);
    x=-3*4%-6/5;
    /*
        -3*4 = -12
        -12%-6 = 0
        0 / 5 = 0
    */
    printf("x=%d\n", x);
    x=(7+6)%5/2;
    /*
        7+6 = 13
        13%5 = 3
        3/2 = 1
    */
    printf("x=%d\n", x);
    return 0; 
}