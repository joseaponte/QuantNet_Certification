/* Assignment operators */
#include <stdio.h>
int main()
{
int x=2;
int y; int z;
     x*=3+2;
     /*
        x=x*5 => x=10
     */
     printf("x=%d\n", x);
     x*=y=z=4;
     /*
        x=x*4 => x=10*4 = 40
     */
     printf("x=%d\n", x);
     x=y==z;
     /*
        y == z = True = 1 => x = 1
     */
     printf("x=%d\n", x);
return 0; }