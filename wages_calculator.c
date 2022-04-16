#include<stdio.h>
/*
calculate and print the total wage of labor on daily basis
Up to first 8 hours	50.00
For next 4 hours	10.00 per hour extra
For next 4 hours	20.00 per hour extra
For next 4 hours	25.00 per hour extra
For next 4 hours	40.00 per hour extra
*/
int main()
{
    float initWage=50, hours, tempHour, tempWage, totalWage;
    printf("Enter total hours worked: \t");
    scanf("%f", &hours);
    if(hours<=8)
        totalWage = initWage;
    else if(hours>8 && hours<=12)
    {
        tempHour = hours-8;
        tempWage = tempHour*10;
        totalWage = tempWage + initWage;
    }
    else if(hours>12 && hours<=16)
    {
        tempHour = hours-12;
        tempWage = 4*10;
        totalWage = initWage + tempWage + (tempHour*20);
    }
    else if(hours>16 && hours<=20)
    {
        tempHour = hours-16;
        tempWage = (4*10) + (4*20);
        totalWage = initWage + tempWage + (tempHour*25);
    }
    else if(hours>20 && hours<=24)
    {
        tempHour = hours-20;
        tempWage = (4*10) + (4*20) + (4*25);
        totalWage = initWage + tempWage + (tempHour*40);
    }
    else
    {
        printf("A single day only has 24 hours.");
    }
    printf("\nTotal Wage: \t\t\t%0.2f", totalWage);
    return 0;
}
