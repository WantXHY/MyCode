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
	snake.size = 2;//��ʼΪ2�ڳ���

	snake.body[0].X = WIDE / 2;//��ͷ��ʼ��
	snake.body[0].Y = HIGH / 2;
	
	snake.body[1].X = WIDE / 2 - 1;//һ�������ʼ��������
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

	//����
	COORD coord = { 0 };//����ƶ�λ�ñ���

	for (size_t i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

		if (i == 0)
			putchar('@');//�����ͷ
		else
			putchar('*');//�������
	}

	//ȥ����β
	coord.X = lastX;
	coord.Y = lastY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');

	//��ʳ��
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

	//�ж���ײǽ
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE 
		&& snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		InitUI();

		//�����û���������aswd
		if (_kbhit())//Ϊ�棬��������
		{
			key = _getch();
		}

		switch (key)
		{
		case'w':kx = 0; ky = -1;
			break;//��
		case's':kx = 0; ky = +1;
			break;//��
		case'a':kx = -1; ky = 0;
			break;//��
		case'd':kx = +1; ky = 0;
			break;//��
		default:
			break;
		}

		//�ж���ײ����
		for (size_t i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X 
				&& snake.body[0].Y == snake.body[i].Y)
			{
				return;//��Ϸ����
			}
		}

		//�ж���ײʳ��
		if (snake.body[0].X == food.X && snake.body[0].Y == food.Y)
		{
			InitFood();//ʳ����ʧ
			snake.size++;//��������
			score += 10;//�ӷ�
			SleepSecond -= 20;//����
		}

		//�洢��β����
		lastX = snake.body[snake.size - 1].X;
		lastY = snake.body[snake.size - 1].Y;

		//���ƶ���ǰһ�ڸ���һ�ڸ�ֵ
		for (size_t i = snake.size - 1; i >0 ; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		snake.body[0].X += kx;//��ͷ���ݰ����ı�
		snake.body[0].Y += ky;


		Sleep(SleepSecond);
		////����
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
			memset(buf, 0, sizeof(buf));//ÿ�ζ�ȡһ��֮ǰ�������buf���,��ֹ�߽����
			fgets(buf, sizeof(buf), p);//���ļ��ж�ȡһ��
			date[count] = atoi(buf);//����ȡ����һ��ת��ΪInt,��ֵ�������Ա
			count++;
		}
	}
	fclose(p);
	pupple(date, count);
	printf("��������:\n");
	for (size_t i = 0; i < count-1; i++)
	{
		printf("%d\n", date[i]);
	}
}

void ShowScore(void)
{
	COORD coord;
	//������ƶ�����Ӱ��λ��
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
	printf("�÷�Ϊ:%d\n\n", score);
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
//			memset(buf, 0, sizeof(buf));//ÿ�ζ�ȡһ��֮ǰ�������buf���
//			fgets(buf, sizeof(buf), p);//���ļ��ж�ȡһ��
//			date[count] = atoi(buf);//����ȡ����һ��ת��ΪInt,��ֵ�������Ա
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
