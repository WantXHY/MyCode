#include "code.h"

//加密
void codeFile(char* sourceR_file, char* destR_file)
{
	FILE* f1 = fopen(sourceR_file, "r");
	FILE* f2 = fopen(destR_file, "w");

	if (!f1 || !f2)
	{
		perror("fopen error");
		return -1;
	}
	char ch;
	while ((ch = fgetc(f1)) != EOF)
	{
		short temp = (short)ch;
		temp = temp << 4;

		temp = temp | 0x8000;//1000 0000 0000 0000十六进制0x8000

		temp += rand() % 16;

		//printf("%d\n", temp);

		fprintf(f2, "%hd", temp);
	}
	fclose(f1);
	fclose(f2);
}

//解密

void destFile(char* sourceR_file, char* destR_file)
{
	FILE* f1 = fopen(sourceR_file, "r");
	FILE* f2 = fopen(destR_file, "w");

	if (!f1 || !f2)
	{
		perror("fopen error");
		return;
	}

	short temp;
	while (!feof(f1))
	{
		fscanf(f1, "%hd", &temp);
		temp = temp << 1;
		temp = temp >> 5;
		char ch = (char)temp;

		fputc(ch, f2);
	}
	fclose(f1);
	fclose(f2);
}
