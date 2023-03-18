#include <iostream>
#include <stack>
#include <queue>
using namespace std;

#if 1
#define MaxVertex 100
#endif

//邻接点的结构体
struct edgeNode
{
	//当前顶点在顶点数组中的位置
	int position;
	//指向后续节点的指针
	struct edgeNode* next; 
	//节点相关信息,权值
	int weight;
};
//顶点数组的结构体
struct Vertex
{
	//顶点名字
	char name[9];
	//指向邻接点结构体指针
	struct edgeNode* first;
};

//邻接表图结构体
struct GraphList
{
	//顶点数组
	Vertex head[MaxVertex];
	//顶点个数
	int VertexNum;
	//边的个数
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

//创建一个图
void CreateGraph(GraphList& g)
{
	cout << "请输入图的顶点数和边数：顶点  边" << endl;
	cin >> g.VertexNum >> g.edgeNum;
	cout << "请输入" << g.VertexNum << "顶点的值" << endl;
	for (int i = 0; i < g.VertexNum; i++)
	{
		cin >> g.head[i].name;
		g.head[i].first = NULL;
	}
	cout << "请输入" << g.edgeNum << "条边，顶点1  顶点2" << endl;
	char v1[9], v2[9];
	for (int i = 0; i < g.edgeNum; i++)
	{
		cin >> v1 >> v2;
		//以M为头节点的链表，n是m的邻接点
		//求用户输入的顶点在顶点数组中的位置
		int m = LocalVertex(g, v1);
		int n = LocalVertex(g, v2);
		//链表中添加邻接点
		edgeNode* pNew = new edgeNode;
		pNew->position = n;//当前节点在顶点数组中的位置
		//pNew添加到头节点数组中的第m个元素，对应的链表中
		//头插法，尾插法需要遍历
		pNew->next = g.head[m].first;
		g.head[m].first = pNew;
#if 1
		//改为 if 0为有向图
		//以N为头节点的链表，m是n的邻接点
		edgeNode* pNew1 = new edgeNode;
		pNew1->position = m;
		pNew1->next = g.head[n].first;
		g.head[n].first = pNew1;

#endif
	}
}

//打印图
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
