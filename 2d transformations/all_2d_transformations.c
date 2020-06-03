#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{

  int x3, y3, x3new, y3new, x4, y4, ch2, i, x1, y1, x2, y2, gd = DETECT, gm, x1new, x2new, y1new, y2new, ty, tx, ch, rad, x2org, y2org, x[10], y[10], tempx[10], tempy[10], x4new, y4new;
  float thetha, sy, sx, shx, shy;
  initgraph(&gd, &gm, "C:\\TurboC3\\BGI");
  printf("\n Enter the bottom left corner co-ordinate");
  scanf("%d %d", &x1, &y1);
  printf("\n Enter the top right corner co-ordinate");
  scanf("%d %d", &x2, &y2);
  do
  {
    clrscr();
    printf("\n Menu: \n 1:Translation \n 2:Rotation \n 3:Scaling \n 4:Reflection \n 5:Shearing \n 6:Exit");
    printf("\n Enter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
      clrscr();
      line(x1, y1, x1, y2);
      line(x1, y2, x2, y2);
      line(x2, y2, x2, y1);
      line(x2, y1, x1, y1);
      printf("\n Enter the values of tx and ty:");
      scanf("%d %d", &tx, &ty);
      x1new = x1 + tx;
      x2new = x2 + tx;
      y1new = y1 + ty;
      y2new = y2 + ty;
      line(x1new, y1new, x1new, y2new);
      line(x1new, y2new, x2new, y2new);
      line(x2new, y2new, x2new, y1new);
      line(x2new, y1new, x1new, y1new);
      getch();
      break;
    }
    case 2:
    {
      clrscr();
      line(x1, y1, x1, y2);
      line(x1, y2, x2, y2);
      line(x2, y2, x2, y1);
      line(x2, y1, x1, y1);
      printf("\n Enter the angle:");
      scanf("%d", &rad);
      thetha = (float)(rad * 3.14 / 180);

      //Making array of co-ordinates
      x[0] = x[1] = x1;
      x[2] = x[3] = x2;
      y[0] = y[3] = y1;
      y[1] = y[2] = y2;
      for (i = 0; i < 4; i++)
      {
        //Transferring
        tempx[i] = x[i];
        tempy[i] = y[i];
        //Shifting to origin
        tempx[i] = tempx[i] - x1;
        tempy[i] = tempy[i] - y1;
        x[i] = x[i] - x1;
        y[i] = y[i] - y1;
        //Rotating
        tempx[i] = (int)((float)x[i] * cos(thetha) - (float)y[i] * sin(thetha));
        tempy[i] = (int)((float)x[i] * sin(thetha) + (float)y[i] * cos(thetha));
        //Shifting to original point
        tempx[i] = tempx[i] + x1;
        tempy[i] = tempy[i] + y1;
        //Temp to original
        x[i] = tempx[i];
        y[i] = tempy[i];
      }
      line(x[0], y[0], x[1], y[1]);
      line(x[1], y[1], x[2], y[2]);
      line(x[2], y[2], x[3], y[3]);
      line(x[3], y[3], x[0], y[0]);
      getch();
      break;
    }
    case 3:
    {
      clrscr();
      line(x1, y1, x1, y2);
      line(x1, y2, x2, y2);
      line(x2, y2, x2, y1);
      line(x2, y1, x1, y1);
      printf("\n Enter the scaling factor sx and sy:");
      scanf("%f %f", &sx, &sy);
      x1new = 0;
      y1new = 0;
      x2new = (x2 - x1) * sx;
      y2new = (y2 - y1) * sy;
      line(x1new + x1, y1new + y1, x1new + x1, y2new + y1);
      line(x1new + x1, y2new + y1, x2new + x1, y2new + y1);
      line(x2new + x1, y2new + y1, x2new + x1, y1new + y1);
      line(x2new + x1, y1new + y1, x1new + x1, y1new + y1);
      getch();
      break;
    }
    case 4:
    {
      clrscr();
      do
      {
        clrscr();
        printf("\n 1:Reflection along x axis \n 2:Reflection along y axis \n 3:Reflection along y=x \n 4:Exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
        {
          clrscr();
          line(x1, y1, x1, y2);
          line(x1, y2, x2, y2);
          line(x2, y2, x2, y1);
          line(x2, y1, x1, y1);
          x1new = 0;
          y1new = 0;
          x2new = x2 - x1;
          y2new = y2 - y1;
          y2new = -1 * y2new;

          line(x1new + x1, y1new + y1, x1new + x1, y2new + y1);
          line(x1new + x1, y2new + y1, x2new + x1, y2new + y1);
          line(x2new + x1, y2new + y1, x2new + x1, y1new + y1);
          line(x2new + x1, y1new + y1, x1new + x1, y1new + y1);
          getch();
          break;
        }
        case 2:
        {
          clrscr();
          line(x1, y1, x1, y2);
          line(x1, y2, x2, y2);
          line(x2, y2, x2, y1);
          line(x2, y1, x1, y1);
          x1new = 0;
          y1new = 0;
          x2new = x2 - x1;
          y2new = y2 - y1;
          x2new = -1 * x2new;

          line(x1new + x1, y1new + y1, x1new + x1, y2new + y1);
          line(x1new + x1, y2new + y1, x2new + x1, y2new + y1);
          line(x2new + x1, y2new + y1, x2new + x1, y1new + y1);
          line(x2new + x1, y1new + y1, x1new + x1, y1new + y1);
          getch();
          break;
        }
        case 3:
        {
          clrscr();
          line(x1, y1, x1, y2);
          line(x1, y2, x2, y2);
          line(x2, y2, x2, y1);
          line(x2, y1, x1, y1);
          x1new = 0;
          y1new = 0;
          x2new = x2 - x1;
          y2new = y2 - y1;
          y2new = -1 * y2new;
          x2new = -1 * x2new;
          line(x1new + x1, y1new + y1, x1new + x1, y2new + y1);
          line(x1new + x1, y2new + y1, x2new + x1, y2new + y1);
          line(x2new + x1, y2new + y1, x2new + x1, y1new + y1);
          line(x2new + x1, y1new + y1, x1new + x1, y1new + y1);
          getch();
          break;
        }
        case 4:
          break;
        }
      } while (ch2 != 4);
    }
    case 5:
    {
      do
      {
        clrscr();
        printf("\n1:X shear \n2:Y Shear \n3:Exit");
        printf("\n Enter your choice:");
        scanf("%d", &ch2);
        switch (ch2)
        {
        case 1:
        {
          clrscr();
          line(x1, y1, x1, y2);
          line(x1, y2, x2, y2);
          line(x2, y2, x2, y1);
          line(x2, y1, x1, y1);
          printf("\n Enter value of shear");
          scanf("%f", &shx);

          x3 = x2;
          y3 = y1;
          x4 = x1;
          y4 = y2;
          x1new = 0;
          y1new = 0;
          x2new = x2 - x1;
          y2new = y2 - y1;
          x3new = x3 - x1;
          y3new = y3 - y1;
          x4new = x4 - x1;
          y4new = y4 - y1;
          x2new = x2new - shx * y2new;
          x4new = x4new - shx * y4new;
          line(x1new + x1, y1new + y1, x4new + x1, y4new + y1);
          line(x4new + x1, y4new + y1, x2new + x1, y2new + y1);
          line(x2new + x1, y2new + y1, x3new + x1, y3new + y1);
          line(x3new + x1, y3new + y1, x1new + x1, y1new + y1);
          getch();
          break;
        }
        case 2:
        {
          clrscr();
          line(x1, y1, x1, y2);
          line(x1, y2, x2, y2);
          line(x2, y2, x2, y1);
          line(x2, y1, x1, y1);
          printf("\n Enter value of shear");
          scanf("%f", &shy);

          x3 = x2;
          y3 = y1;
          x4 = x1;
          y4 = y2;
          x1new = 0;
          y1new = 0;
          x2new = x2 - x1;
          y2new = y2 - y1;
          x3new = x3 - x1;
          y3new = y3 - y1;
          x4new = x4 - x1;
          y4new = y4 - y1;
          y2new = y2new - shy * x2new;
          y3new = y3new - shy * x3new;
          line(x1new + x1, y1new + y1, x4new + x1, y4new + y1);
          line(x4new + x1, y4new + y1, x2new + x1, y2new + y1);
          line(x2new + x1, y2new + y1, x3new + x1, y3new + y1);
          line(x3new + x1, y3new + y1, x1new + x1, y1new + y1);
          getch();
          break;
        }
        case 3:
          break;
        }
      } while (ch2 != 3);
    }
    case 6:
      break;
    }
  } while (ch != 6);
  getch();
  closegraph();
}
