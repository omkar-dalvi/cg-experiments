#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
void koch(int x1, int y1, int x2, int y2, int it)
{
  float angle;
  int x3, y3, x4, y4, x, y;
  angle = 60 * M_PI / 180;
  x3 = (2 * x1 + x2) / 3;
  y3 = (2 * y1 + y2) / 3;
  x4 = (x1 + 2 * x2) / 3;
  y4 = (y1 + 2 * y2) / 3;
  x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
  y = y3 + (y4 - y3) * cos(angle) - (x4 - x3) * sin(angle);
  if (it > 0)
  {
    koch(x1, y1, x3, y3, it - 1);
    koch(x3, y3, x, y, it - 1);
    koch(x, y, x4, y4, it - 1);
    koch(x4, y4, x2, y2, it - 1);
  }
  else
  {
    line(x1, y1, x3, y3);
    line(x3, y3, x, y);
    line(x, y, x4, y4);
    line(x4, y4, x2, y2);
  }
}
void main()
{
  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  koch(100, 100, 400, 400, 4);
  getch();
  closegraph();
}
