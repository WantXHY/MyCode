#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct Player
{
	char name[64];
	int level;//�ȼ�
	int exp;//����
};

//��ʼ����Ϸ,���ָ��  �������
void INIT_GAME_COMPANY1(void** player, char* name);

//����ս��������ս���Ƿ�ʤ�� 1.ʤ��0.ʧ��  ���  ��Ϸ�����Ѷ�
int FIGH_GAME_COMPANY1(void* player, int gameDiff);

//�ж���Ϸ�Ƿ�ʤ��
int isWin(int winRate, int diff);

//�鿴�����Ϣ
void PINFO_GAME_COMPANY1(void* player);

//�뿪��Ϸ
void EXIT_GAME_COMPANY1(void* player);
