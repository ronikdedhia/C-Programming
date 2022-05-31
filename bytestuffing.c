#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
int i=0,j=0,n,pos;
char a[20],b[50],ch;
printf("Enter string: \n");
scanf("%s",&a);
n=strlen(a);
printf("Enter position:"); scanf("%d",&pos);
if(pos>n)
{
printf("Invalid position, Enter again:"); scanf("%d",&pos);
}
printf("Enter the character\n");
ch=getch();
b[0]='1';
b[1]='2';
b[2]='3';
b[3]='4';
b[4]='5';
b[5]='6';
j=6;
while(i<n)
{
if(i==pos-1)
{
b[j]='1';
b[j+1]='2';
b[j+2]='3';
b[j+3]=ch;
b[j+4]='4';
b[j+5]='5';
b[j+6]='6';
j=j+7;
}
if(a[i]=='d' && a[i+1]=='1' && a[i+2] =='e')
{
b[j] ='1';
b[j+1]='2';
b[j+2]='3';
j=j+3;
}
b[j]=a[i];
i++;
j++;
}
b[j]='1';
b[j+1]='2';
b[j+2]='3';
b[j+3] ='3';
b[j+4]='5';
b[j+5]='6';
b[j+6]='\0';
printf("\n Frames after character stuffing\n");
printf("%s",b);
getch();
}