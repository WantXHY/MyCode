#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Parray
{
	void** parray;
	int capacity;
	int m_size;
};
//��ʼ��
struct Parray* Init_Parray(int capacity);
//��������
void insert_Parray(struct Parray* array, int pos, void* data);
//��������
void foreach_Parray(struct Parray* array, void(*myPrint)(void*));
//��λ��ɾ������
void DelBypos_Parray(struct Parray* array, int pos);
//����ֵɾ������
void DelByvalue_Parray(struct Parray* array, void* data, int(*myCompare)(void*,void*));
//��������
void destory_Parray(struct Parray* array);