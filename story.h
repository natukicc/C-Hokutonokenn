#pragma once
#ifndef STORY_H_INCLUDED
#define STORY_H_INCLUDED

void StoryEntry();
void Scene1Win();
void Scene1Lose();
void Scene2();
void Scene2Win();
void Scene2Lose();
void TheEnd();

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
		NtkGDI_PrintText(20, top + 190, "而你, 作为北斗神拳的第64代继承人健四郎，", strlen("而你, 作为北斗神拳的第64代继承人健四郎，"), RGB(i,i,i), 0, TRUE, 34, "微软雅黑");
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

void Scene1Win()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "小喽啰1:老……大", strlen("小喽啰1:老……大"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "小喽啰2:咳……呃……到此为止了吗", strlen("小喽啰2:咳……呃……到此为止了吗"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	Scene2();
	NtkGDI_update();
	Sleep(800);	
}

void Scene1Lose()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "小喽啰1:哈哈哈哈受死吧健四郎", strlen("小喽啰1:哈哈哈哈受死吧健四郎"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "小喽啰2:不要跟他废话了", strlen("小喽啰2:不要跟他废话了"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "健四郎:没想到，我拳四郎居然会败在这里……", strlen("健四郎:没想到，我拳四郎居然会败在这里……"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(400, 329, "You Die", strlen("You Die"), RGB(220,20,60), 0, TRUE, 100, "粗体");
	NtkGDI_update();
	Sleep(800);	
}

void Scene2()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "健四郎:不过如此，就你们凭两个还想为你们老大报仇", strlen("健四郎:不过如此，就你们凭两个还想为你们老大报仇"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 80, "Boos:精彩", strlen("Boos:精彩"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "健四郎:什么人？！", strlen("健四郎:什么人？！"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 160, "Boss:我是[KING]的梅花，最大的兴趣就是打人。看到你这么能打", strlen("Boss:我是[KING]的梅花，最大的兴趣就是打人。看到你这么能打"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "今天，不是你打死我，就是我打死你。", strlen("今天，不是你打死我，就是我打死你。"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top , "看拳！", strlen("看拳！"), RGB(i,i,i), 0, TRUE, 200, "粗体");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(470, 389, "第二关", strlen("第二关"), RGB(220,20,60), 0, TRUE, 40, "微软雅黑");
	NtkGDI_update();
	Sleep(800);	
}

void Scene2Win()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "健四郎:看来还是我比较强。", strlen("健四郎:看来还是我比较强。"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "梅花:可……恶", strlen("梅花:可……恶"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_update();
	Sleep(800);	
}

void Scene2Lose()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "梅花:看来，还是我比较强，去死吧", strlen("梅花:看来，还是我比较强，去死吧"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "健四郎:尤……莉……亚", strlen("健四郎:尤……莉……亚"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "健四郎:没想到，健拳四郎居然会败在这里……", strlen("健四郎:没想到，我健四郎居然会败在这里……"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(400, 329, "You Die", strlen("You Die"), RGB(220,20,60), 0, TRUE, 100, "粗体");
	NtkGDI_update();
	Sleep(800);	
}

void TheEnd()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "为了追查梅花所在的组织[KING]", strlen("为了追查梅花所在的组织[KING]"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "健四郎踏上了前往南十字星城的旅程", strlen("健四郎踏上了前往南十字星城的旅程"), RGB(i,i,i), 0, TRUE, 40, "微软雅黑");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(300, 329, "To Be continued", strlen("To Be continued"), RGB(255,255,255), 0, TRUE, 100, "粗体");
	NtkGDI_update();
	Sleep(800);
}
#endif
