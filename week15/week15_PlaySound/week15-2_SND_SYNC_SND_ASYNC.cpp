#include <windows.h>
#include <stdio.h>
int main()
{///ASYNC：不等待（聲音沒播完就執行下一行），適合用於互動
    PlaySound("07042111.wav", NULL, SND_ASYNC);
    while(1)
    {
        printf("請輸入數字: ");
        int N;
        scanf("%d", &N);
        if(N==1) PlaySound("do.wav", NULL, SND_ASYNC);
        if(N==2) PlaySound("re.wav", NULL, SND_ASYNC);
        if(N==3) PlaySound("mi.wav", NULL, SND_ASYNC);
    }
}
