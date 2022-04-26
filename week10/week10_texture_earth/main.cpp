#include<GL/glut.h>
#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * sphere=NULL;///����G������������
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
        glRotatef(90,1,0,0);///�ॿ�a�y
        glRotatef(angle,0,0,1);
        gluQuadricTexture(sphere,1);///�G�������K��(����,�O�_�K��)
        gluSphere(sphere,1,30,30);///��y(����,�b�|,������,�����)
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;///�C�����泣��1��
}
int main(int argc,char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture earth");
    glEnable(GL_DEPTH_TEST);///3D�`�״��աA�}�F�~��3D�ĪG
    glutIdleFunc(display);///���ŴN����display
    glutDisplayFunc(display);
    myTexture("earth.jpg");
    sphere=gluNewQuadric();///�ǳƤG������
    glutMainLoop();
}
