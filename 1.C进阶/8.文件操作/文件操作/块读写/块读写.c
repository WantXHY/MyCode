#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person
{
	char name[20];
	int age;
}person;

void test03()
{
	FILE* f_write = fopen("./test03.txt", "wb");
	if (f_write == NULL)
	{
		return;
	}
	person date[3] = { {"我",12}, {"你",22},{"他",32} };
	for (int i = 0; i < 3; i++)
	{
		fwrite(&date[i], sizeof(person), 1, f_write);
	}
	fclose(f_write);
	//读文件
	FILE* f_read = fopen("./test03.txt", "rb");
	if (f_read == NULL)
	{
		return;
	}
	person temp[3];
	fread(&temp, sizeof(person), 3, f_read);
	for (int i = 0; i < 3; i++)
	{
		printf("%s %d\n", temp[i].name, temp[i].age);
	}
	fclose(f_read);

	//读文件
	FILE* fread2 = fopen("./test03.txt", "rb");
	if (fread2 == NULL)
	{
		perror("fopen error");
		return;
	}
	person temp2;

	//fseek(fread2, sizeof(person) * 1, SEEK_SET);
	fseek(fread2, -(long)sizeof(person) * 1, SEEK_END);

	rewind(fread2);//光标制到首位

	fread(&temp2, sizeof(person), 1, fread2);
	printf("%s  %d\n", temp2.name, temp2.age);

	fclose(fread2);
}

int main()
{
	test03();
	system("pause");
	return 0;
}
