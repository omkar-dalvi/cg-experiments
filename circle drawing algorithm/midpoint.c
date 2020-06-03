Midpoint circle
#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
    void
    main()
{
  int xc, yc, r, x, y, gd = DETECT, gm;
  float m;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the radius:");
  scanf("%d", &r);
  printf("\n Enter the centre co-ordinate:");
  scanf("%d %d", &xc, &yc);
  x = 0;
  y = r;
  m = (5 / 4) - r;
  while (x <= y)
  {
    delay(20);
    putpixel(xc + x, yc + y, 10);
    putpixel(xc + x, yc - y, 10);
    putpixel(xc - x, yc + y, 10);
    putpixel(xc - x, yc - y, 10);
    putpixel(xc + y, yc + x, 10);
    putpixel(xc + y, yc - x, 10);
    putpixel(xc - y, yc + x, 10);
    putpixel(xc - y, yc - x, 10);
    if (m < 0)
      m = m + 2 * x + 3;
    else
    {
      m = m + 2 * (x - y) + 5;
      y--;
    }
    x++;
  }
  getch();
  closegraph();
}
