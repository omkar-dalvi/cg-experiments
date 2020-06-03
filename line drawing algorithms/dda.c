#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
void main()
{
  int x1, y1, x2, y2, dx, dy, gd = DETECT, gm, i;
  float L, xincr, yincr, xnew, ynew;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the co-ordinates of endpoints of the line:");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  dx = x2 - x1;
  dy = y2 - y1;
  if (abs(dx) > abs(dy))
    L = dx;
  else
    L = dy;
  xincr = dx / L;
  yincr = dy / L;
  xnew = x1 + 0.5;
  ynew = y1 + 0.5;
  putpixel((int)xnew, (int)ynew, 10);
  i = 1;
  while (i <= L)
  {
    delay(10);
    xnew = xnew + xincr;
    ynew = ynew + yincr;
    putpixel((int)xnew, (int)ynew, 10);
    i++;
  }

  getch();
  closegraph();
}
