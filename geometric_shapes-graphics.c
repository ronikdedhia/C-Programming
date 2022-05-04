#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int x1, y1, rad, rad1, rad2;
   int gdriver = DETECT, gmode, errorcode;
   int xmax, ymax;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
//   rectangle(190,150,400,230);
   line(170,150,420,150);
   line(170,150,100,230);
   line(420,150,500,230);
   rectangle(100,230,500,300);
   circle(185,335,35);
   circle(405,335,35);
   line(170,150,170,230);
   line(420,150,420,230);
//   rectangle(190,175,400,200);
   circle(475,250,7);
   circle(475,280,7);
   line(0,370,getmaxx(),370);
   /* clean up */
   getch();
   closegraph();
   return 0;
}

