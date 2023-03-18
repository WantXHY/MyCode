#include "Parray.h"


//初始化动态数组
struct Parray* Init_Parray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	//给数组开辟空间
	struct Parray* array = malloc(sizeof(struct Parray));
	if (array == NULL)
	{
		return NULL;a
	}
	//给数组初始化
	array->parray = malloc(sizeof(void*) * capacity);
	array->capacity = capacity;
	array->m_size = 0;

	return array;
}

//插入数组
void insert_Parray(struct Parray* array, int pos, void* data)
{
	if (array == NULL)
	{
		return;
	}if (data == NULL)
	{
		return;
	}

	//无效位置，尾插
	if (pos < 0 || pos >= array->m_size)
	{
		pos = array->m_size;
	}
	//判断是否存满，若满动态扩展
	if (array->m_size == array->capacity)
	{
		//计算新空间大小
		int newCapacity = array->capacity * 2;

		//开辟新空间,即替换void**parray
		void** NewSpace = malloc(sizeof(void*) * newCapacity);

		//拷贝原有数据
		memcpy(NewSpace, array->parray, sizeof(void*) * array->capacity);

		//释放原空间
		free(array->parray);

		//更新指向
		array->parray = NewSpace;

		//更新容量
		array->capacity = newCapacity;
	}

	//插入数值
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->parray[i + 1] = array->parray[i];//数字后移
	}
	array->parray[pos] = data;

	//更新大小
	array->m_size++;
}

//遍历数组
void foreach_Parray(struct Parray* array, void(*my_Print)(void*))
{
	if (array == NULL)
	{
		return;
	}
	if (my_Print == NULL)
	{
		return;
	}

	for (int i = 0; i < array->m_size; i++)
	{
		my_Print(array->parray[i]);
	}
}

//删除数组  按位置删除
void removeBypos_Parray(struct Parray* array, int pos)
{
	if (array == NULL)
	{
		return;
	}
	if (pos<0 || pos>array->m_size - 1)
	{
		return;
	}
	for (int i = pos; i < array->m_size; i++)
	{
		array->parray[i] = array->parray[i + 1];
	}
	array->m_size--;
}
//删除数组  按数字删除
void removeByValue_parray(struct Parray* array, void* data, int(*myCompare)(void*, void*))
{
	if (array == NULL || data == NULL)
	{
		return;
	}
	for (int i = 0; i < array->m_size; i++)
	{
		if (myCompare(array->parray[i], data))
		{
			removeBypos_Parray(array, i);
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