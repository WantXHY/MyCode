#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//最大的顶点数
#define MaxVertex 50
//存放顶点名称的数组
typedef char VertexInfo[9];

// 定义图的结构
struct graph
{
	//图的顶点数组
	VertexInfo vertex[MaxVertex];
	//图的边
	//边的数组 二维矩阵
	int edge[MaxVertex][MaxVertex];
	//顶点的个数
	int vertexNum;
	//边的个数
	int edgeNum; 
};

//求用户输入的顶点在顶点数组中的位置
int LocalVertex(graph &g, VertexInfo v)
{
	//遍历顶点数组
	for (int i = 0; i < g.vertexNum; ++i)
	{
		if (strcmp(v, g.vertex[i]) == 0)
		{
			//找到下标，返回元素
			return i;
		}
	}
	//没找到
	return -1;
}

//构建一个图
void CreateGraph(graph &g)
{
	cout << "请输入图的顶点数和边数：顶点  边" << endl;
	cin >> g.vertexNum >> g.edgeNum;
	cout << "请输入" << g.vertexNum << "个顶点的个数" << endl;
	for (int i = 0; i < g.vertexNum; i++)
	{
		cin >> g.vertex[i];//初始化每个顶点
	}
	//初始化所有边都不存在
	for (int i = 0; i < g.vertexNum; ++i)
	{
		for (int j = 0; j < g.vertexNum; ++j)
		{
			g.edge[i][j] = 0;
		}
	}
	cout << "请输入" << g.edgeNum << "条边，顶点1 顶点2" << endl;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; ++i)
	{
		cin >> v1 >> v2;
		//求用户输入顶点在顶点数组中的位置
		int m = LocalVertex(g, v1);//获取v1在二维数组中的位置
		int n = LocalVertex(g, v2);//获取v2在二维数组中的位置

		//边对应的二维数组赋值
		g.edge[m][n] = 1;
		g.edge[n][m] = 1;
	}
}

//打印图
void PrintGraph(graph& g)
{
	//水平表头
	cout << "\t";
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << g.vertex[i] << "\t";
	}
	for (int i = 0; i < g.vertexNum; ++i)
	{
		cout << endl;
		//垂直
		cout << g.vertex[i] << "\t";
		for (int j = 0; j < g.vertexNum; ++j)
		{
			cout << g.edge[i][j] << "\t";
		}
	}
	cout << endl;
}

//深度优先遍历
void DFS(graph& g)
{
	bool* visited = new bool[g.vertexNum];
	for (int i = 0; i < g.vertexNum; ++i)
	{
		visited[i] = false;
	}
	//从顶点数组中的第一个开始访问
	stack<int>st;//int-顶点数组的下标
	visited[0] = true;
	cout << g.vertex[0] << " ";
	st.push(0);

	while (!st.empty())
	{
		//遍历所有的顶点，找邻接点-栈顶元素对应的邻接点
		for (int i = 0; i < g.vertexNum; ++i)
		{
			//栈顶元素在顶点数组中的位置
			int top = st.top();
			if (!visited[i] && g.edge[top][i] > 0)//遍历每一个节点横向后的所有节点
			{
				//遍历该顶点
				visited[i] = true;
				cout << g.vertex[i] << " ";
				//邻接点压栈
				st.push(i);
			}
		}
		//栈顶的顶点与顶点组成的边全部判断一遍
		st.pop();
	}
	delete[] visited;
} 

//广度优先遍历
void BFS(graph& g)
{
	//保证顶点不被重复遍历
	bool* visited = new bool[g.vertexNum];
	//初始化为所有顶点都没有被访问
	for (int i = 0; i < g.vertexNum; i++)
	{
		visited[i] = false;
	}
	//找一个顶点开始访问
	queue<int> q;
	visited[0] = true;
	cout << g.vertex[0] << " ";
	q.push(0);
	//如果队列为空，遍历完成
	while (!q.empty())
	{
		//对头顶点的下标值取出
		int front = q.front();
		//遍历所有顶点，找出邻接点
		for (int i = 0; i < g.vertexNum; i++)
		{
			if (!visited[i] && g.edge[front][i] > 0)
			{
				visited[i] = true;
				cout << g.vertex[i] << " ";
				q.push(i);
			}
		}
		q.pop();//所有邻接点都访问完成，出队列
	}
	delete[] visited;
}

void test01()
{
	graph graph;
	CreateGraph(graph);
	PrintGraph(graph);
}
//深度优先搜索
void test02()
{
	graph graph;
	CreateGraph(graph);
	PrintGraph(graph);

	DFS(graph);
}

//广度优先搜索
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