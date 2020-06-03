#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
void main()
{
  int x1, y1, x2, y2, dx, dy, gd = DETECT, gm, i, x, y;
  float e;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the co-ordinates of the endpoints:");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  dx = x2 - x1;
  dy = y2 - y1;
  x = x1;
  y = y1;
  e = (float)(dy / dx) - 0.5;
  for (i = 0; i <= dx; i++)
  {
    delay(20);
    putpixel(x, y, 10);
    while (e >= 0)
    {
      y++;
      e--;
    }
    x++;
    e += (float)(dy / dx);
  }
  getch();
  closegraph();
}
