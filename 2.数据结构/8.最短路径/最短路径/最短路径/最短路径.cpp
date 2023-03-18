#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//���Ķ�����
#define MaxVertex 50
//��Ŷ������Ƶ�����
typedef char VertexInfo[9];

//ͼ�Ľṹ
struct Graph
{
	//��������
	VertexInfo Vertex[MaxVertex];
	//�ߵĶ�ά����
	int edge[MaxVertex][MaxVertex];
	//�������
	int VertexNum;
	//�ߵĸ���
	int edgeNum;
};

//���û�����Ķ����ڶ��������е�λ��
int LocalVertex(Graph& g,VertexInfo v)
{
	//��������
	for (int i = 0; i < g.VertexNum; i++)
	{
		if (strcmp(v, g.Vertex[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

//����ͼ
void CreateGraph(Graph& g)
{
	cout << "������ͼ�Ķ������ͱ���������  ��" << endl;
	cin >> g.VertexNum >> g.edgeNum;
	cout << "������" << g.VertexNum << "������ĸ���" << endl;
	//��ʼ������
	for (int i = 0; i < g.VertexNum; i++)
	{
		cin >> g.Vertex[i];
	}
	//��ʼ����
	for (int i = 0; i < g.VertexNum; i++)
	{
		for (int j = 0; j < g.VertexNum; j++)
		{
			g.edge[i][j] = INT_MAX;
		}
	}
	cout << "������" << g.edgeNum << "���ߣ�����1������2,Ȩ��" << endl;
	int w;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2 >> w;
		//���û�����Ķ����ڶ��������е�λ��
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		//�߶�Ӧ�Ķ�ά���鸳ֵ
		g.edge[m][n] = w;
		g.edge[n][m] = w;
	}
}

//��ӡͼ
void PrintGraph(Graph& g)
{
	//ˮƽ��ͷ
	cout << "\t";
	for (int i = 0; i < g.VertexNum; i++)
	{
		cout << g.Vertex[i] << "\t";
	}
	for (int i = 0; i < g.VertexNum; i++)
	{
		cout << endl;
		cout << g.Vertex[i] << "\t";
		for (int j = 0; j < g.VertexNum; j++)
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

//���·��
//�Ͻ�˹�����㷨
//path��һ���㵽��ǰ��ľ������
void dijkstraPath(Graph& g, int* path, int* dist, int v0)
{
	int min = 0;
	int pos = v0;//���ʵ���ʼ����
	//����һ�����飬��Ƕ����Ƿ��Ѿ�������
	bool* visited = new bool[g.VertexNum];
	//��ʼ��
	for (int i = 0; i < g.VertexNum; i++)
	{
		visited[i] = false;//����δ����
		if (i != v0)//�ų����㵽������ļ���
		{
			//��ʼ�����е������ڽӵ㶼��v0��
			path[i] = v0;
			//v0�����������Ȩ��
			dist[i] = g.edge[v0][i];
			cout << g.Vertex[0] << "��" << g.Vertex[i]
				<< "���룺dist[" << i << "]=" << dist[i] << endl;
		}
		else
		{
			// path[]���� - ����ǰ���������ڽӵ�
			// dist[]���� - �ӳ����㵽���������̾���
			// i == v0���㵽�㣬û���κ�����, ������·��
			path[i] = -1;
			dist[i] = INT_MAX;//��Ч·��
		}
	}
	visited[v0] = true;//��v0���Ϊ�ѷ���
	for (int i = 0; i < g.VertexNum; i++)
	{
		min = INT_MAX;
		for (int j = 0; j < g.VertexNum; j++)
		{
			// û�б�����, �����ҵ���ӵ�и�СȨֵ�ı�
			if (!visited[j] && min > dist[j])
			{
				min = dist[j];
				pos = j;
				cout << "++������£�pos=" << pos
					<< "����Ϊ" << g.Vertex[pos] << endl;
			}
		}
		//posλ�õĶ�����Ϊ�ѷ���
		visited[pos] = true;
		
		for (int j = 0; j < g.VertexNum; j++)
		{
			// g.edge[pos][j] < INT_MAX - �ж�pos->j�������Ǵ��ڵ�
			if (!visited[j] && dist[pos] + g.edge[pos][i] < dist[j] && g.edge[pos][j] < INT_MAX)
			{
				// ������̾���
				//���� ��j����E  pos����B�����A��E���·��
				dist[j] = dist[pos] + g.edge[pos][j];
				//����·��, ������j����Ķ�����pos
				path[j] = pos;
				cout << "=== ������̾���: dist[" << j
					<< "] = " << dist[j] << endl;
			}
		}
	}
}

void showPath(Graph& g, int* path, int v0, int v)
{
	stack<int> st;
	int temp = v;
	while (temp != v0)
	{
		st.push(temp);
		//Ѱ����һ������
		temp = path[temp];
	}
	st.push(v0);

	//��ӡ·��
	while (!st.empty())
	{
		cout << g.Vertex[st.top()] << " ";
		st.pop();
	}
}

void test01()
{
	Graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	cout << "�Ͻ�˹�����㷨" << endl;
	// path���� - ����ǰ���������ڽӵ�
	int path[50];
	// dist[] ���� - �ӳ����㵽���������̾���
	int dist[50];
	// ������
	int v0 = 0;
	dijkstraPath(graph, path, dist, v0);
	for (int i = 1; i < graph.VertexNum; ++i)
	{
		cout << "·��: ";
		showPath(graph, path, v0, i);
		cout << "·������: " << dist[i] << endl;
	}
	cout << "Keyboard not found, press F1 to continue..." << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}