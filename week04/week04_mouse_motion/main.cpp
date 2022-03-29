#include <GL/glut.h>
float angle=0,oldX;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    display();
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;///�w��A�O���ª�x�y��
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 ����");
    glutDisplayFunc(display);
    glutMotionFunc(motion);///���򲾰ʪ��ƹ��ƥ�
    glutMouseFunc(mouse);
    glutMainLoop();
}
