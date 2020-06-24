#ifndef __SOUND_H__
#define __SOUND_H__
#pragma comment(lib,"winmm.lib")

int playsound1(char *sound);
int psLoop(char *sound);
int bkmusic();

int playsound1(char *sound)//播放函数（一次） 
{
	PlaySound(sound, NULL,SND_FILENAME | SND_ASYNC | SND_NOSTOP);
	return 0;
}

int psLoop(char *sound)//只播放一次
{
	PlaySound(sound, NULL,SND_FILENAME | SND_LOOP | SND_ASYNC);
	return 1;
}

int bkmusic()//背景音乐 
{
	char add[]="sounds/bkmusic.wav";
	psLoop(add);
	return 0;
}

int shutup()
{
	PlaySound(NULL, NULL, SND_PURGE);
	return 0;
}
#endif
