
/*

*	最小生成树算法：在一个无向连通加权图中，花费最小的代价将图中所有点连接起来，形成一棵树。 
*	
*	Kruskal算法，不断从图中所有连边中依次挑选权值最小的连边将点串接起来。 

*/ 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int u; //边连接的一个顶点编号
	int v; //边连接另一个顶点编号
	int w; //边的权值
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w < E2.w;
	}
};


/*

*	利用并查集来将图中的点 
*

*/ 
//创建并查集
void MakeSet(vector<int>& uset, int n)
{
	uset.assign(n, 0);
	for (int i = 0; i < n; i++)
		uset[i] = i;
}

//查找当前元素所在集合的代表元，注意是while循环，表示直到找到集合代表元为止，即 uset[i] == i 时 
int FindSet(vector<int>& uset, int u)
{
	int i = u;
	while (uset[i] != i) i = uset[i];             //  uset[i] != i说明该点已经归入其他集合了 
	return i;
}


void Kruskal(const vector<Edge>& edges, int n)
{
	vector<int> uset;
	vector<Edge> SpanTree;
	int Cost = 0, e1, e2;
	MakeSet(uset, n);
	
	for (int i = 0; i < edges.size(); i++) //按权值从小到大的顺序取边
	{
		e1 = FindSet(uset, edges[i].u);
		e2 = FindSet(uset, edges[i].v);
		
		if (e1 != e2) //若当前边连接的两个结点在不同集合中，选取该边并合并这两个集合
		{
			SpanTree.push_back(edges[i]);
			Cost += edges[i].w;
			uset[e1] = e2; //合并当前边连接的两个顶点所在集合
		}
	}
	
	cout << "Result:\n";
	cout << "Cost: " << Cost << endl;
	cout << "Edges:\n";
	for (int j = 0; j < SpanTree.size(); j++)
		cout << SpanTree[j].u << " " << SpanTree[j].v << " " << SpanTree[j].w << endl;
		
	cout << endl;
}
int main()
{

	int n = 5, m = 7;            //定义图，5个顶点，7条连边 
	
	vector<Edge> edges;          //定义边的集合 
	
	edges.assign(m, Edge());           //对边集合初始化 
	
	edges[0].u = 1,edges[0].v = 3,edges[0].w = 2;            //初始化图，定义连边 
	edges[1].u = 1,edges[1].v = 5,edges[1].w = 3; 
	edges[2].u = 1,edges[2].v = 2,edges[2].w = 3; 
	edges[3].u = 3,edges[3].v = 5,edges[3].w = 4; 
	edges[4].u = 2,edges[4].v = 4,edges[4].w = 6; 
	edges[5].u = 2,edges[5].v = 5,edges[5].w = 1; 
	edges[6].u = 3,edges[6].v = 4,edges[6].w = 5; 
	
	sort(edges.begin(), edges.end());       //排序之后，可以以边权值从小到大的顺序选取边
	
	Kruskal(edges, n + 1);

	return 0;
}
