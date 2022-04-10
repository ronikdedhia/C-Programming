#include <stdio.h>
/*
performing calculator operations using switch case
*/
int main() {
    char operation;
    double n1, n2;
    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operation);
    switch(operation)
    {
        case '+':
            printf("Enter two operands: ");
            scanf("%lf %lf",&n1, &n2);
            printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
            break;

        case '-':
            printf("Enter two operands: ");
            scanf("%lf %lf",&n1, &n2);
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;

        case '*':
            printf("Enter two operands: ");
            scanf("%lf %lf",&n1, &n2);
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;

        case '/':
            printf("Enter two operands: ");
            scanf("%lf %lf",&n1, &n2);
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;

        default:
            printf("Error! operator is not correct");
    }
    return 0;
}
