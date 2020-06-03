#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <graphics.h>

void floodfill4(int x, int y, int newcolor, int oldcolor)
{
  if (getpixel(x, y) == oldcolor)
  {
    setcolor(newcolor);
    putpixel(x, y, newcolor);
    floodfill4(x + 1, y, newcolor, oldcolor);
    floodfill4(x - 1, y, newcolor, oldcolor);
    floodfill4(x, y + 1, newcolor, oldcolor);
    floodfill4(x, y - 1, newcolor, oldcolor);
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  setcolor(50);
  circle(350, 350, 30);
  setcolor(30);
  circle(380, 350, 30);
  setcolor(20);
  circle(370, 380, 30);
  floodfill4(370, 360, 60, 0);
  floodfill4(340, 350, 15, 0);
  getch();
  closegraph();
}
