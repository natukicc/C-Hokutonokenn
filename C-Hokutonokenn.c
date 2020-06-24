#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <time.h>
#include <math.h>
#include "sound.h"
#include "ntkgdi.h"
#include "story.h"
#include "game.h"

int main()
{
	NtkGDI_init();
	NtkGDI_SetWindowsSize(20,20,1134,650);
	bkmusic();
	GameInit();
	//StoryEntry();
	GameEntry();
	GameUninit();
	NtkGDI_uninit();
	getchar();
	return 0;
}
