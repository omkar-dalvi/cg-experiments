#include <GL/glut.h>

void displayMe()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5, 0.0, 0.5);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.3, 0.0, 0.0);
  glVertex3f(0.3, 0.3, 0.0);
  glVertex3f(0.0, 0.3, 0.0);
  glEnd();

  glColor3f(0.0, 0.5, 0.0);
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.1, 0.3, 0.0);
  glVertex3f(0.15, 0.4, 0.0);
  glVertex3f(0.4, 0.3, 0.0);
  glEnd();

  glColor3f(0.0, 0.0, 0.5);
  glBegin(GL_QUADS);
  glVertex3f(0.1, 0.0, 0.0);
  glVertex3f(0.1, 0.2, 0.0);
  glVertex3f(0.2, 0.2, 0.0);
  glVertex3f(0.2, 0.0, 0.0);
  glEnd();
  glFlush();
}
int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("First exp");
  glutDisplayFunc(displayMe);
  glutMainLoop();
  return 0;
}
