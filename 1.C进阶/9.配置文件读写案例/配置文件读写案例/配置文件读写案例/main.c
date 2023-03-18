#include "config.h"
#include "code.h"


int main()
{
	srand((unsigned int)time(NULL));
	//���ļ�
	char* R_file = "./file.txt";
	int len= getFilelines(R_file);
	printf("%d\n", len);

	struct ConfigInfo* Info = NULL;
	specConfigInfo(R_file, len, &Info);

	printf("heroID:=%s\n", getInfokey("heroId", Info, len));
	printf("heroName:=%s\n", getInfokey("heroName", Info, len));
	printf("heroAtk:=%s\n", getInfokey("heroAtk", Info, len));
	printf("heroDef:=%s\n", getInfokey("heroDef", Info, len));
	printf("heroInfo:=%s\n", getInfokey("heroInfo", Info, len));
	freeConfigInfo(Info);
	Info = NULL;

	codeFile("./file.txt", "./�����ļ�file2.txt");
	destFile("./�����ļ�file2.txt", "./�����ļ�file3.txt");

	system("pause");
	return 0;
}
