#include<stdio.h>
/*
basic salary is input through the keyboard
dearness allowance is 40% of basic salary
house rent allowance is 20% of basic salary
calculate gross salary.
*/
int main()
{
    float bs, hra, da, gs;
    printf("Enter basic salary\n");
    scanf("%f", &bs);
    hra = bs * (0.2);
    da  = bs * (0.4);
    gs  = bs + hra + da;
    printf("Gross Salary = %f\n", gs);
    return 0;
}
