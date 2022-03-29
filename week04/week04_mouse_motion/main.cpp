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
    oldX=x;///定錨，記錄舊的x座標
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 旋轉");
    glutDisplayFunc(display);
    glutMotionFunc(motion);///持續移動的滑鼠事件
    glutMouseFunc(mouse);
    glutMainLoop();
}
