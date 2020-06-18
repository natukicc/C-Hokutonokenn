#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include "ntkgdi.h"
#include "story.h"
#include "game.h"

int main()
{
	NtkGDI_init();
	NtkGDI_SetWindowsSize(20,20,1134,650);
	GameInit();
	//StoryEntry();
	GameEntry();
	//NtkGDI_PutImageEx(&fig, left, 350, 51*2, 94*2, iFig*49, 0, 49, 105, false, RGB(255,0,255), SRCCOPY);
	GameUninit();
	NtkGDI_uninit();
	getchar();
	return 0;
}
