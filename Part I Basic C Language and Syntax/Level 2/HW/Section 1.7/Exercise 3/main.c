/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) )
#define NL          printf("\n");
// Create and initialse array
int a[]={0, 1, 2, 3, 4};
int main(){
     int i;
     int* p;
     for (i=0; i<=4; i++) PRD(a[i]);                   // 0 1 2 3 4
     NL;
     for (p=&a[0]; p<=&a[4]; p++) PRD(*p);             // 0 1 2 3 4
     NL;
     NL;
     for (p=&a[0], i=0; i<=4; i++) PRD(p[i]);          // 0 1 2 3 4
     NL;
     for (p=a, i=0; p+i<=a+4; p++, i++) PRD(*(p+i));   // 0 2 4
     NL;
     NL;
     for (p=a+4; p>=a; p--) PRD(*p);                   // 4 3 2 1 0
     NL;
     for (p=a+4, i=0; i<=4; i++) PRD(p[-i]);           // 4 3 2 1 0
     NL;
     for (p=a+4; p>=a; p--) PRD(a[p-a]);               // 4 3 2 1 0
     NL;
     return 0; 
}