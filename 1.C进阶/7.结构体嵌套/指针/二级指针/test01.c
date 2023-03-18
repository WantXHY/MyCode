#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Teacher
{
	char* name;
	char** students;
};

void allocateSpace(struct Teacher*** teacher)
{
	if (teacher == NULL)
	{
		return;
	}
	//�����ڴ�
	struct Teacher** temp = malloc(sizeof(struct Teacher*) * 3);

	//����ʦ�����ڴ�
	for (int i = 0; i < 3; i++)
	{
		temp[i] = malloc(sizeof(struct Teacher));

		//g����ʦ���ַ���ռ�
		temp[i]->name = malloc(sizeof(char) * 64);
		//����ʦ������
		sprintf(temp[i]->name, "Teacher_%d", i + 1);

		//��ѧ������������ڴ�
		temp[i]->students = malloc(sizeof(char*) * 4);
		//��ѧ���������ڴ�
		for (int j = 0; j < 4; j++)
		{
			temp[i]->students[j] = malloc(sizeof(char) * 64);
			sprintf(temp[i]->students[j], "%s_Student_%d", temp[i]->name, j + 1);
		}
	}
	*teacher = temp;
}
void PrintTeacher(struct Teacher** parray)
{
	if (parray == NULL)
	{
		return;
	}
	for(int i = 0; i < 3; i++) 
	{
		printf("%s\n", parray[i]->name);
		for (int j = 0; j < 4; j++)
		{
			printf("   %s\n", parray[i]->students[j]);
		}
	}
}

void freeTeacher(struct Teacher** parray)
{
	if (parray == NULL)
	{
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		//�ͷ���ʦ����
		if (parray[i]->name != NULL)
		{
			free(parray[i]->name);
			parray[i]->name = NULL;
		}
		//�ͷ�ѧ������
		for (int j = 0; j < 4; j++)
		{
			if (parray[i]->students[j] != NULL)
			{
				free(parray[i]->students[j] != NULL);
				parray[i]->students[j] = NULL;
			}
		}
		//�ͷ�ѧ������
		if (parray[i]->students != NULL)
		{
			free(parray[i]->students);
			parray[i]->students = NULL;
		}
		//�ͷ���ʦ
		if (parray[i] != NULL)
		{
			free(parray[i]);
			parray[i] = NULL;
		}
	}
	//�ͷ���ʦ����
	if (parray != NULL)
	{
		free(parray);
		parray = NULL;
	}
}

void test01()
{
	struct Teacher** parray = NULL;

	allocateSpace(&parray);

	PrintTeacher(parray);

	freeTeacher(parray);
	parray = NULL;
}
int main()
{
	test01();
	system("pause");
	return 0;
}
