#include "Parray.h"


//��ʼ����̬����
struct Parray* Init_Parray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	//�����鿪�ٿռ�
	struct Parray* array = malloc(sizeof(struct Parray));
	if (array == NULL)
	{
		return NULL;a
	}
	//�������ʼ��
	array->parray = malloc(sizeof(void*) * capacity);
	array->capacity = capacity;
	array->m_size = 0;

	return array;
}

//��������
void insert_Parray(struct Parray* array, int pos, void* data)
{
	if (array == NULL)
	{
		return;
	}if (data == NULL)
	{
		return;
	}

	//��Чλ�ã�β��
	if (pos < 0 || pos >= array->m_size)
	{
		pos = array->m_size;
	}
	//�ж��Ƿ������������̬��չ
	if (array->m_size == array->capacity)
	{
		//�����¿ռ��С
		int newCapacity = array->capacity * 2;

		//�����¿ռ�,���滻void**parray
		void** NewSpace = malloc(sizeof(void*) * newCapacity);

		//����ԭ������
		memcpy(NewSpace, array->parray, sizeof(void*) * array->capacity);

		//�ͷ�ԭ�ռ�
		free(array->parray);

		//����ָ��
		array->parray = NewSpace;

		//��������
		array->capacity = newCapacity;
	}

	//������ֵ
	for (int i = array->m_size - 1; i >= pos; i--)
	{
		array->parray[i + 1] = array->parray[i];//���ֺ���
	}
	array->parray[pos] = data;

	//���´�С
	array->m_size++;
}

//��������
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

//ɾ������  ��λ��ɾ��
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
//ɾ������  ������ɾ��
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