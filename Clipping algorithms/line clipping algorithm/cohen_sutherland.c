#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#define MAX 10

void main()
{
  int gd = DETECT, gm, x1, y1, x2, y2, xmin, ymin, xmax, ymax, start[MAX], end[MAX], i, code[MAX];
  float m;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the bottom left corner co-ordinates of clipping window:");
  scanf("%d %d", &xmin, &ymin);
  printf("\n Enter the top right corner co-ordinates of clipping window:");
  scanf("%d %d", &xmax, &ymax);
  printf("\n Enter the co-ordinates of endpoints of the line:");
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  //Calculating m
  m = (y2 - y1) / (x2 - x1);
  //Initializing the arrays to 0
  for (i = 0; i < 4; i++)
  {
    start[i] = 0;
    end[i] = 0;
  }
  //Assigning opcodes to endpoints
  if (x1 < xmin)
    start[0] = 1;
  if (x1 > xmax)
    start[1] = 1;
  if (y1 < ymin)
    start[2] = 1;
  if (y1 > ymax)
    start[3] = 1;
  if (x2 < xmin)
    end[0] = 1;
  if (x2 > xmax)
    end[1] = 1;
  if (y2 < ymin)
    end[2] = 1;
  if (y2 > ymax)
    end[3] = 1;

  //Calculating and operation for quick acceptance or rejection
  for (i = 0; i < 4; i++)
    code[i] = start[i] && end[i];

  if (code[0] == 0 && code[1] == 0 && code[2] == 0 && code[3] == 0)
  {
    if (start[0] == 0 && start[1] == 0 && start[2] == 0 && start[3] == 0 && end[0] == 0 && end[1] == 0 && end[2] == 0 && end[3] == 0)
    {
      clrscr();
      printf("\n Line is completely visible");
      rectangle(xmin, ymin, xmax, ymax);
      line(x1, y1, x2, y2);
      getch();
    }
    else
    {
      clrscr();
      printf("\n Line is partially visible:");
      printf("\n Before clipping");
      rectangle(xmin, ymin, xmax, ymax);
      line(x1, y1, x2, y2);
      getch();
      if (start[0] == 1 && start[1] == 0) //L
      {
        y1 = y1 + m * (xmin - x1);
        x1 = xmin;
      }
      if (start[0] == 0 && start[1] == 1) //R
      {
        y1 = y1 + m * (xmax - x1);
        x1 = xmax;
      }
      if (start[2] == 1 && start[3] == 0) //B
      {
        x1 = x1 + (ymin - y1) / m;
        y1 = ymin;
      }
      if (start[2] == 0 && start[3] == 1) //T
      {
        x1 = x1 + (ymax - y1) / m;
        y1 = ymax;
      }
      //Same for endpoint
      if (end[0] == 1 && end[1] == 0) //L
      {
        y2 = y2 + m * (xmin - x2);
        x2 = xmin;
      }
      if (end[0] == 0 && end[1] == 1) //R
      {
        y2 = y2 + m * (xmax - x2);
        x2 = xmax;
      }
      if (end[2] == 1 && end[3] == 0) //B
      {
        x2 = x2 + (ymin - y2) / m;
        y2 = ymin;
      }
      if (end[2] == 0 && end[3] == 1) //T
      {
        x2 = x2 + (ymax - y2) / m;
        y2 = ymax;
      }
      clrscr();
      printf("\n After clipping");
      rectangle(xmin, ymin, xmax, ymax);
      line(x1, y1, x2, y2);
      getch();
    }
  }
  else
  {
    clrscr();
    printf("\n Line is completely invisible");
    rectangle(xmin, ymin, xmax, ymax);
    getch();
  }

  getch();
  closegraph();
}
