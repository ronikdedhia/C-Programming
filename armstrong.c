#include <stdio.h>
/*
for armstrong number of 3 digits, the sum of cubes of each digit is equal to the number itself
153 = 1*1*1 + 5*5*5 + 3*3*3
*/
int main() {
    int num, originalNum, remainder, result = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) {
       remainder = originalNum % 10;
       result += remainder * remainder * remainder;
       originalNum /= 10;
    }
    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
    return 0;
}
