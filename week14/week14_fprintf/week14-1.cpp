#include <stdio.h>
int main()
{///�ɮ׫���fout
    FILE * fout = fopen("file.txt", "w+");///�}���ɮ�(�ɦW,�g��)
    printf("Hello World\n");///�@�몺�T������
    fprintf(fout,"Hello World\n");///�g�J�ɮת��T������
    fclose(fout);///�����ɮ�
}
