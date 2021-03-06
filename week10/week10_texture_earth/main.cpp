#include<GL/glut.h>
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
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(90,1,0,0);///轉正地球
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere,1);///二次曲面貼圖(指標,是否貼圖)
        gluSphere(sphere,1,30,30);///圓球(指標,半徑,直切數,橫切數)
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
    sphere=gluNewQuadric();///準備二次曲面
    glutMainLoop();
}
