#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MaxVertex 50
typedef char VertexInfo[9];

//图的结构体
struct Graph
{
	//顶点
	VertexInfo Vertex[MaxVertex];
	//边 边的数组二维矩阵 
	int edge[MaxVertex][MaxVertex];
	//顶点的个数
	int vertexNum;
	//边的个数
	int edgeNum;
};

//用户输入顶点在顶点数组中的位置
int LocalVertex(Graph& g,VertexInfo v)
{
	//遍历顶点数组
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.Vertex[i]) == 0)
		{
			return i;//找到元素，返回下标
		}
	}
	return -1;
}

//构件一个图
void CreateGraph(Graph& g)
{
	cout << "请输入图的顶点数和边数: 顶点  边" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "请输入" << g.vertexNum << "顶点个数" << endl;
	for (int i = 0; i < g.vertexNum; i++)
	{
		cin >> g.Vertex[i];
	}
	//初始化所有边都不存在
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = INT_MAX;
		}
	}
	cout << "请输入" << g.edgeNum << "条边 弧尾 弧头 权重" << endl;
	int w;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2 >> w;
		//求用户输入的顶点在顶点数组中的位置
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		//边对应的二维数组赋值
		g.edge[m][n] = w;
	}
}

//打印图
void PrintVertex(Graph &g)
{
	//水平表头
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.Vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		//垂直
		cout << g.Vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			if (g.edge[i][j] == INT_MAX)
			{
				cout << "∞" << "\t";
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