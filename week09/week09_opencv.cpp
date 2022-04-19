#include<opencv/highgui.h>///使用opencv的外掛
int main()
{
    IplImage * img=cvLoadImage("檔名.jpg");///讀圖
    cvShowImage("week09", img);///秀圖
    cvWaitKey(0);///等待按鍵，等到按為止
}
