#include<stdio.h>
/*
temp variable is assigned the value of the first variable
then the value of the first variable is assigned to the second variable
finally the temp (which holds the initial value of first) is assigned to second. This completes the swapping process.
*/
/*
we can swap two numbers without using third variable by using + and -
*/
int main() {
  int a=50, b=100, temp;
  temp = a;
  a = b;
  b = temp;
  printf("\nAfter swapping, first number = %d\n", a);
  printf("After swapping, second number = %d", b);
  a=a+b;
  b=a-b;
  a=a-b;
  printf("\nAfter swap a=%d b=%d",a,b);
  return 0;
}
