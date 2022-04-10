#include <stdio.h>
/*
generate multiplication tables up to 10
*/
int main() {
  int n=9, i;
  for (i = 1; i <= 10; ++i) {
    printf("%d * %d = %d \n", n, i, n * i);
  }
  return 0;
}

