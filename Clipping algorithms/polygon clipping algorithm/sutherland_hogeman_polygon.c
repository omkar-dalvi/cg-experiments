#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define MAX 10
#define INF 32767000
int k;
float xmin, ymin, xmax, ymax, , arr[MAX];
void clipl(float x1, float y1, float x2, float y2)
{
  float m;
  if (x2 - x1 != 0)
    m = (y2 - y1) / (x2 - x1);
  else
    m = INF;
  //Inside to inside
  if (x1 >= xmin && x2 >= xmin)
  {
    arr[k] = x2;
    arr[k + 1] = y2;
    k += 2;
  }
  //Inside to outside
  if (x1 >= xmin && x2 < xmin)
  {
    arr[k] = xmin;
    arr[k + 1] = y1 + m * (xmin - x1);
    k += 2;
  }
  //Outside to inside
  if (x1 < xmin && x2 >= xmin)
  {
    arr[k] = xmin;
    arr[k + 1] = y1 + m * (xmin - x1);
    arr[k + 2] = x2;
    arr[k + 3] = y2;
    k += 4;
  }
}

void clipt(float x1, float y1, float x2, float y2)
{
  float m;
  if (y2 - y1 != 0)
    m = (x2 - x1) / (y2 - y1);
  else
    m = INF;
  //Inside to inside
  if (y1 >= ymax && y2 >= ymax)
  {
    arr[k] = x2;
    arr[k + 1] = y2;
    k += 2;
  }
  //Outside to inside
  if (y1 < ymax && y2 >= ymax)
  {
    arr[k] = x1 + (ymax - y1) * m;
    arr[k + 1] = ymax;
    arr[k + 2] = x2;
    arr[k + 3] = y2;
    k += 4;
  }

  //Inside to outside
  if (y1 >= ymax && y2 < ymax)
  {
    arr[k] = x1 + m * (ymax - y1);
    arr[k + 1] = ymax;
    k += 2;
  }
}

void clipr(float x1, float y1, float x2, float y2)
{
  float m;
  if (x2 - x1 != 0)
    m = (y2 - y1) / (x2 - x1);
  if (x1 <= xmax && x2 <= xmax)
  {
    arr[k] = x2;
    arr[k + 1] = y2;
    k += 2;
  }

  if (x1 <= xmax && x2 > xmax)
  {
    arr[k] = xmax;
    arr[k + 1] = y1 + m * (xmax - x1);
    k += 2;
  }
  if (x1 > xmax && x2 <= xmax)
  {
    arr[k] = xmax;
    arr[k + 1] = y1 + m * (xmax - x1);
    arr[k + 2] = x2;
    arr[k + 3] = y2;
    k += 4;
  }
}

void clipb(float x1, float y1, float x2, float y2)
{
  float m;
  if (y2 - y1 != 0)
    m = (x2 - x1) / (y2 - y1);
  else
    m = INF;
  if (y1 <= ymin && y2 <= ymin)
  {
    arr[k] = x2;
    arr[k + 1] = y2;
    k += 2;
  }
  if (y1 > ymin && y2 <= ymin)
  {
    arr[k] = x1 + m * (ymin - y1);
    arr[k + 1] = ymin;
    arr[k + 2] = x2;
    arr[k + 3] = y2;
    k += 4;
  }
  if (y1 <= ymin && y2 > ymin)
  {
    arr[k] = x1 + m * (ymin - y1);
    arr[k + 1] = ymin;
    k += 2;
  }
}

void main()

{
  int i, j, gd = DETECT, gm, n, poly[MAX];
  float polyt[MAX];
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the bottom left corner of clipping window:");
  scanf("%f %f", &xmin, &ymin);

  printf("\n Enter the top right corner of clipping window:");
  scanf("%f %f", &xmax, &ymax);
  rectangle(xmin, ymin, xmax, ymax);
  printf("\n Enter the no. of lines:");
  scanf("%d", &n);
  printf("\n Enter the co-ordinates of the polygon:");
  //Storing the co-ordinates in one array
  for (i = 0; i < 2 * n; i++)
    scanf("%f", &polyt[i]);
  //The last point will be the first point
  polyt[i] = polyt[0];
  polyt[i + 1] = polyt[1];
  //Storing in another array for reference
  for (i = 0; i < 2 * n + 2; i++)
    poly[i] = (int)(polyt[i] + 0.5);
  clrscr();
  printf("\n Before clipping");
  setcolor(RED);
  rectangle(xmin, ymin, xmax, ymax);
  setcolor(WHITE);
  fillpoly(n, poly);
  getch();
  clrscr();
  k = 0;
  for (i = 0; i < 2 * n; i += 2)
    clipl(polyt[i], polyt[i + 1], polyt[i + 2], polyt[i + 3]);
  //Since k considers x and y as different and n considers it as one we have to divide it //by 2
  n = k / 2;
  for (i = 0; i < k; i++)
    polyt[i] = arr[i];
  polyt[i] = polyt[0];
  polyt[i + 1] = polyt[1];

  k = 0;
  for (i = 0; i < 2 * n; i += 2)
    clipt(polyt[i], polyt[i + 1], polyt[i + 2], polyt[i + 3]);
  n = k / 2;
  for (i = 0; i < k; i++)
    polyt[i] = arr[i];
  polyt[i] = polyt[0];
  polyt[i + 1] = polyt[1];

  k = 0;
  for (i = 0; i < 2 * n; i += 2)
    clipr(polyt[i], polyt[i + 1], polyt[i + 2], polyt[i + 3]);
  n = k / 2;
  for (i = 0; i < k; i++)
    polyt[i] = arr[i];
  polyt[i] = polyt[0];
  polyt[i + 1] = polyt[1];

  k = 0;
  for (i = 0; i < 2 * n; i += 2)
    clipb(polyt[i], polyt[i + 1], polyt[i + 2], polyt[i + 3]);
  for (i = 0; i < k; i++)
    poly[i] = (int)(arr[i] + 0.5);
  printf("%d", poly[i]);

  if (k)
  {

    setcolor(RED);
    rectangle(xmin, ymin, xmax, ymax);
    setcolor(WHITE);
    fillpoly(k / 2, poly);
    printf("\n After clipping");
  }

  getch();

  closegraph();
}
