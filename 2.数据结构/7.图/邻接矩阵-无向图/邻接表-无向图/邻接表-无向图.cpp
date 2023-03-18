#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#if 1
#define MaxVertex 100
#endif

//�ڽӵ�Ľṹ��
struct edgeNode
{
	//��ǰ�����ڶ��������е�λ��
	int position;
	//ָ������ڵ��ָ��
	struct edgeNode* next; 
	//�ڵ������Ϣ,Ȩֵ
	int weight;
};
//��������Ľṹ��
struct Vertex
{
	//��������
	char name[9];
	//ָ���ڽӵ�ṹ��ָ��
	struct edgeNode* first;
};

//�ڽӱ�ͼ�ṹ��
struct GraphList
{
	//��������
	Vertex head[MaxVertex];
	//�������
	int VertexNum;
	//�ߵĸ���
	int edgeNum;
};

int LocalVertex(GraphList& g, char* name)
{
	for (int i = 0; i < g.VertexNum; i++)
	{
		if (strcmp(name, g.head[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//����һ��ͼ
void CreateGraph(GraphList& g)
{
	cout << "������ͼ�Ķ������ͱ���������  ��" << endl;
	cin >> g.VertexNum >> g.edgeNum;
	cout << "������" << g.VertexNum << "�����ֵ" << endl;
	for (int i = 0; i < g.VertexNum; i++)
	{
		cin >> g.head[i].name;
		g.head[i].first = NULL;
	}
	cout << "������" << g.edgeNum << "���ߣ�����1  ����2" << endl;
	char v1[9], v2[9];
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2;
		//��MΪͷ�ڵ������n��m���ڽӵ�
		//���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);
		//����������ڽӵ�
		edgeNode* pNew = new edgeNode;
		pNew->position = n;//��ǰ�ڵ��ڶ��������е�λ��
		//pNew��ӵ�ͷ�ڵ������еĵ�m��Ԫ�أ���Ӧ��������
		//ͷ�巨��β�巨��Ҫ����
		pNew->next = g.head[m].first;
		g.head[m].first = pNew;
#if 1
		//��Ϊ if 0Ϊ����ͼ
		//��NΪͷ�ڵ������m��n���ڽӵ�
		edgeNode* pNew1 = new edgeNode;
		pNew1->position = m;
		pNew1->next = g.head[n].first;
		g.head[n].first = pNew1;

#endif
	}
}

//��ӡͼ
void PrintGraph(GraphList& g)
{
	for (int i = 0; i < g.VertexNum; i++)
	{
		edgeNode* pNode = g.head[i].first;
		cout << g.head[i].name << ":";
		while (pNode != NULL)
		{
			int index = pNode->position;
			cout << g.head[index].name << ",";
			pNode = pNode->next;
		}
		cout << endl;
	}
	cout << endl;
}



void test()
{
	GraphList g;
	CreateGraph(g);
	PrintGraph(g);
}

int main()
{
	test();
	system("pause");
	return 0;
}
