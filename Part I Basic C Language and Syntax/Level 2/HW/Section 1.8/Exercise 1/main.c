/*
    Jose Aponte
    Exercise 1.8.1

    Write a C-program that prints the contents of a struct called Article. 
    An Article has the following characteristics:
        • Article number
        • Quantity
        • Description (20 characters)
    The test program must create an Article of which the contents are assigned 
    at initialization level. Printing the Article is done with a Print() function.
    This function gets the address of the structure as a parameter.
    Tip: Suppose that p is the pointer to the structure. It will allow the fields 
    to be printed by (*p).fieldname or p->fieldname.
*/

#include <stdio.h>

const int MAX = 20;

/***** Structure *****/
struct Article{
    int articleNumber;
    int quantity;
    char description[MAX];
};

/***** Print Function *****/
void Print(struct Article* a)
{
    printf("\nArticle number: \t%d\n",a->articleNumber);
    printf("Quantity = \t\t%d\n",a->quantity);
    printf("Description = %s\n", a->description);
};

/***** Main Program *****/
int main(){
    struct Article article;
    int i=0;
    int c;
    printf("Introduce Article Number: ");
    scanf("%d", &article.articleNumber);
    printf("Introduce Quantity: ");
    scanf("%d",&article.quantity);
    printf("Introduce Description: ");
    while ((c=getchar())!=EOF && i < MAX){  
        article.description[i++] = (char)c;
    }

    Print(&article);    
    return 0;
    
}