# 2022graphics1
# week02
## Color 實心茶壺
```C++
#include<GL/glut.h>///使用GLUT外掛，簡化程式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清除圖像
    glColor3f(1,1,0);///設定色彩
    glutSolidTeapot(0.3);///實心茶壺
    glutSwapBuffers();///畫好後，交換出來
}
int main(int argc,char** argv)///main()主函式 進階版
{
    glutInit(&argc, argv);///把參數，送給 gitInit 初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區 + 3D深度功能
    glutCreateWindow("第02週的程式");///開 GLUT 視窗
    glutDisplayFunc(display);///用來顯示的函式
    glutMainLoop();///主要的程式迴圈
}
```
## Color 多邊形
```C++
#include<GL/glut.h>///使用GLUT外掛，簡化程式
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清除圖像
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);///R,G,B
        glVertex2f(-1,-1);///Vertex:頂點
        glColor3f(0,1,0);
        glVertex2f(+1,-1);
        glColor3f(0,0,1);
        glVertex2f(0,+1);
    glEnd();
    glutSwapBuffers();///畫好後，交換出來
}
int main(int argc,char** argv)///main()主函式 進階版
{
    glutInit(&argc, argv);///把參數，送給 gitInit 初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///雙緩衝區 + 3D深度功能
    glutCreateWindow("第02週的程式");///開 GLUT 視窗
    glutDisplayFunc(display);///用來顯示的函式
    glutMainLoop();///主要的程式迴圈
}
```
# week03
## 移動茶壺
```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///備份舊的位置
        glTranslated(0.5,0.5,0);///向右上角移動
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原舊的位置
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 四個茶壺
```C++
#include <GL/glut.h>
void Teapot(float x,float y)
{
    glPushMatrix();///備份舊的位置
        glTranslated(x,y,0);///向座標移動
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原舊的位置
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Teapot(0.5,0.5);
    Teapot(0.5,-0.5);
    Teapot(-0.5,-0.5);
    Teapot(-0.5,0.5);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 移動");
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠移動茶壺
```C++
#include <GL/glut.h>
float mouseX=0,mouseY=0;
void Teapot(float x,float y)
{
    glPushMatrix();///備份舊的位置
        glTranslated(x,y,0);///向座標移動
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();///還原舊的位置
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Teapot((mouseX-150)/150.0,-(mouseY-150)/150.0);
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
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
```
