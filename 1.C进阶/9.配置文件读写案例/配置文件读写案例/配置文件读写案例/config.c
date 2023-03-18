#include "config.h"



int getFilelines(const char* R_file)
{
	FILE* file = fopen(R_file, "r");
	if (file == NULL)
	{
		return -1;
	}
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, file) != NULL)
	{
		if (getRealline(buf))
		{
			lines++;
		}
		memset(buf, 0, 1024);//���buf
	}
	fclose(file);
	return lines;
	
}

//�ж��ļ���ǰ�����Ƿ���Ч��Ϣ
int getRealline(char* buf)
{
	if (strchr(buf, ':') == NULL)
	{
		return 0;
	}
	return 1;
}

//������Ϣ
void specConfigInfo(char* R_file, int len, struct ConfigInfo** Info)
{
	struct ConfigInfo* Config = malloc(sizeof(struct ConfigInfo) * len);
	if (Config == NULL)
	{
		return -1;
	}

	//���ļ�
	FILE* S_file = fopen(R_file, "r");
	if (S_file == NULL)
	{
		return -1;
	}

	char buf[1024] = { 0 };
	int index = 0;
	while (fgets(buf, 1024, S_file) != NULL)
	{
		if (getRealline(buf))
		{
			memset(Config[index].key, 0, 64);
			memset(Config[index].value, 0, 64);
			//heroud:1
			char* pos = strchr(buf, ':');
			strncpy(Config[index].key, buf, pos-buf);//��ȡheroud:
			strncpy(Config[index].value, pos+1, strlen(pos+1)-1);//��ȡ1
			//printf("key = %s\n", Config[index].key);
			//printf("value = %s\n", Config[index].value);

			index++;
		}
		memset(buf, 0, 1024);
	}
	*Info = Config;//������ϵ
	///*fclose(S_file);*/
}

char* getInfokey(char* key, struct ConfigInfo * Info, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (strcmp(key, Info[i].key) == 0)
		{
			return Info[i].value;
		}
		
	}
	return NULL;
}

void freeConfigInfo(struct ConfigInfo* Info)
{
	free(Info);
	Info = NULL;
}
