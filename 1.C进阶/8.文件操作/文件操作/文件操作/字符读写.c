#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//fputc  fgetc
void test01()
{
	//写文件
	FILE* f_write = fopen("./test.txt", "w+");
	if (f_write == NULL)
	{
		return;
	}
	char buf[] = "hello world";
	for (int i = 0; i < strlen(buf); i++)
	{
		fputc(buf[i], f_write);
	}
	fclose(f_write);

	//读文件
	FILE* f_read = fopen("./test.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char ch;
	while ((ch = fgetc(f_read)) != EOF)
	{
		printf("%c", ch);
	}
	fclose(f_read);
}


int main()
{
	test01();
	system("pause");
	return 0;
}
