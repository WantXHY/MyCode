#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Parray
{
	void** parray;//ά����ʵ�ڶ��������������ָ��
	int capacity;//��������
	int m_size;//�����С
};

//��ʼ����̬����
struct Parray* Init_Parray(int capacity);

//��������
void insert_Parray(struct Parray* array, int pos, void* data);

//��������
void foreach_Parray(struct Parray* array, void(*my_Print)(void*));

//ɾ������  ��λ��ɾ��
void removeBypos_Parray(struct Parray* array, int pos);

//ɾ������  ������ɾ��
void removeByValue_parray(struct Parray* array, void* data, int(*myCompare)(void*, void*));

//��������
void destory_Parray(struct Parray* array);
