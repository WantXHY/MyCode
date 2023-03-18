
#ifndef SNAKE_H
#define SNAKE_H


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <Windows.h>
#include <errno.h>

//墙的区域大小
#define WIDE 60
#define HIGH 30

//extern int score;
//extern int kx;
//extern int ky;
//extern int lastX;
//extern int lastY;

struct BODY
{
	int X;
	int Y;
};

//定义蛇对象
struct SNAKE
{
	struct BODY body[WIDE * HIGH];// 蛇身 -- body[0] -- 蛇头
	int size;//蛇的大小
}snake;

//定义食物对象
struct FOOD
{
	int X;
	int Y;
}food;


void InitSnake(void);//初始化蛇
void InitFood(void);//初始化食物
void InitWall(void);//画墙
void InitUI(void);//初始化界面控件
void PlayGame(void);//启动游戏
void ShowScore(void);
//void SaveScore(void);

#endif