#include <GL/glut.h>
#include <stdio.h>
float mouseX=0,mouseY=0;
void Teapot(float x,float y)
{
    glPushMatrix();///備份舊的位置
        glTranslated(x,y,0);///向座標移動
        glColor3f(1,1,0);
        glutSolidTeapot(0.1);
    glPopMatrix();///還原舊的位置
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Teapot((mouseX-150)/150.0,-(mouseY-150)/150.0);///座標換算
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
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);///滑鼠事件
    glutMainLoop();
}
