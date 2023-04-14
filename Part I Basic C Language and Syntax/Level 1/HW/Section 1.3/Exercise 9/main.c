/* Conditional expressions */
#include <stdio.h>
int main()
{
int x=1;
     int y=1;
     int z=1;
     x+=y+=x;
     printf("%d\n\n", (x<y)?y:x);
     /*
        print x-> 3
     */
     printf("%d\n", (x<y)?x++:y++);
     /*
        print y++ -> 2
     */
     printf("%d\n", x);
     /*
        print x -> 3
     */
     printf("%d\n", y);
     /*
        print y -> 3
     */
return 0; }