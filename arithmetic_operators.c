#include <stdio.h>
/*
arithmetic operator performs mathematical operations such as addition, subtraction, multiplication, division etc
 on numerical values (constants and variables).
*/
int main()
{
    int a = 9,b = 4, c;
    c = a+b;
    printf("a=9, b=4 \n");
    printf("a+b = %d \n",c);
    c = a-b;
    printf("a-b = %d \n",c);
    c = a*b;
    printf("a*b = %d \n",c);
    c = a/b;
    printf("a/b = %d \n",c);
    c = a%b;
    printf("a%b = %d \n",c);
    return 0;
}
