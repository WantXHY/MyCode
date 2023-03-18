#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//fputs  fgets
void test02()
{
	FILE* f_write = fopen("./test02.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	char* buf[] = {
		"你你你\n",
		"我我我\n",
		"他他他\n",
	};
	for (int i = 0; i < 3; i++)
	{
		fputs(buf[i], f_write);
	}
	fclose(f_write);

	//读文件
	FILE* f_read = fopen("./test02.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char buf1[1024] = { 0 };
	while (!feof(f_read))
	{
		fgets(buf1, 1024, f_read);
		printf("%s", buf1);

	}
	fclose(f_read);
}

int main()
{
	test02();

	system("pause");
	return 0;
}
