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
//初始化
struct Parray* Init_Parray(int capacity);
//插入数组
void insert_Parray(struct Parray* array, int pos, void* data);
//遍历数组
void foreach_Parray(struct Parray* array, void(*myPrint)(void*));
//按位置删除数组
void DelBypos_Parray(struct Parray* array, int pos);
//按数值删除数组
void DelByvalue_Parray(struct Parray* array, void* data, int(*myCompare)(void*,void*));
//销毁数组
void destory_Parray(struct Parray* array);