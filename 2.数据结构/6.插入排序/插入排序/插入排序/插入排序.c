#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void insertSort(int arr[], int len)
{
	//��С�����������
	//for (int i = 1; i < len; i++)
	//{
	//	if (arr[i - 1] > arr[i])
	//	{
	//		int temp = arr[i];
	//		int j = i - 1;
	//		for (; j >= 0 && temp < arr[j]; j--)
	//		{
	//			arr[j + 1] = arr[j];//���ݺ���
	//		}
	//		arr[j + 1] = temp;
	//	}
	//}

	//�Ӵ�С
	for (int i = 1; i < len; i++)
	{
		if (arr[i - 1] < arr[i])
		{
			int temp = arr[i];
			int j = i - 1;
			for (; j >= 0 && temp > arr[j]; j--)
			{
				arr[j + 1] = arr[j];//���ݺ���
			}
			arr[j + 1] = temp;
		}
	}
}

void print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

void test()
{
	int arr[] = { 4,1,2,3,6,7,8,5 };
	int len = sizeof(arr) / sizeof(int);
	insertSort(arr, len);
	print(arr, len);
}

int main()
{
	test();
	system("pause");
	return 0;
}
