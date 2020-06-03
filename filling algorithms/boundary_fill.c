#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void boundaryfill4(int x, int y, int fillcolor, int boundary)
{
  int current;
  current = getpixel(x, y);
  if (current != boundary && current != fillcolor)
  {
    setcolor(fillcolor);
    putpixel(x, y, fillcolor);
    boundaryfill4(x - 1, y, fillcolor, boundary);
    boundaryfill4(x + 1, y, fillcolor, boundary);
    boundaryfill4(x, y - 1, fillcolor, boundary);
    boundaryfill4(x, y + 1, fillcolor, boundary);
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  // setcolor(60);
  circle(300, 300, 30);
  // circle(320,300,30);
  // circle(310,320,30);
  boundaryfill4(300, 300, 15, 1);
  getch();
  closegraph();
}
