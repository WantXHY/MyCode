#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void Print01(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Selectsort01(int arr[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		int min = i;//设定最小值下标
		for (int j = i + 1; j < len; j++)
		{
			//判断设定最小值下标对应元素是否为最小
			if (arr[min] > arr[j])
			{
				//更新真实最小值下标
				min = j;
			}
		}
		//判断真实最小值下标是否与最初设定的i相同，若不同交换元素，相同不做更改
		if (i != min)
		{
			int temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
}
void test01()
{
	int arr[5] = { 5,2,1,4,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Selectsort01(arr, len);
	Print01(arr, len);
}


void Print02(char** parray, int len)
{

	for (int i = 0; i < len; i++)
	{
		printf("%s ", parray[i]);
	}
	printf("\n");
}

void Selectsort02(char* parray[],int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1;j< len; j++)
		{
			//if (parray[min] > parray[j])
			if(strcmp(parray[min], parray[j]) > 0)
			{
				min = j;
			}
		}
		if (i != min)
		{
			char* temp = parray[i];
			parray[i] = parray[min];
			parray[min] = temp;
		}
	}
}

void test02()
{
	char* parray[] = { "aaa","eee","ddd","ccc","bbb" };
	int len = sizeof(parray) / sizeof(char*);
	Selectsort02(parray, len);
	Print02(parray, len);
}

int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}
