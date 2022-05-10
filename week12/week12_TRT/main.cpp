#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///身體
    glPushMatrix();
        glColor3f(1,0,0);
        glTranslatef(0.5,0.2,0);///物件位置
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.2,0,0);///軸心位置
        glutSolidTeapot(0.2);///手臂
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
