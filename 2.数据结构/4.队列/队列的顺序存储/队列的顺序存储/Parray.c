#include "Parray.h"

//��ʼ��
struct Parray* Init_Parray(int capacity)
{
	if (capacity <=0)
	{
		return NULL;
	}
	//���ٿռ�
	struct Parray* array = malloc(sizeof(struct Parray));
	if (array == NULL)
	{
		return NULL;
	} 
	//��ʼ��
	array->parray = malloc(sizeof(void*) * capacity);
	array->m_size = 0;
	array->capacity = capacity;

	return array;
}

//��������
void insert_Parray(struct Parray* array, int pos, void* data)
{
	if (array == NULL|| data == NULL)
	{
		return;
	}
	if (pos < 0 || pos >= array->m_size)
	{
		//����β��
		pos = array->m_size;
	}
	//�ж��Ƿ����
	if (array->m_size == array->capacity)
	{
		//������չ�¿ռ��С
		int NewCapacity = array->capacity * 2;
		//�����¿ռ�
		void** NewSpace = malloc(sizeof(void*) * NewCapacity);
		//����ԭ������
		memcpy(NewSpace, array->parray, sizeof(void*) * array->capacity);
		//�ͷ�ԭ�ռ�
		free(array->parray);
		//����ָ��
		array->parray = NewSpace;
		//��������
		array->capacity = NewCapacity;
	}
	//��������
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->parray[i + 1] = array->parray[i];
	}
	array->parray[pos] = data;
	//���´�С
	array->m_size++;
}

//��������
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

//��λ��ɾ������
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
//����ֵɾ������
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

//��������
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
