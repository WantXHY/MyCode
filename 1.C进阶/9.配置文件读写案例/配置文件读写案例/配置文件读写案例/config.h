#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//配置信息结构体
struct ConfigInfo
{
	char key[64];
	char value[64];
};

int getFilelines(const char* R_file);//获取文件有效行数

int getRealline(char* str);//判断文件当前行数是否有效信息

void specConfigInfo(char* R_file, int len, struct ConfigInfo** Info);//配置信息

char* getInfokey(char* key, struct  ConfigInfo* Info, int len);

void freeConfigInfo(struct ConfigInfo* Info);
