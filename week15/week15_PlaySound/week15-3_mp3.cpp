#include <stdio.h>
#include "CMP3_MCI.h"///更ヘ魁ㄏノ
CMP3_MCI mp3;///跑计
int main()
{
    mp3.Load("07042111.mp3");
    mp3.Play();
    printf("单块计: ");
    int N;///ノ块ㄓ祘Α
    scanf("%d", &N);
}
