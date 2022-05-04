#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include<dos.h>
#include<math.h>
#include <conio.h>
int main(void)
{
   int gdriver = DETECT, gmode, errorcode;
   int x1,y1,x2,y2,tx,ty,sx,sy;
   float theta;
   int ch,t[3][3]={{1,0,0},{0,1,0},{0,0,1}};
   int i,j,p[3],a[3];
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
   printf("enter line cords:");
   scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
   line(100+x1,100+y1,100+x2,100+y2)
   //delay(10000)
   printf("\n1.Translation\n2.Rotation\n3.Scaling\n4.Exit\n");
   scanf("%d",&ch);
   switch(ch);
   {
	case 1: printf("enter tx and ty:\n");
		scanf("%d %d",&tx,&ty);
		t[2][0]=tx;t[2][1]=ty;
		break;
	case 2:printf("Enter theta:\n");
		scanf("%d",&theta);
		printf("%d\n",theta);
		t[0][0]=ceil(cos(theta));t[0][1]=ceil(-sin(theta));
		printf("%d %d\n",t[0][0],t[0][1]);
		printf("%d\n",theta);
		printf("%lf\n",ceil(sin(90)));
		t[1][0]=ceil(sin(theta));t[1][1]=ceil(cos(theta));
		printf("%d %d\n",t[1][0],t[1][1]);
		break;
	case 3: printf("enter sx and sy:\n");
		scanf("%d %d",&tx,&ty);
		t[2][0]=tx;t[2][1]=ty;
		break
	default:break;
   }
		p[0]=x1;p[1]=y1;p[2]=1;
		i=0;j=0;a[0]=0;a[1]=0;a[2]=0;
		while(i<3)
		{
		  j=0;
		  while(j<3)
		  {
		    a[i]+=p[j]*t[j][i];
		    j++;
		  }i++
		}
		x1=a[0];y1=a[1];
		printf("x1:%d y1:%d\n",x1,y1);
		p[0]=x2;p[1]=y2;p[2]=1;
		i=0;j=0;a[0]=0;a[1]=0;a[2]=0;
		while(i<3)
		{ j=0;
		  while(j<3)
		  {
		    a[i]+=p[j]*t[j][i];
		    j++;
		  }i++;
		}
		x2=a[0];y2=a[1];
		printf("x2:%d y2:%d\n",x2,y2);
		line(100+x1,100+y1,100+x2,100+y2);
   getch();
}