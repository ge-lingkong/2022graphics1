#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void timer(int t)
{
    printf("起床,現在時間: %d\n", t);
    PlaySound("do.wav", NULL, SND_ASYNC);///播聲音
    glutTimerFunc(2000, timer, t+1);///每2秒執行一次
}
void display()
{
    ///啥都沒做
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14 timer");

    glutTimerFunc(5000, timer, 0);///5秒後，第0個timer
    glutDisplayFunc(display);
    glutMainLoop();
}
