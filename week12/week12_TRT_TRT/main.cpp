#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///身體
    glPushMatrix();///右
        glColor3f(1,0,0);
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.2,0,0);
        glutSolidTeapot(0.2);///上手臂
        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(0.4,0.1,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.2,0,0);
            glutSolidTeapot(0.2);///下手肘
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();///左
        glColor3f(1,0,0);
        glTranslatef(-0.5,0.2,0);
        glRotatef(-angle,0,0,1);
        glTranslatef(-0.2,0,0);
        glutSolidTeapot(0.2);///上手臂
        glPushMatrix();
            glColor3f(0,0,1);
            glTranslatef(-0.4,0.1,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(-0.2,0,0);
            glutSolidTeapot(0.2);///下手肘
        glPopMatrix();
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
