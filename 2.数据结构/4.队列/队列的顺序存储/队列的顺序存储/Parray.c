#include "Parray.h"

//初始化
struct Parray* Init_Parray(int capacity)
{
	if (capacity <=0)
	{
		return NULL;
	}
	//开辟空间
	struct Parray* array = malloc(sizeof(struct Parray));
	if (array == NULL)
	{
		return NULL;
	} 
	//初始化
	array->parray = malloc(sizeof(void*) * capacity);
	array->m_size = 0;
	array->capacity = capacity;

	return array;
}

//插入数组
void insert_Parray(struct Parray* array, int pos, void* data)
{
	if (array == NULL|| data == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= array->m_size)
	{
		//进行尾插
		pos = array->m_size;
	}
	//判断是否存满
	if (array->m_size == array->capacity)
	{
		//计算扩展新空间大小
		int NewCapacity = array->capacity * 2;
		//开辟新空间
		void** NewSpace = malloc(sizeof(void*) * NewCapacity);
		//拷贝原有数据
		memcpy(NewSpace, array->parray, sizeof(void*) * array->capacity);
		//释放原空间
		free(array->parray);
		//更新指向
		array->parray = NewSpace;
		//更新容量
		array->capacity = NewCapacity;
	}
	//插入数据
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->parray[i + 1] = array->parray[i];
	}
	array->parray[pos] = data;
	//更新大小
	array->m_size++;
}

//遍历数组
void foreach_Parray(struct Parray* array,void(*myPrint)(void*))
{
	if (array == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		myPrint(array->parray[i]);
	}
}

//按位置删除数组
void DelBypos_Parray(struct Parray* array, int pos)
{
	if (array == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= array->m_size)
	{
		return;
	}
	for (int i = pos; i < array->m_size; i++)
	{
		array->parray[i] = array->parray[i + 1];
	}
	array->m_size--;
}
//按数值删除数组
void DelByvalue_Parray(struct Parray* array, void* data,int(*myCompare)(void*, void*))
{
	if (array == NULL || data == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		if (myCompare(array->parray[i], data))
		{
			DelBypos_Parray(array, i);
			break;
		}
	}
}

//销毁数组
void destory_Parray(struct Parray* array)
{
	if (array == NULL)
	{
		return;
	}
	if (array->parray != NULL)
	{
		free(array->parray);
		array->parray = NULL;
	}
	free(array);
	array = NULL;
}
