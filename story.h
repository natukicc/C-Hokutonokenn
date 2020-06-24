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
		NtkGDI_PrintText(20, top + 40, "��Ԫ199X��,", strlen("��Ԫ199X��,"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	top += 20;
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 90, "�����ܵ�����������ϴ������������󶼻���һ����", strlen("�����ܵ�����������ϴ������������󶼻���һ����"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 140, "���������ಢû����˶���������������Ȼ�д������������������Ϊ����ͳ�ε������", strlen("���������ಢû����˶���������������Ȼ�д������������������Ϊ����ͳ�ε������"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 190, "����, ��Ϊ������ȭ�ĵ�64���̳��˽����ɣ�", strlen("����, ��Ϊ������ȭ�ĵ�64���̳��˽����ɣ�"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 240, "�㽫�����Լ����յı�����ȭ�书�������Ž���෴�����˺�ѹ�Ȳ��Ĵ�������ˣ�", strlen("�㽫�������Լ����յı�����ȭ�书�������Ž���෴�����˺�ѹ�Ȳ��Ĵ�������ˣ�"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0; i <= 255; i+=15)
	{
		NtkGDI_PrintText(20, top + 290, "һ������ڰ�ʱ���еĸ��ָ�����а�������Լ��丽����а���������ж�������", strlen("һ������ڰ�ʱ���еĸ��ָ�����а�������Լ��丽����а���������ж�������"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_LoadImage(&logo,"images/logo.bmp",0,0);
	NtkGDI_PutImage(&logo, 250, 200, logo.width, logo.height, FALSE, RGB(255,0,255), SRCCOPY);
	NtkGDI_PrintText(470, 389, "�����С�", strlen("�����С�"), RGB(255,255,255), 0, TRUE, 40, "΢���ź�");
	NtkGDI_update();
	Sleep(800);
}

void Scene1Win()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "Сආ�1:�ϡ�����", strlen("Сආ�1:�ϡ�����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "Сආ�2:�ȡ�������������Ϊֹ����", strlen("Сආ�2:�ȡ�������������Ϊֹ����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
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
		NtkGDI_PrintText(20, top + 40, "Сආ�1:�������������ɽ�����", strlen("Сආ�1:�������������ɽ�����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "Сආ�2:��Ҫ�����ϻ���", strlen("Сආ�2:��Ҫ�����ϻ���"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "������:û�뵽����ȭ���ɾ�Ȼ����������", strlen("������:û�뵽����ȭ���ɾ�Ȼ����������"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(400, 329, "You Die", strlen("You Die"), RGB(220,20,60), 0, TRUE, 100, "����");
	NtkGDI_update();
	Sleep(800);	
}

void Scene2()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "������:������ˣ�������ƾ��������Ϊ�����ϴ󱨳�", strlen("������:������ˣ�������ƾ��������Ϊ�����ϴ󱨳�"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 80, "Boos:����", strlen("Boos:����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "������:ʲô�ˣ���", strlen("������:ʲô�ˣ���"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 160, "Boss:����[KING]��÷����������Ȥ���Ǵ��ˡ���������ô�ܴ�", strlen("Boss:����[KING]��÷����������Ȥ���Ǵ��ˡ���������ô�ܴ�"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "���죬����������ң������Ҵ����㡣", strlen("���죬����������ң������Ҵ����㡣"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top , "��ȭ��", strlen("��ȭ��"), RGB(i,i,i), 0, TRUE, 200, "����");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(470, 389, "�ڶ���", strlen("�ڶ���"), RGB(220,20,60), 0, TRUE, 40, "΢���ź�");
	NtkGDI_update();
	Sleep(800);	
}

void Scene2Win()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "������:���������ұȽ�ǿ��", strlen("������:���������ұȽ�ǿ��"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "÷��:�ɡ�����", strlen("÷��:�ɡ�����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
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
		NtkGDI_PrintText(20, top + 40, "÷��:�����������ұȽ�ǿ��ȥ����", strlen("÷��:�����������ұȽ�ǿ��ȥ����"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "������:�ȡ����򡭡���", strlen("������:�ȡ����򡭡���"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 200, "������:û�뵽����ȭ���ɾ�Ȼ����������", strlen("������:û�뵽���ҽ����ɾ�Ȼ����������"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(400, 329, "You Die", strlen("You Die"), RGB(220,20,60), 0, TRUE, 100, "����");
	NtkGDI_update();
	Sleep(800);	
}

void TheEnd()
{
	int i = 0 , top = 80 ;
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 40, "Ϊ��׷��÷�����ڵ���֯[KING]", strlen("Ϊ��׷��÷�����ڵ���֯[KING]"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	for(i = 0 ; i<=255 ; i+=15)
	{
		NtkGDI_PrintText(20, top + 120, "������̤����ǰ����ʮ���ǳǵ��ó�", strlen("������̤����ǰ����ʮ���ǳǵ��ó�"), RGB(i,i,i), 0, TRUE, 40, "΢���ź�");
		NtkGDI_update();
		Sleep(80);
	}
	Sleep(800);
	NtkGDI_DrawRectangle(0, 0, NTK_WINDOW_WIDTH, NTK_WINDOW_HEIGHT, RGB(0,0,0));
	NtkGDI_PrintText(300, 329, "To Be continued", strlen("To Be continued"), RGB(255,255,255), 0, TRUE, 100, "����");
	NtkGDI_update();
	Sleep(800);
}
#endif
