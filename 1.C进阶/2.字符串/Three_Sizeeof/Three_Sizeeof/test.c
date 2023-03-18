#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//拷贝
//方法1
void CopyString01(char *dest,char *src)
{
	int len = strlen(src);
	for (int i = 0; i < len; i++)
	{
		dest[i] = src[i];
	}
	dest[len] = '\0';
}
//方法2
void CopyString02(char* dest, char* src)
{
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}
//方法3
void CopyString03(char *dest, char *src)
{
	while(*dest++=*src++){}//碰\0先拷贝，在判断退出循环
}

//反转
void reverseString(char *str)
{
	int len = strlen(str);
	int start = 0;
	int end = len - 1;
	while (start < end)
	{
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int main()
{
	char* str = "hello world";
	char buf[1024];
	char str1[] = "hello world";

	//CopyString01(buf,str);
	//printf("%s\n", buf);

	//CopyString02(buf, str);
	//printf("%s\n", buf);

	CopyString03(buf, str);
	printf("%s\n", buf);

	reverseString(str1);
	printf("%s\n", str1);

	system("pause");
	return 0;
}
