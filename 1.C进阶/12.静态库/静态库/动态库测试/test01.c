#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib,"./动态库.lib")//添加现有项动态库代码

int main()
{
	printf("%d\n", mySub(20, 10));
	system("pause");
	return 0;
}
