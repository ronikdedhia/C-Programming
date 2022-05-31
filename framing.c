#include<stdio.h>
#include<conio.h>
int arr[30];
static int m=0;
void seperate(int n)
{
int z,i,c=0,arz[10];
while(n!=0)
{
z=n%10;
n=n/10;
arz[c]=z;
c=c+1;
}
c=c+1;
arr[m]=c;
m=m+1;
for(i=c-2;i>=0;i--)
{
arr[m]=arz[i];
m=m+1;
}
}
void main()
{
int n,num,i;
printf("Enter number of frames:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("Enter the frame data:");
scanf("%d",&num);
seperate(num);
}
printf("Data to be sent:");
for(i=0;i<m;i++)
{
printf("%d ",arr[i]);
}
getch();
}