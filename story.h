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
		NtkGDI_PrintText(20, top + 190, "����, ��Ϊ������ȭ�ĵ�64���̳���ȭ���ɣ�", strlen("����, ��Ϊ������ȭ�ĵ�64���̳���ȭ���ɣ�"), RGB(i,i,i), 0, TRUE, 34, "΢���ź�");
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

#endif