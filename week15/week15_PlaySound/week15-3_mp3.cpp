#include <stdio.h>
#include "CMP3_MCI.h"///�U�����P�@�ؿ��ϥ�
CMP3_MCI mp3;///�ŧi�ܼ�
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("���ݿ�J�Ʀr: ");
    int N;///�ο�J�ӥd��{��
    scanf("%d", &N);
}
