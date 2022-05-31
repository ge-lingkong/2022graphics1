#include <windows.h>
#include <stdio.h>
int main()
{///SYNC：等待（聲音完整播完）
    printf("PlaySound()之前\n");
    PlaySound("07042111.wav", NULL, SND_SYNC);///檔案不存在時，會有很小的錯誤聲
    printf("PlaySound()之後\n");
}
