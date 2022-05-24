#include <stdio.h>
int main()
{///檔案指標fout
    FILE * fout = fopen("file.txt", "w+");///開啟檔案(檔名,寫檔)
    printf("Hello World\n");///一般的訊息提示
    fprintf(fout,"Hello World\n");///寫入檔案的訊息提示
    fclose(fout);///關閉檔案
}
