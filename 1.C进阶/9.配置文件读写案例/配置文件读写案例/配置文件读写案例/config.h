#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//������Ϣ�ṹ��
struct ConfigInfo
{
	char key[64];
	char value[64];
};

int getFilelines(const char* R_file);//��ȡ�ļ���Ч����

int getRealline(char* str);//�ж��ļ���ǰ�����Ƿ���Ч��Ϣ

void specConfigInfo(char* R_file, int len, struct ConfigInfo** Info);//������Ϣ

char* getInfokey(char* key, struct  ConfigInfo* Info, int len);

void freeConfigInfo(struct ConfigInfo* Info);
