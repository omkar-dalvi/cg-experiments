#include <graphics.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{   
   int gdriver = DETECT, gmode;
   initgraph(&gdriver, &gmode, "C:\\TurboC3\\BGI");
   setcolor(50);
   int i;
   for(i=1; i<=7; i++)
    printf("\n");
   for(i=1; i<=7; i++)
    printf("\t");
    printf("Welcome to CG Lab!!!!!");
   /* draw a line */
   circle(150,150,30);
   circle(250,220,200);
   circle(320,150,30);
   arc(250,250,180,0,100);
   rectangle(100,100,200,200);
   rectangle(370,100,270,200);
   
   getch();
   closegraph();
   return 0;
}
