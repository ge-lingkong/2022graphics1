#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);

    float angle=0;
    FILE * fin = fopen("file.txt","r");///開啟檔案(檔名,讀檔)
    fscanf(fin,"%f", &angle);///從檔案裡讀取變數的值
    printf("讀到了角度:%f", angle);
    fclose(fin);
}
