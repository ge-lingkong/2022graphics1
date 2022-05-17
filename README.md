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
## 滑鼠座標換算
```C++
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
    printf("%d %d %d %d\n", button, state, x, y);
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
# week04
## 旋轉茶壺
```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,0,0,1);///z軸心，90度
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 旋轉");
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠旋轉茶壺 滑鼠x座標=旋轉角度
```C++
#include <GL/glut.h>
float angle=0;
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
    angle=x;///角度隨滑鼠移動更改
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 旋轉");
    glutDisplayFunc(display);
    glutMotionFunc(motion);///持續移動的滑鼠事件
    glutMainLoop();
}
```
## 滑鼠旋轉茶壺 滑鼠x座標!=旋轉角度
```C++
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
```
## 滑鼠畫圖
```C++
#include <GL/glut.h>
#include <stdio.h>
int mx[2000],my[2000],N=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
        for(int i=0;i<N;i++)
            glVertex2f((mx[i]-150)/150.0,-(my[i]-150)/150.0);
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)
    {
        printf("    glVertex2f((%d-150)/150.0, -(%d-150)/150.0);\n", x, y);
        N++;
        mx[N-1]=x;
        my[N-1]=y;
    }
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 滑鼠畫圖");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
```
# week05
## 按鍵盤看滑鼠座標
```C++
#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    printf("你按下了 %c 在 %d %d 座標\n", key, x, y);
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}
```
## 滑鼠拖動茶壺
```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A  A是Alpha值，調透明度
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;  oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    x+=(mouseX-oldX);  y+=(mouseY-oldY);
    oldX=mouseX;       oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
## 滑鼠縮放茶壺
```C++
#include <GL/glut.h>
#include <stdio.h>
float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);///R,G,B,A  A是Alpha值，調透明度
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);///縮放
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;  oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX > 0) scale*=1.01;
    if(mouseX-oldX < 0) scale*=0.99;
    oldX=mouseX;       oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05 keyboard");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutMainLoop();
}
```
# week06
## 打光
```C++
#include <GL/glut.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
```
## 打光+縮放
```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glScalef(scale,scale,scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;  oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(mouseX-oldX > 0) scale*=1.01;
    if(mouseX-oldX < 0) scale*=0.99;
    oldX=mouseX;       oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
```
## 打光+旋轉
```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150,y=150,z=0,angle=0.0;
int oldX=0,oldY=0;
void display()
{
    glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotatef(angle,0,1,0);///軸心:y軸
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;  oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    angle+=(mouseX-oldX);
    oldX=mouseX;       oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
```
## 鍵盤切換：移動、旋轉、縮放
```C++
#include <GL/glut.h>
#include <stdio.h>
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=1;///now: 1移動, 2轉動, 3縮放
void display()
{
    glClearColor(0.5,0.5,0.5,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0,-(y-150)/150.0,z);
        glRotatef(angle,0,1,0);///軸心:y軸
        glScalef(scale,scale,scale);
        glColor3f(1,1,0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{
    if(key=='1' || key=='w' || key=='K') now=1;
    if(key=='2' || key=='e' || key=='E') now=2;
    if(key=='3' || key=='r' || key=='R') now=3;
}
void mouse(int button,int state,int mouseX,int mouseY)
{
    oldX=mouseX;  oldY=mouseY;
}
void motion(int mouseX,int mouseY)
{
    if(now==1){///移動
        x+=(mouseX-oldX);  y+=(mouseY-oldY);
    }
    else if(now==2)///轉動
        angle+=(mouseX-oldX);
    else if(now==3){///縮放
        if(mouseX-oldX > 0) scale*=1.01;
        if(mouseX-oldX < 0) scale*=0.99;
    }
    oldX=mouseX;       oldY=mouseY;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
```
# week08
## 模型
```C++
#include <GL/glut.h>///角括號，是系統的include裡的檔案
#include "glm.h"///雙引號，同目錄裡的檔案
GLMmodel* pmodel = NULL;///指到GLMmodel模型的指標
void drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/soccerball.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}///用來畫3D模型的程式碼

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,0);
    ///glutSolidTeapot(0.3);
    drawmodel();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");

    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
```
# week09
## 讀圖、秀圖
```C++
#include<opencv/highgui.h>///使用opencv的外掛
int main()
{
    IplImage * img=cvLoadImage("檔名.jpg");///讀圖
    cvShowImage("week09", img);///秀圖
    cvWaitKey(0);///等待按鍵，等到按為止
}
```
## OpenCV+OpenGL
```C++
#include<GL/glut.h>
#include<opencv/highgui.h>
void myTexture()
{
    IplImage * img=cvLoadImage("檔案.png");
    cvShowImage("opencv", img);
    ///cvWaitKey(0);///可以不用寫，因為有glutMainLoop()卡住
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");
    glutDisplayFunc(display);
    myTexture();
    glutMainLoop();
}
```
## 茶壺貼圖
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");
    glutDisplayFunc(display);
    myTexture("檔案.jpg");
    glutMainLoop();
}
```
# week10
## 背景貼圖
```C++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,1);  glVertex2f(-1,-1);///左下
        glTexCoord2f(1,1);  glVertex2f(1,-1);///右下
        glTexCoord2f(1,0);  glVertex2f(1,1);///右上
        glTexCoord2f(0,0);  glVertex2f(-1,1);///左上
    glEnd();///圖片左上角是(0,0)，視窗左下角是(-1,-1)
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture background");
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    glutMainLoop();
}
```
## 圓球貼圖，不會轉
```C++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere=NULL;///指到二次曲面的指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluQuadricTexture(sphere,1);///二次曲面貼圖(指標,是否貼圖)
    gluSphere(sphere,1,30,30);///圓球(指標,半徑,直切數,橫切數)
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture earth");
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere=gluNewQuadric();///準備二次曲面
    glutMainLoop();
}
```
## 圓球貼圖，會轉
```C++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere=NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,1,0,0);///轉正地球
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere,1);
        gluSphere(sphere,1,30,30);
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;///每次執行都轉1度
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture earth");
    glEnable(GL_DEPTH_TEST);///3D深度測試，開了才有3D效果
    glutIdleFunc(display);///有空就執行display
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere=gluNewQuadric();
    glutMainLoop();
}
```
# week11
## 顯示圖片
```C++
#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("data/Diffuse.jpg");
    cvShowImage("week11", img);
    cvWaitKey(0);
}
```
## 2D貼圖
```C++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundam");
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glutMainLoop();
}
```
## 3D貼圖
```C++
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * pmodel = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL)///模型還沒準備好時，會是空指標
    {
        pmodel=glmReadOBJ("data/Gundam.obj");///將模型讀入
        glmUnitize(pmodel);///將模型座標換算成-1~+1的範圍
        glmFacetNormals(pmodel);///重新計算面的法向量
        glmVertexNormals(pmodel, 90);///重新計算模型頂點的法向量
    }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_TEXTURE);///將模型的面和貼圖畫出來
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundam");
    glEnable(GL_DEPTH_TEST);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");
    glutMainLoop();
}
```
## 關節轉動模擬
```C++
#include <GL/glut.h>
void hand()
{
    glColor3f(0,1,0);
    glutSolidTeapot(0.2);
}
void body()
{
    glColor3f(1,1,0);
    glutSolidTeapot(0.3);
}
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
# week12
## 茶壺超人
```C++
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
```
## 茶壺超人，有手肘
```C++
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glutSolidTeapot(0.3);///身體
    glPushMatrix();
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
```
## 茶壺超人，兩隻手
```C++
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
```
# week13
## TRT，矩形版，關節*1
```C++
#include <GL/glut.h>
float angle=0;
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
    angle+=0.1;
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠轉手臂，關節*1
```C++
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
    glColor3f(1,1,1);
    glRectf(0.3,0.5, -0.3,-0.5);
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);
        glRectf(0.3,0.5, 0.7,0.3);
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
```
## 滑鼠轉手臂，關節*2
```C++
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白
    glRectf(0.3,0.5, -0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle,0,0,1);///0.註解掉上層旋轉軸
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(0.3,0.5, 0.7,0.3);///上手臂
        glPushMatrix();
            glTranslatef(0.7,0.4,0);///3.將物件放到該在的位置上
            glRotatef(angle,0,0,1);///2.旋轉軸
            glTranslatef(-0.7,-0.4,0);///1.將物件軸心放到座標中心
            glColor3f(0,1,0);///綠
            glRectf(0.7,0.5, 1.0,0.3);///下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠轉手臂，關節*4
```C++
#include <GL/glut.h>
float angle=0, oldX=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白
    glRectf(0.3,0.5, -0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle,0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(0.3,0.5, 0.7,0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(0.7,0.5, 1.0,0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(-0.3,0.5, -0.7,0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle,0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(-0.7,0.5, -1.0,0.3);///左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT TRT");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
## 滑鼠轉手臂，鍵盤換號，關節*4
```C++
#include <GL/glut.h>
float angle[20], oldX=0;
int angleID=0;///關節ID
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}///更改操作關節
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleID]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);///白
    glRectf(0.3,0.5, -0.3,-0.5);///身體
    glPushMatrix();
        glTranslatef(0.3,0.4,0);
        glRotatef(angle[0],0,0,1);
        glTranslatef(-0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(0.3,0.5, 0.7,0.3);///右上手臂
        glPushMatrix();
            glTranslatef(0.7,0.4,0);
            glRotatef(angle[1],0,0,1);
            glTranslatef(-0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(0.7,0.5, 1.0,0.3);///右下手肘
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.3,0.4,0);
        glRotatef(angle[2],0,0,1);
        glTranslatef(0.3,-0.4,0);
        glColor3f(1,0,0);///紅
        glRectf(-0.3,0.5, -0.7,0.3);///左上手臂
        glPushMatrix();
            glTranslatef(-0.7,0.4,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(0.7,-0.4,0);
            glColor3f(0,1,0);///綠
            glRectf(-0.7,0.5, -1.0,0.3);///左下手肘
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rect TRT TRT");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
