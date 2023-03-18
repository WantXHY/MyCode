#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char* str = "helloworld@itcast.cn";
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };

	
	sscanf(str, "%[a-z]%*[@]%s", buf1,buf2);
	printf("%s\n", buf1);

	//sscanf(str, "%*[^@]@%s", buf2);
	printf("%s\n", buf2);

	system("pause");
	return 0;
}

//int main()
//{
//	char* str = "123abcd$myname@000qwe.";
//	char buf[1024] = { 0 };
//
//	sscanf(str, "%*[^$]$%[^@]", buf);
//	printf("%s\n", buf);
//
//	system("pause");
//	return 0;
//}