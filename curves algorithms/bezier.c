#include <stdio.h>
#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#define MAX 10

void main()
{
  int gd = DETECT, gm, i, n, x[MAX], y[MAX], px, py;
  double u;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the no. of control points:");
  scanf("%d", &n);
  printf("\n Enter the co-ordinates:");
  for (i = 0; i < n; i++)
  {
    scanf("%d %d", &x[i], &y[i]);
    putpixel(x[i], y[i], GREEN);
  }
  for (u = 0.0; u <= 1.0; u += 0.001)
  {
    px = (1 - u) * (1 - u) * (1 - u) * x[0] + 3 * (1 - u) * (1 - u) * u * x[1] + 3 * (1 - u) * u * u * x[2] + u * u * u * x[3];
    py = (1 - u) * (1 - u) * (1 - u) * y[0] + 3 * (1 - u) * (1 - u) * u * y[1] + 3 * (1 - u) * u * u * y[2] + u * u * u * y[3];

    putpixel(px, py, WHITE);
    delay(2);
  }

  getch();
  closegraph();
}
