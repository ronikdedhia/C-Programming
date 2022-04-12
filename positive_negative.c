#include <stdio.h>
/*
take a number from the user and check whether that number is either positive, negative or zero
*/
int main() {
    double num;
    printf("Enter a number: ");
    scanf("%lf", &num);

    if (num < 0.0)
        printf("You entered a negative number.");
    else if (num > 0.0)
        printf("You entered a positive number.");
    else
        printf("You entered 0.");

    return 0;
}

