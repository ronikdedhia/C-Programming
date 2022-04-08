#include <stdio.h>
/*
given the number of days, task is to convert the number of days in terms of years, weeks and days
*/
int main()
{
    int days, years, weeks;
    days = 1329;
    years = days/365;
    weeks = (days % 365)/7;
    days = days- ((years*365) + (weeks*7));
    printf("Years: %d\n", years);
    printf("Weeks: %d\n", weeks);
    printf("Days: %d \n", days);
    return 0;
}
