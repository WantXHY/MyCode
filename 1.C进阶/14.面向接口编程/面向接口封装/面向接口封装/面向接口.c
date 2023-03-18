#include "gameCompany.h"

//设计接口
//初始化游戏,玩家指针  玩家姓名
typedef void(*INIT_GAME)(void** player, char* name);

//副本战斗，返回战斗是否胜利 1.胜利0.失败  玩家  游戏副本难度
typedef int(*FIGH_GAME)(void* player, int gameDiff);

//查看玩家信息
typedef void(*PINFO_GAME)(void* player);

//离开游戏
typedef void(*EXIT_GAME)(void* player);


void palyerGame(INIT_GAME init, FIGH_GAME fight, PINFO_GAME pinfoGmae, EXIT_GAME exitGame)
{
	//初始化
	void* player = NULL;
	printf("请输入姓名：\n");
	char userName[64];
	scanf("%s", userName);

	init(&player, userName);

	//副本难度
	int diff = -1;

	while (1)
	{
		getchar();
		system("cls");

		printf("请输入副本难度：\n");
		printf("1、简单\n");
		printf("2、中等\n");
		printf("3、困难\n");
		scanf("%d", &diff);

		getchar();//取走换行符

		//战斗
		int ret = fight(player, diff);
		if (ret == 0)
		{
			printf("失败\n");
			break;
		}
		else
		{
			printf("成功,玩家信息如下：\n");
			pinfoGmae(player);
		}

	}

	//关闭游戏
	exitGame(player);
}


int main()
{
	srand((unsigned int)time(NULL));

	//对接
	palyerGame(INIT_GAME_COMPANY1, FIGH_GAME_COMPANY1, PINFO_GAME_COMPANY1, EXIT_GAME_COMPANY1);

	system("pause");
	return 0;
}
