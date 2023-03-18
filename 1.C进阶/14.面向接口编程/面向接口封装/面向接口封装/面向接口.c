#include "gameCompany.h"

//��ƽӿ�
//��ʼ����Ϸ,���ָ��  �������
typedef void(*INIT_GAME)(void** player, char* name);

//����ս��������ս���Ƿ�ʤ�� 1.ʤ��0.ʧ��  ���  ��Ϸ�����Ѷ�
typedef int(*FIGH_GAME)(void* player, int gameDiff);

//�鿴�����Ϣ
typedef void(*PINFO_GAME)(void* player);

//�뿪��Ϸ
typedef void(*EXIT_GAME)(void* player);


void palyerGame(INIT_GAME init, FIGH_GAME fight, PINFO_GAME pinfoGmae, EXIT_GAME exitGame)
{
	//��ʼ��
	void* player = NULL;
	printf("������������\n");
	char userName[64];
	scanf("%s", userName);

	init(&player, userName);

	//�����Ѷ�
	int diff = -1;

	while (1)
	{
		getchar();
		system("cls");

		printf("�����븱���Ѷȣ�\n");
		printf("1����\n");
		printf("2���е�\n");
		printf("3������\n");
		scanf("%d", &diff);

		getchar();//ȡ�߻��з�

		//ս��
		int ret = fight(player, diff);
		if (ret == 0)
		{
			printf("ʧ��\n");
			break;
		}
		else
		{
			printf("�ɹ�,�����Ϣ���£�\n");
			pinfoGmae(player);
		}

	}

	//�ر���Ϸ
	exitGame(player);
}


int main()
{
	srand((unsigned int)time(NULL));

	//�Խ�
	palyerGame(INIT_GAME_COMPANY1, FIGH_GAME_COMPANY1, PINFO_GAME_COMPANY1, EXIT_GAME_COMPANY1);

	system("pause");
	return 0;
}
