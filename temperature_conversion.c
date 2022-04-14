#include <stdio.h>
/*
program to convert Celsius to Fahrenheit temperature
*/
int main() {
    float c, f;
    printf("Enter the temperature in Celsius::\n");
    scanf("%f", &c);
    f = (c * 9 / 5) + 32;
    // c= (5.0/9) * (f - 32);
    printf("\n%f Celsius = %f Fahrenheit\n", c, f);
    return 0;
}
