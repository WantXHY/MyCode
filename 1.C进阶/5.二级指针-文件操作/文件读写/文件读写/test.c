#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Show_parray(char** parray, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d行的字符为：%s\n", i + 1, parray[i]);
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

		memset(buf, 0, 1024);//清空buf
	}
}


int GetfileLines(FILE* fp)
{
	if (fp == NULL)
	{
		printf("打开失败\n");
		return -1;
	}
	int len = 0;
	char buf[1024] = { 0 };
	while (fgets(buf, 1024, fp) != '\0')
	{
		len++;
	}
	//printf("%d\n", len);
	fseek(fp, 0, SEEK_SET);//将光标放回开始位置
	return len;
}

int main()
{
	//读文件
	FILE* fp = fopen("./test.txt", "r");
	if (fp == NULL)
	{
		perror("fopen error");
		return -1;
	}

	//统计有效行数
	int len = GetfileLines(fp);
	char** parray = malloc((sizeof(char*) * len));

	//读取文件中数据并放到parray中
	Read_parray(fp, len, parray);

	//读取数据
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
