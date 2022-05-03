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
    if(pmodel==NULL)///�ҫ��٨S�ǳƦn�ɡA�|�O�ū���
    {
        pmodel=glmReadOBJ("data/Gundam.obj");///�N�ҫ�Ū�J
        glmUnitize(pmodel);///�N�ҫ��y�д��⦨-1~+1���d��
        glmFacetNormals(pmodel);///���s�p�⭱���k�V�q
        glmVertexNormals(pmodel, 90);///���s�p��ҫ����I���k�V�q
    }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel, GLM_TEXTURE);///�N�ҫ������M�K�ϵe�X��
    glPopMatrix();
    glutSwapBuffers();
    angle+=0.1;
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
