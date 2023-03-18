#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test04()
{
	FILE* f_write = fopen("./test04.txt", "w");
	if (f_write == NULL)
	{
		return;
	}
	fprintf(f_write, "hello world %dƒÍ  %d‘¬  %d»’", 2022, 5, 2);
	fclose(f_write);

	FILE* f_read = fopen("./test04.txt", "r");
	if (f_read == NULL)
	{
		return;
	}
	char buf[1024] = {0};
	while (!feof(f_write))
	{
		fscanf(f_read, "%s\n", buf);
		printf("%s\n", buf);
	}
	fclose(f_read);
}


int main()
{
	test04();
	system("pause");
	return 0;
}
