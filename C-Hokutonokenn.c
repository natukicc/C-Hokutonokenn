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
	GameUninit();
	NtkGDI_uninit();
	getchar();
	return 0;
}
