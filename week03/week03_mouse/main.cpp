#include <GL/glut.h>
#include <stdio.h>
float mouseX=0,mouseY=0;
void Teapot(float x,float y)
{
    glPushMatrix();///�ƥ��ª���m
        glTranslated(x,y,0);///�V�y�в���
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///�٭��ª���m
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Teapot((mouseX-150)/150.0,-(mouseY-150)/150.0);///�y�д���
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    printf("glVertex2f((%d-150)/150.0,-(%d-150.0)/150.0)\n", x, y);
    mouseX=x;
    mouseY=y;
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 ����");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///�ƹ��ƥ�
    glutMainLoop();
}
