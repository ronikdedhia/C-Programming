#include <stdio.h>
/*
input an alphabet and check whether it is vowel or consonant using switch case
*/
main()
{
  char ch;
  printf("Enter a character\n");
  scanf("%c", &ch);
  switch(ch)
  {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
      printf("%c is a vowel.\n", ch);
      break;
    default:
      printf("%c is a consonant.\n", ch);
  }
  return 0;
}
