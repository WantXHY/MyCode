#include "gameCompany.h"

//初始化游戏,玩家指针  玩家姓名
void INIT_GAME_COMPANY1(void** player, char* name)
{
	struct Player* player1 = malloc(sizeof(struct Player));
	if (player1 == NULL)
	{
		printf("初始化失败");
		return;
	}

	*player = player1;

	strcpy(player1->name, name);
	player1->level = 0;
	player1->exp = 0;
}

//副本战斗，返回战斗是否胜利 1.胜利0.失败  玩家  游戏副本难度
int FIGH_GAME_COMPANY1(void* player, int gameDiff)
{
	struct Player* player1 = player;
	int Addexp = 0;

	switch (gameDiff)
	{
	case 1:
		Addexp = isWin(90, 1);
		break;
	case 2:
		Addexp = isWin(50, 2);
		break;
	case 3:
		Addexp = isWin(20, 3);
		break;
	default:
		break;
	}

	//累加经验到玩家
	player1->exp += Addexp;
	player1->level = player1->exp / 10;
	if (Addexp == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
		
}

int isWin(int winRate, int diff)
{
	int random = rand() % 100 + 1;//1-100
	if (random <= winRate)
	{
		return diff * 10;
	}
	else
		return 0;
}

//查看玩家信息
void PINFO_GAME_COMPANY1(void* player)
{
	struct Player* player1 = player;
	printf("玩家：%s\n 当前等级：%d\n 当前经验：%d\n", player1->name, player1->level, player1->exp);
}

//离开游戏
void EXIT_GAME_COMPANY1(void* player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}