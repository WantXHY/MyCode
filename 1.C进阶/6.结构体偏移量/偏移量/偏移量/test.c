#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct Person
{
	char a;
	int b;
};
void test()
{
	struct Person p1;
	struct Person* p = &p1;
	printf("b的偏移量: %d\n", offsetof(struct Person, b));
	printf("b的偏移量: %d\n", (int)&(p->b)-(int)p);//b的地址-首地址
}
void test01()
{
	struct Person p1 = { 'a',10 };
	//取首地址强转(char*,一个一个移动)+偏移量
	printf("p1.b：%d\n", *(int*)((char*)&p1 + offsetof(struct Person, b)));
	printf("p1.b: %d\n", *(int*)((int*)&p1 + 1));
}
struct Person2
{
	char c;
	int d;
	struct Person e;
};
void test02()
{
	struct Person2 p2= { 'a',10,'b',20 };
	int offset1 = offsetof(struct Person2, e);
	int offset2 = offsetof(struct Person, b);
	printf("p2.b:%d\n", *(int*)((char*)&p2 + offset1 + offset2));
	printf("p2.b:%d\n", ((struct Person*)((char*)&p2 + offset1))->b);
}

int main()
{
	test();
	test01();
	test02();
	system("pause");
	return 0;
}
