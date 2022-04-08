#include<stdio.h>
/*
given a number, check if it is divisible by 7 or not
*/
int main()
{
  int i,n=7,a=100;
  printf("Numbers divisible by 7 are:");
  for(i=1;i<=a;i++)
  {
    if(i%7==0)
    {
      printf("\n%d",i);
    }
  }
  return 0;
}
