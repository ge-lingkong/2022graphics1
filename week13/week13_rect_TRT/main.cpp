#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;///紀錄滑鼠點擊時的x座標
}
void motion(int x,int y)
{
    angle+=(x-oldX);///按著滑鼠移動時，角度跟著滑鼠的x座標增減
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白
    glRectf(0.3,0.5, -0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///3.將物件放到該在的位置上
        glRotatef(angle,0,0,1);///2.旋轉軸
        glTranslatef(-0.3,-0.4,0);///1.將物件軸心放到座標中心
        glColor3f(1,0,0);///紅
        glRectf(0.3,0.5, 0.7,0.3);///手臂
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
