#define _CRT_SECURE_NO_WARINGS 1

#include "snake.h"

int main()
{
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	srand((unsigned int)time(NULL));

	InitSnake();//初始化蛇
	InitFood();//初始化食物
	InitWall();//画墙
	InitUI();//初始化界面控件
	PlayGame();//启动游戏
	ShowScore();//更新分数
	//void SaveScore();

	system("pause");
	return EXIT_SUCCESS;
}