#include <windows.h>
#include <stdio.h>
int main()
{///SYNC�G���ݡ]�n�����㼽���^
    printf("PlaySound()���e\n");
    PlaySound("07042111.wav", NULL, SND_SYNC);///�ɮפ��s�b�ɡA�|���ܤp�����~�n
    printf("PlaySound()����\n");
}
