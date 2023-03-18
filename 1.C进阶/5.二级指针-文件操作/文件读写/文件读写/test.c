#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Show_parray(char** parray, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d�е��ַ�Ϊ��%s\n", i + 1, parray[i]);
	}
	printf("\n");
}

void Read_parray(FILE* fp, int len, char** parray)
{
	if (fp == NULL || len <= 0 || parray == NULL)
	{
		return;
	}
	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, fp) != NULL)
	{
		int currentlen = strlen(buf) + 1;
		char* currentStr = malloc(sizeof(char) * currentlen);
		strcpy(currentStr, buf);
		parray[index++] = currentStr;

		memset(buf, 0, 1024);//���buf
	}
}


int GetfileLines(FILE* fp)
{
	if (fp == NULL)
	{
		printf("��ʧ��\n");
		return -1;
	}
	int len = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, fp) != '\0')
	{
		len++;
	}
	//printf("%d\n", len);
	fseek(fp, 0, SEEK_SET);//�����Żؿ�ʼλ��
	return len;
}

int main()
{
	//���ļ�
	FILE* fp = fopen("./test.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	//ͳ����Ч����
	int len = GetfileLines(fp);
	char** parray = malloc((sizeof(char*) * len));

	//��ȡ�ļ������ݲ��ŵ�parray��
	Read_parray(fp, len, parray);

	//��ȡ����
	Show_parray(parray,len);


	for (int i = 0; i < len; i++)
	{
		if (parray[i] != NULL)
		{
			ferr(parray);
			parray = NULL;
		}
	}

	free(parray);
	parray = NULL;
	fclose(fp);

	system("pause");
	return 0;
}
