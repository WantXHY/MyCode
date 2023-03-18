#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//最大的顶点数
#define MaxVertex 50
//存放顶点名称的数组
typedef char VertexInfo[9];

//图的结构
struct Graph
{
	//顶点数组
	VertexInfo Vertex[MaxVertex];
	//边的二维数组
	int edge[MaxVertex][MaxVertex];
	//顶点个数
	int VertexNum;
	//边的个数
	int edgeNum;
};

//求用户输入的顶点在顶点数组中的位置
int LocalVertex(Graph& g,VertexInfo v)
{
	//遍历数组
	for (int i = 0; i < g.VertexNum; i++)
	{
		if (strcmp(v, g.Vertex[i]) == 0)
		{
			return i;
		}
	}
	return -1;
}

//创建图
void CreateGraph(Graph& g)
{
	cout << "请输入图的顶点数和边数：顶点  边" << endl;
	cin >> g.VertexNum >> g.edgeNum;
	cout << "请输入" << g.VertexNum << "个顶点的个数" << endl;
	//初始化顶点
	for (int i = 0; i < g.VertexNum; i++)
	{
		cin >> g.Vertex[i];
	}
	//初始化边
	for (int i = 0; i < g.VertexNum; i++)
	{
		for (int j = 0; j < g.VertexNum; j++)
		{
			g.edge[i][j] = INT_MAX;
		}
	}
	cout << "请输入" << g.edgeNum << "条边，顶点1，顶点2,权重" << endl;
	int w;
	VertexInfo v1, v2;
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2 >> w;
		//求用户输入的顶点在顶点数组中的位置
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);

		//边对应的二维数组赋值
		g.edge[m][n] = w;
		g.edge[n][m] = w;
	}
}

//打印图
void PrintGraph(Graph& g)
{
	//水平表头
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

//最短路径
//迪杰斯特拉算法
//path哪一顶点到当前点的距离最近
void dijkstraPath(Graph& g, int* path, int* dist, int v0)
{
	int min = 0;
	int pos = v0;//访问的起始顶点
	//定义一个数组，标记顶点是否已经被访问
	bool* visited = new bool[g.VertexNum];
	//初始化
	for (int i = 0; i < g.VertexNum; i++)
	{
		visited[i] = false;//顶点未访问
		if (i != v0)//排除顶点到出发点的计算
		{
			//初始化所有点的最近邻接点都是v0点
			path[i] = v0;
			//v0到各个顶点的权重
			dist[i] = g.edge[v0][i];
			cout << g.Vertex[0] << "到" << g.Vertex[i]
				<< "距离：dist[" << i << "]=" << dist[i] << endl;
		}
		else
		{
			// path[]数组 - 到当前点的最近的邻接点
			// dist[]数组 - 从出发点到各个点的最短距离
			// i == v0即点到点，没有任何意义, 不存在路径
			path[i] = -1;
			dist[i] = INT_MAX;//无效路径
		}
	}
	visited[v0] = true;//将v0标记为已访问
	for (int i = 0; i < g.VertexNum; i++)
	{
		min = INT_MAX;
		for (int j = 0; j < g.VertexNum; j++)
		{
			// 没有被访问, 并且找到了拥有更小权值的边
			if (!visited[j] && min > dist[j])
			{
				min = dist[j];
				pos = j;
				cout << "++顶点更新：pos=" << pos
					<< "顶点为" << g.Vertex[pos] << endl;
			}
		}
		//pos位置的顶点标记为已访问
		visited[pos] = true;
		
		for (int j = 0; j < g.VertexNum; j++)
		{
			// g.edge[pos][j] < INT_MAX - 判断pos->j这条边是存在的
			if (!visited[j] && dist[pos] + g.edge[pos][i] < dist[j] && g.edge[pos][j] < INT_MAX)
			{
				// 更新最短距离
				//例如 将j看成E  pos看成B，求出A到E最短路径
				dist[j] = dist[pos] + g.edge[pos][j];
				//更新路径, 到顶点j最近的顶点是pos
				path[j] = pos;
				cout << "=== 更新最短距离: dist[" << j
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
		//寻找下一个顶点
		temp = path[temp];
	}
	st.push(v0);

	//打印路径
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

	cout << "迪杰斯特拉算法" << endl;
	// path数组 - 到当前点的最近的邻接点
	int path[50];
	// dist[] 数组 - 从出发点到各个点的最短距离
	int dist[50];
	// 出发点
	int v0 = 0;
	dijkstraPath(graph, path, dist, v0);
	for (int i = 1; i < graph.VertexNum; ++i)
	{
		cout << "路径: ";
		showPath(graph, path, v0, i);
		cout << "路径长度: " << dist[i] << endl;
	}
	cout << "Keyboard not found, press F1 to continue..." << endl;
}

int main()
{
	test01();

	system("pause");
	return 0;
}