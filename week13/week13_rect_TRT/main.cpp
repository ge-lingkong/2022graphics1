#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;///�����ƹ��I���ɪ�x�y��
}
void motion(int x,int y)
{
    angle+=(x-oldX);///���۷ƹ����ʮɡA���׸�۷ƹ���x�y�мW��
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///��
    glRectf(0.3,0.5, -0.3,-0.5);///����
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///3.�N������Ӧb����m�W
        glRotatef(angle,0,0,1);///2.����b
        glTranslatef(-0.3,-0.4,0);///1.�N����b�ߩ��y�Ф���
        glColor3f(1,0,0);///��
        glRectf(0.3,0.5, 0.7,0.3);///���u
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
