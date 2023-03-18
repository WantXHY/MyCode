#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MaxVertex 50
typedef char VertexInfo[9];

//ͼ�Ľṹ��
struct Graph
{
	//����
	VertexInfo Vertex[MaxVertex];
	//�� �ߵ������ά���� 
	int edge[MaxVertex][MaxVertex];
	//����ĸ���
	int vertexNum;
	//�ߵĸ���
	int edgeNum;
};

//�û����붥���ڶ��������е�λ��
int LocalVertex(Graph& g,VertexInfo v)
{
	//������������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.Vertex[i]) == 0)
		{
			return i;//�ҵ�Ԫ�أ������±�
		}
	}
	return -1;
}

//����һ��ͼ
void CreateGraph(Graph& g)
{
	cout << "������ͼ�Ķ������ͱ���: ����  ��" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "������" << g.vertexNum << "�������" << endl;
	for (int i = 0; i < g.vertexNum; i++)
	{
		cin >> g.Vertex[i];
	}
	//��ʼ�����б߶�������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = INT_MAX;
		}
	}
	cout << "������" << g.edgeNum << "���� ��β ��ͷ Ȩ��" << endl;
	int w;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2 >> w;
		//���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		//�߶�Ӧ�Ķ�ά���鸳ֵ
		g.edge[m][n] = w;
	}
}

//��ӡͼ
void PrintVertex(Graph &g)
{
	//ˮƽ��ͷ
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.Vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		//��ֱ
		cout << g.Vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			if (g.edge[i][j] == INT_MAX)
			{
				cout << "��" << "\t";
			}
			else
			{
				cout << g.edge[i][j] << "\t";
			}
		}
	}
	cout << endl;
}

void test()
{
	Graph g;
	CreateGraph(g);
	PrintVertex(g);
}

int main()
{
	test();
	system("pause");
	return 0;
}