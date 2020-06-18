#pragma once
#ifndef STORY_H_INCLUDED
#define STORY_H_INCLUDED

void StoryEntry();

void StoryEntry()
{
	int i;
	int top = 80;
	NImage logo;
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "西元199X年,", strlen("西元199X年,"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	top += 20;
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 90, "世界受到核子武器的洗礼，人类的文明大都毁于一旦。", strlen("世界受到核子武器的洗礼，人类的文明大都毁于一旦。"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 140, "不过，人类并没有因此而灭亡，少数人仍然残存了下来，活在这个沦为暴力统治的世界里。", strlen("不过，人类并没有因此而灭亡，少数人仍然残存了下来，活在这个沦为暴力统治的世界里。"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 190, "而你, 作为北斗神拳的第64代继承人拳四郎，", strlen("而你, 作为北斗神拳的第64代继承人拳四郎，"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 240, "你将运用自己掌握的北斗神拳武功，加上团结许多反抗厄运和压迫并心存正义的人，", strlen("你将将运用自己掌握的北斗神拳武功，加上团结许多反抗厄运和压迫并心存正义的人，"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 290, "一起与这黑暗时代中的各种各样的邪恶首脑以及其附属的邪恶势力进行斗争……", strlen("一起与这黑暗时代中的各种各样的邪恶首脑以及其附属的邪恶势力进行斗争……"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_LoadImage(&logo,"images/logo.bmp",0,0);
	NtkGDI_PutImage(&logo, 250, 200, logo.width, logo.height, FALSE, RGB(255,0,255), SRCCOPY);
	NtkGDI_PrintText(470, 389, "加载中…", strlen("加载中…"), RGB(255,255,255), 0, TRUE, 40, "微软雅黑");
	NtkGDI_update();
	Sleep(800);
}

#endif