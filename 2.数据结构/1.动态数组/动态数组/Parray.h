#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Parray
{
	void** parray;//维护真实在堆区创建的数组的指针
	int capacity;//数组容量
	int m_size;//数组大小
};

//初始化动态数组
struct Parray* Init_Parray(int capacity);

//插入数组
void insert_Parray(struct Parray* array, int pos, void* data);

//遍历数组
void foreach_Parray(struct Parray* array, void(*my_Print)(void*));

//删除数组  按位置删除
void removeBypos_Parray(struct Parray* array, int pos);

//删除数组  按数字删除
void removeByValue_parray(struct Parray* array, void* data, int(*myCompare)(void*, void*));

//销毁数组
void destory_Parray(struct Parray* array);
