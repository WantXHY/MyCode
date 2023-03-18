#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//���Ķ�����
#define MaxVertex 50
//��Ŷ������Ƶ�����
typedef char VertexInfo[9];

// ����ͼ�Ľṹ
struct graph
{
	//ͼ�Ķ�������
	VertexInfo vertex[MaxVertex];
	//ͼ�ı�
	//�ߵ����� ��ά����
	int edge[MaxVertex][MaxVertex];
	//����ĸ���
	int vertexNum;
	//�ߵĸ���
	int edgeNum; 
};

//���û�����Ķ����ڶ��������е�λ��
int LocalVertex(graph &g, VertexInfo v)
{
	//������������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.vertex[i]) == 0)
		{
			//�ҵ��±꣬����Ԫ��
			return i;
		}
	}
	//û�ҵ�
	return -1;
}

//����һ��ͼ
void CreateGraph(graph &g)
{
	cout << "������ͼ�Ķ������ͱ���������  ��" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "������" << g.vertexNum << "������ĸ���" << endl;
	for (int i = 0; i < g.vertexNum; i++)
	{
		cin >> g.vertex[i];//��ʼ��ÿ������
	}
	//��ʼ�����б߶�������
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = 0;
		}
	}
	cout << "������" << g.edgeNum << "���ߣ�����1 ����2" << endl;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		//���û����붥���ڶ��������е�λ��
		int m = LocalVertex(g, v1);//��ȡv1�ڶ�ά�����е�λ��
		int n = LocalVertex(g, v2);//��ȡv2�ڶ�ά�����е�λ��

		//�߶�Ӧ�Ķ�ά���鸳ֵ
		g.edge[m][n] = 1;
		g.edge[n][m] = 1;
	}
}

//��ӡͼ
void PrintGraph(graph& g)
{
	//ˮƽ��ͷ
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		//��ֱ
		cout << g.vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			cout << g.edge[i][j] << "\t";
		}
	}
	cout << endl;
}

//������ȱ���
void DFS(graph& g)
{
	bool* visited = new bool[g.vertexNum];
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	//�Ӷ��������еĵ�һ����ʼ����
	stack<int>st;//int-����������±�
	visited[0] = true;
	cout << g.vertex[0] << " ";
	st.push(0);

	while (!st.empty())
	{
		//�������еĶ��㣬���ڽӵ�-ջ��Ԫ�ض�Ӧ���ڽӵ�
		for (int i = 0; i < g.vertexNum; ++i)
		{
			//ջ��Ԫ���ڶ��������е�λ��
			int top = st.top();
			if (!visited[i] && g.edge[top][i] > 0)//����ÿһ���ڵ���������нڵ�
			{
				//�����ö���
				visited[i] = true;
				cout << g.vertex[i] << " ";
				//�ڽӵ�ѹջ
				st.push(i);
			}
		}
		//ջ���Ķ����붥����ɵı�ȫ���ж�һ��
		st.pop();
	}
	delete[] visited;
} 

//������ȱ���
void BFS(graph& g)
{
	//��֤���㲻���ظ�����
	bool* visited = new bool[g.vertexNum];
	//��ʼ��Ϊ���ж��㶼û�б�����
	for (int i = 0; i < g.vertexNum; i++)
	{
		visited[i] = false;
	}
	//��һ�����㿪ʼ����
	queue<int> q;
	visited[0] = true;
	cout << g.vertex[0] << " ";
	q.push(0);
	//�������Ϊ�գ��������
	while (!q.empty())
	{
		//��ͷ������±�ֵȡ��
		int front = q.front();
		//�������ж��㣬�ҳ��ڽӵ�
		for (int i = 0; i < g.vertexNum; i++)
		{
			if (!visited[i] && g.edge[front][i] > 0)
			{
				visited[i] = true;
				cout << g.vertex[i] << " ";
				q.push(i);
			}
		}
		q.pop();//�����ڽӵ㶼������ɣ�������
	}
	delete[] visited;
}

void test01()
{
	graph graph;
	CreateGraph(graph);
	PrintGraph(graph);
}
//�����������
void test02()
{
	graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	DFS(graph);
}

//�����������
void test03()
{
	graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	BFS(graph);
}

int main()
{
	//test01();
	//test02();
	test03();
	system("pause");
	return 0;
}