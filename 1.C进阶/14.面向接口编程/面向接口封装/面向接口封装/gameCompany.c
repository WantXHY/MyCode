#include "gameCompany.h"

//��ʼ����Ϸ,���ָ��  �������
void INIT_GAME_COMPANY1(void** player, char* name)
{
	struct Player* player1 = malloc(sizeof(struct Player));
	if (player1 == NULL)
	{
		printf("��ʼ��ʧ��");
		return;
	}

	*player = player1;

	strcpy(player1->name, name);
	player1->level = 0;
	player1->exp = 0;
}

//����ս��������ս���Ƿ�ʤ�� 1.ʤ��0.ʧ��  ���  ��Ϸ�����Ѷ�
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

	//�ۼӾ��鵽���
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

//�鿴�����Ϣ
void PINFO_GAME_COMPANY1(void* player)
{
	struct Player* player1 = player;
	printf("��ң�%s\n ��ǰ�ȼ���%d\n ��ǰ���飺%d\n", player1->name, player1->level, player1->exp);
}

//�뿪��Ϸ
void EXIT_GAME_COMPANY1(void* player)
{
	if (player == NULL)
	{
		return;
	}
	free(player);
	player = NULL;
}