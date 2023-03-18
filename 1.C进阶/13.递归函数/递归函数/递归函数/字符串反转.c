#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归实现字符串反转
void reverse(char* str)
{
	if (*str == '\0')
	{
		return;
	}
	reverse(str + 1);
	printf("%c\n", *str);
}
int Fib(int n)
{
	if (n < 3)
	{
		return 1;
	}
	else
	{
		return Fib(n - 1) + Fib(n - 2);
	}
}


void test01()
{
	char* str = "abcd";
	int len = strlen(str);
	
	reverse(str);
}
void test02()
{
	int n = 0;
	scanf("%d", &n);
	int ret=Fib(n);
	printf("%d\n", ret);
}



int main()
{
	//test01();
	test02();
	system("pause");
	return 0;
}
