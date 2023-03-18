#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MyStrstr(char* str,char* Mystr)
{
	int count = 0;
	while (*str != '\0')
	{
		if (*str != *Mystr)
		{
			str++;
			count++;
			continue;
		}

		//找到第一个对应元素，创建临时指针
		char* temp = str;
		char* Mytemp = Mystr;
		while (*Mytemp != '\0')
		{
			if (*temp != *Mytemp)
			{
				str++;
				count++;
				break;
			}
			temp++;
			Mytemp++;
		}
		if (*Mytemp == '\0')
		{
			return count;//返回下标
		}
	}
	return -1;
}
int MyStrstr(char* str, char* Mystr)
{
	int len = strlen(Mystr);
	int count = 0;
	while (*str != '\0')
	{
		if (*str != *Mystr)
		{
			str++;
			count++;
			continue;
		}
		if (memcmp(str, Mystr, len) == 0)
		{
			return count;//返回下标
		}
		else
		{
			str++;
			count++;
		}
	}
	return -1;
}

void test()
{
	char* str = "abcdefgh";
	char* Mystr = "def";
	int ret = MyStrstr(str, Mystr);
	if (ret != -1)
	{
		printf("YES:%d\n", ret);
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}
