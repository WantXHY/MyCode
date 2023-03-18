
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

//ǽ�������С
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

//�����߶���
struct SNAKE
{
	struct BODY body[WIDE * HIGH];// ���� -- body[0] -- ��ͷ
	int size;//�ߵĴ�С
}snake;

//����ʳ�����
struct FOOD
{
	int X;
	int Y;
}food;


void InitSnake(void);//��ʼ����
void InitFood(void);//��ʼ��ʳ��
void InitWall(void);//��ǽ
void InitUI(void);//��ʼ������ؼ�
void PlayGame(void);//������Ϸ
void ShowScore(void);
//void SaveScore(void);

#endif