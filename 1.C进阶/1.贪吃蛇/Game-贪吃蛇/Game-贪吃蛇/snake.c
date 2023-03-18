#define _CRT_SECURE_NO_WARINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE

#include "snake.h"

int lastX = 0;
int lastY = 0;
int score = 0;
int kx = 0;
int ky = 0;
int SleepSecond = 400;
int count = 0;
int date[100] = { 0 };
char buf[1024] = { 0 };

void InitSnake(void)
{
	snake.size = 2;//初始为2节长度

	snake.body[0].X = WIDE / 2;//蛇头初始化
	snake.body[0].Y = HIGH / 2;
	
	snake.body[1].X = WIDE / 2 - 1;//一节蛇身初始化，右移
	snake.body[1].Y = HIGH / 2;
}


void InitFood(void)
{
	food.X = rand() % WIDE;//0-59
	food.Y = rand() % HIGH;//0-59
}

void InitWall(void)
{
	for (size_t i = 0; i <= HIGH; i++)
	{
		for (size_t j = 0; j <= WIDE; j++)
		{
			if (j == WIDE)
			{
				printf("|");
			}
			else if (i == HIGH)
			{
				printf("_");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void InitUI(void)
{
	/*int lastX = 0;
	int lastY = 0;*/

	//画蛇
	COORD coord = { 0 };//光标移动位置变量

	for (size_t i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		if (i == 0)
			putchar('@');//输出蛇头
		else
			putchar('*');//输出蛇身
	}

	//去除蛇尾
	coord.X = lastX;
	coord.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//画食物
	coord.X = food.X;
	coord.Y = food.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');
}

void PlayGame(void)
{
	//int score = 0;
	char key = 'd';
	//int kx = 0;
	//int ky = 0;
	//int lastX = 0;
	//int lastY = 0;

	//判断蛇撞墙
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE 
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		InitUI();

		//接受用户按键输入aswd
		if (_kbhit())//为真，表明按下
		{
			key = _getch();
		}

		switch (key)
		{
		case'w':kx = 0; ky = -1;
			break;//上
		case's':kx = 0; ky = +1;
			break;//下
		case'a':kx = -1; ky = 0;
			break;//左
		case'd':kx = +1; ky = 0;
			break;//右
		default:
			break;
		}

		//判断蛇撞身体
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X 
				&& snake.body[0].Y == snake.body[i].Y)
			{
				return;//游戏结束
			}
		}

		//判断蛇撞食物
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
		{
			InitFood();//食物消失
			snake.size++;//身体增长
			score += 10;//加分
			SleepSecond -= 20;//加速
		}

		//存储蛇尾坐标
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		//蛇移动，前一节给后一节赋值
		for (size_t i = snake.size - 1; i >0 ; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		snake.body[0].X += kx;//蛇头根据按键改变
		snake.body[0].Y += ky;


		Sleep(SleepSecond);
		////清屏
		//system("cls");
	}
	return;
}

void pupple(int* pf, int n)
{
	int i = 0;
	for (i = 0; i < count; i++)
	{
		int j = 0;
		for (j = 0; j < count - i; j++)
		{
			if (date[j] < date[j + 1])
			{
				int tmp = date[j];
				date[j] = date[j + 1];
				date[j + 1] = tmp;
			}
		}
	}
}

void SaveScore(void)
{
	FILE* p = fopen("snake.txt", "r");
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	else
	{
		while (!feof(p))
		{
			memset(buf, 0, sizeof(buf));//每次读取一行之前都把这个buf清空,防止边界溢出
			fgets(buf, sizeof(buf), p);//从文件中读取一行
			date[count] = atoi(buf);//将读取到的一行转换为Int,赋值给数组成员
			count++;
		}
	}
	fclose(p);
	pupple(date, count);
	printf("分数排行:\n");
	for (size_t i = 0; i < count-1; i++)
	{
		printf("%d\n", date[i]);
	}
}

void ShowScore(void)
{
	COORD coord;
	//将光标移动到不影响位置
	coord.X = 0;
	coord.Y = HIGH+2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	FILE* pf = fopen("snake.txt", "a");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return;
	}
	fprintf(pf,"%-10d\n",score);
	fclose(pf);
	pf = NULL;

	printf("Game Over\n");
	printf("得分为:%d\n\n", score);
	SaveScore();
}


//void pupple(int* pf, int n)
//{
//	int i = 0;
//	for (i = 0; i < count; i++)
//	{
//		int j = 0;
//		for (j = 0; j < count - i; j++)
//		{
//			if (date[j] < date[j + 1])
//			{
//				int tmp = date[j];
//				date[j] = date[j + 1];
//				date[j + 1] = tmp;
//			}
//		}
//	}
//}
//
//void SaveScore(void)
//{
//	FILE* p = fopen("snake.txt", "r");
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return;
//	}
//	else
//	{
//		while (!feof(p))
//		{
//			memset(buf, 0, sizeof(buf));//每次读取一行之前都把这个buf清空
//			fgets(buf, sizeof(buf), p);//从文件中读取一行
//			date[count] = atoi(buf);//将读取到的一行转换为Int,赋值给数组成员
//			count++;
//		}
//		fclose(p);
//	}
//	pupple(date, count);
//	for (size_t i = 0; i < count; i++)
//	{
//		printf("%d ", date[i]);
//	}
//}
