#include<opencv/highgui.h>///�ϥ�opencv���~��
int main()
{
    IplImage * img=cvLoadImage("�ɦW.jpg");///Ū��
    cvShowImage("week09", img);///�q��
    cvWaitKey(0);///���ݫ���A���������
}
