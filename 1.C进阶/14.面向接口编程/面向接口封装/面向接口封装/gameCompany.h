#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct Player
{
	char name[64];
	int level;//等级
	int exp;//经验
};

//初始化游戏,玩家指针  玩家姓名
void INIT_GAME_COMPANY1(void** player, char* name);

//副本战斗，返回战斗是否胜利 1.胜利0.失败  玩家  游戏副本难度
int FIGH_GAME_COMPANY1(void* player, int gameDiff);

//判断游戏是否胜利
int isWin(int winRate, int diff);

//查看玩家信息
void PINFO_GAME_COMPANY1(void* player);

//离开游戏
void EXIT_GAME_COMPANY1(void* player);
